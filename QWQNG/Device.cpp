#include "StdAfx.h"
#include "device.h"
#include "math.h"

// ctor
CDevice::CDevice(void)
: idThreadRun(0)
, bufferInPointer(0)
, bufferOutPointer(0)
, bytesInBuffer(0)
, serialNumber(NULL)
, pBuffer(NULL)
, normalConjugate(0)
, needNewNormalCalc(true)
{
	// initialize critical section objects
	InitializeCriticalSection(&syncCritical);
	InitializeCriticalSection(&syncCritReset);

	// create a manual-reset, signaled event to ask the run thread to stop
	eventRequestStopRun = CreateEvent(NULL, TRUE, TRUE, NULL);

	// manual-reset, non-signaled event to release a thread waiting for new data
	eventNewBytesAvailable = CreateEvent(NULL, TRUE, FALSE, NULL);

	// buffer is 8K + 12 bytes long
	pBuffer = new char[8204];

	// calc the halfOfLSB
	__int64 BitHalfOfLSB;
	BitHalfOfLSB = 0x3ce0000000000000;
	memcpy(&halfOfLSB, &BitHalfOfLSB, 8);
}

// dtor
CDevice::~CDevice(void)
{
	// make sure device is closed
	Close();

	// release buffer from mem
	if (pBuffer != NULL)
	{
		delete pBuffer;
		pBuffer = NULL;
	}

	// release event resources
	CloseHandle(eventRequestStopRun);

	// release buffer resources
	CloseHandle(eventNewBytesAvailable);

	// free critical section object
	DeleteCriticalSection(&syncCritical);
	DeleteCriticalSection(&syncCritReset);
}

// Opens the hardware by serial number string
HRESULT CDevice::Open(char* SerialNumber)
{
	HRESULT RetVal = QNG_S_OK;

	generalStatus = QNG_S_OK;

	// remember SerialNumber
	serialNumber = new char[strlen(SerialNumber)+1];
	strcpy(serialNumber, SerialNumber);

	// open and create handle to hardware
	if (FT_OpenEx(serialNumber, FT_OPEN_BY_SERIAL_NUMBER, &deviceHandle) != FT_OK)
		RetVal = QNG_E_DEVICE_NOT_OPENED;

	// Flushes receive buffer every 1 ms
	FT_SetLatencyTimer(deviceHandle, 1);

	// Set read/write timeouts to 50 ms
	FT_SetTimeouts(deviceHandle, 50, 50);

	// FT_SetUSBParameters to set usb transfer block size from device to driver
	if (FT_SetUSBParameters(deviceHandle, 320, 320) != FT_OK)
		RetVal = QNG_E_DEVICE_NOT_OPENED;

	// initialize hardware
	FT_Purge(deviceHandle, FT_PURGE_RX | FT_PURGE_TX);	// clear buffers
	BYTE DummyWord;
	DWORD BytesTxd;
	// write out dummy word to physically start device
	FT_Write(deviceHandle, &DummyWord, 1, &BytesTxd);
	// first 4-5 bits produced from device are invalid (always zero)
	// discard first byte
	if (FT_Read(deviceHandle, &DummyWord, 1, &BytesTxd) != FT_OK)
		RetVal = QNG_E_DEVICE_NOT_OPENED;

	// reset thread sync events and start device read thread
	if (RetVal == QNG_S_OK)
	{
		ResetEvent(eventRequestStopRun);
		handleThreadRun = (HANDLE) _beginthreadex(NULL, 0, &Run, this, 0, &idThreadRun);
		if (handleThreadRun==NULL)
			RetVal = QNG_E_DEVICE_NOT_OPENED;
	}

	if (RetVal == QNG_E_DEVICE_NOT_OPENED)
		Close();

	return RetVal;
}


// Closes the hardware device
HRESULT CDevice::Close(void)
{
	HRESULT RetVal = QNG_S_OK;

	// end the thread
	SetEvent(eventRequestStopRun);
	WaitForSingleObject(handleThreadRun, INFINITE);

	// close hardware device
	// check error
	if (FT_Close(deviceHandle) != FT_OK)
		RetVal = QNG_E_GENERAL_FAILURE;

	// delete serialNumber
	if (serialNumber != NULL)
	{
		delete[] serialNumber;
		serialNumber = NULL;
	}

	return RetVal;
}


// Returns number of devices connected
int CDevice::QueryDevicePopulation(void)
{
	DWORD Population;

	if(FT_ListDevices(&Population, NULL, FT_LIST_NUMBER_ONLY) == FT_OK)
		return (int)Population;
	else	// returns -1 if failure
		return -1;
}


// Returns the SerialNumber of the corresponding DeviceIndex
bool CDevice::QuerySerialNumber(int DeviceIndex, char* SerialNumber)
{
	DWORD devIndex = DeviceIndex;
	if(FT_ListDevices((PVOID)devIndex, SerialNumber, FT_LIST_BY_INDEX | FT_OPEN_BY_SERIAL_NUMBER) == FT_OK)
		return true;
	else	// false if this command failed
		return false;
}


// Runs in a thread to read data from device
unsigned int CDevice::Run(void* pObject)
{
	// resolve object instance
	CDevice* pDevice;
	pDevice = (CDevice*) pObject;

	DWORD BytesTxd = 0;

	// loop until stop is requested
	while (WaitForSingleObject(pDevice->eventRequestStopRun, 0) != WAIT_OBJECT_0)
	{
		// make sure ClearAll is sync'd
		EnterCriticalSection(&pDevice->syncCritReset);

		// no more room in buffer, time out, check back every 100ms
		if (pDevice->bytesInBuffer > 7168)
			Sleep(100);
		else
		{
			DWORD BytesNeeded = 1024;
			DWORD HaveBytes = 0;
			int RetryCount = 0;
			// Will try to read up to 10 times for success - with the set timeouts should be about 1/2 second;
			while ((BytesNeeded>0) && (RetryCount<40))
			{
				if (FT_Read(pDevice->deviceHandle, &pDevice->pBuffer[pDevice->bufferInPointer+HaveBytes], BytesNeeded, &BytesTxd) != FT_OK)
				{
					// Workaround for a known bug
					while ((GetLastError()==ERROR_WORKING_SET_QUOTA) && (RetryCount<40))
					{	
						Sleep(500);
						if (FT_Read(pDevice->deviceHandle, &pDevice->pBuffer[pDevice->bufferInPointer+HaveBytes], BytesNeeded, &BytesTxd) != FT_OK)			
							RetryCount++;
						else
							goto SuccessfulRead;
					}

					pDevice->generalStatus = QNG_E_IO_ERROR;	// IO ERROR
				}
SuccessfulRead:
				BytesNeeded -= BytesTxd;
				HaveBytes += BytesTxd;
				RetryCount++;
			}

			if (HaveBytes==1024)
			{
				EnterCriticalSection(&pDevice->syncCritical);
					// update bufferInPointer
					pDevice->bufferInPointer += 1024;
					pDevice->bufferInPointer %= 8192;

					// a client can read data from the buffer at variable lengths
					// the max length of an output from the buffer is 12 bytes
					// to avoid the wrap around problem, 12 bytes are copied past the 8k buffer boundry
					// these are the same 12 bytes that are at the beginning of the buffer on a wrap around
					// so a client does not need worry about being at a buffer boundry, since the
					// wrap around is calculated with the mod of 8k, reading will corectly continue
					if (pDevice->bufferInPointer == 1024)
						memcpy(&pDevice->pBuffer[8192], &pDevice->pBuffer[0], 12);

					// update buffer status
					pDevice->bytesInBuffer += 1024;

					// fire new Bytes available event, pulse all waiting threads
					PulseEvent(pDevice->eventNewBytesAvailable);
				LeaveCriticalSection(&pDevice->syncCritical);
			}
			else
			{
				// timeout occured
				pDevice->generalStatus = QNG_E_IO_TIMEOUT;
			}
		}
		// make sure ClearAll is sync'd
		LeaveCriticalSection(&pDevice->syncCritReset);
	}
	
	// dispose of thread;
	CloseHandle(pDevice->handleThreadRun);
	_endthreadex(0);

	// should not ever really get here because of _endthreadex
	return 0;
}


// Returns array of bytes from buffer
HRESULT CDevice::GetBytes(void* pOutBuffer, unsigned long Length)
{
	// wait for bytes needed
	while ((bytesInBuffer<(int)Length) && (generalStatus==QNG_S_OK))
		WaitForSingleObject(eventNewBytesAvailable, INFINITE);

	// check to see if buffer wrap around will occur
	// remember we have copied the first 12 "wrap-around" bytes to the end of the buffer
	if ((bufferOutPointer+Length) < 8204)
	{
		// copy without wrap-around
		memcpy(pOutBuffer, &pBuffer[bufferOutPointer], Length);
	}
	else
	{
		// copy with wrap around
		memcpy(pOutBuffer, &pBuffer[bufferOutPointer], 8192-bufferOutPointer);
		memcpy(&((PBYTE)pOutBuffer)[8192-bufferOutPointer], &pBuffer[0], Length - (8192-bufferOutPointer));
	}

	// update OutPointer
	bufferOutPointer += Length;
	bufferOutPointer %= 8192;

	EnterCriticalSection(&syncCritical);
		// update buffer status
		bytesInBuffer -= Length;
	LeaveCriticalSection(&syncCritical);

	return generalStatus;
}


// Returns an integer from the buffer
HRESULT CDevice::GetInt32(long* pInt32)
{
	// infinite, should have a time-out!!!
	if ((bytesInBuffer<4) && (generalStatus==QNG_S_OK))
		WaitForSingleObject(eventNewBytesAvailable, INFINITE);

	// copy 4 bytes over
	*pInt32 = *((long*)&pBuffer[bufferOutPointer]);

	// update OutPointer
	bufferOutPointer += 4;
	bufferOutPointer %= 8192;

	EnterCriticalSection(&syncCritical);
		// update buffer status
		bytesInBuffer -= 4;
	LeaveCriticalSection(&syncCritical);

	return generalStatus;
}


// Returns a uniform number of (0, 1]
HRESULT CDevice::GetUniform(double* pUniform)
{
	// infinite, should have a time-out!!!
	if ((bytesInBuffer<6) && (generalStatus==QNG_S_OK))
		WaitForSingleObject(eventNewBytesAvailable, INFINITE);

	// copy 6 bytes into mantissa
	__int64 UInt64;
	UInt64 = *((__int64*)&pBuffer[bufferOutPointer]);
	UInt64 &= 0x0000ffffffffffff;
	*pUniform = (double)UInt64;
	*pUniform /= 281474976710656.;

	// update OutPointer
	bufferOutPointer += 6;
	bufferOutPointer %= 8192;

	EnterCriticalSection(&syncCritical);
		// update buffer status
		bytesInBuffer -= 6;
	LeaveCriticalSection(&syncCritical);

	return generalStatus;
}


// Returns a normal number from the buffer (generated in pairs)
HRESULT CDevice::GetNormal(double* pNormal)
{
	if (needNewNormalCalc)
	{
		// infinite, should have a time-out!!!
		if ((bytesInBuffer<12) && (generalStatus==QNG_S_OK))
			WaitForSingleObject(eventNewBytesAvailable, INFINITE);

		// uniform numbers to go into equation
		double Uniform1;
		double Uniform2;

		// make Uniform1
		__int64 UInt64;
		UInt64 = *((__int64*)&pBuffer[bufferOutPointer]);
		UInt64 &= 0x0000ffffffffffff;
		Uniform1 = (double)UInt64;
		Uniform1 /= 281474976710656.;
		Uniform1 += halfOfLSB;

		// make Uniform2
		UInt64 = *((__int64*)&pBuffer[bufferOutPointer+6]);
		UInt64 &= 0x0000ffffffffffff;
		Uniform2 = (double)UInt64;
		Uniform2 /= 281474976710656.;
		Uniform2 += halfOfLSB;

		// n1 = cos(2PI * u2) * sqrt(-2 * ln(u1)) 
		// n1 = sin(2PI * u2) * sqrt(-2 * ln(u1))
		double LogPart = sqrt(-2. * log(Uniform1));
		*pNormal = cos(6.28318530717958647692528676656 * Uniform2) * LogPart;
		normalConjugate = sin(6.28318530717958647692528676656 * Uniform2) * LogPart;

		// update OutPointer
		bufferOutPointer += 12;
		bufferOutPointer %= 8192;

		EnterCriticalSection(&syncCritical);
			// update buffer status
			bytesInBuffer -= 12;
		LeaveCriticalSection(&syncCritical);

		needNewNormalCalc = false;
	}
	else
	{
		*pNormal = normalConjugate;

		needNewNormalCalc = true;
	}

	return generalStatus;
}


// Clears all buffers - provides "fresh" data
HRESULT CDevice::ClearAll(void)
{
	// make sure ClearAll is sync'd
	EnterCriticalSection(&syncCritReset);

	// stop device from producing data, clear buffer
	DWORD BytesLeftInBuffer = 0;
	do 
	{
		FT_Purge(deviceHandle, FT_PURGE_RX);
		FT_GetQueueStatus(deviceHandle, &BytesLeftInBuffer);
	} while ((BytesLeftInBuffer!=0) && (generalStatus==QNG_S_OK));

	// now that the buffer is empty (with exception of what might have been on the USB bus)
	BYTE DummyWord;
	DWORD BytesTxd;
	// write out dummy word to physically re-start device
	FT_Write(deviceHandle, &DummyWord, 1, &BytesTxd);

	// first 4-5 bits produced from device are invalid (always zero)
	// discard first byte
	FT_Read(deviceHandle, &DummyWord, 1, &BytesTxd);

	// clear buffer in control
	bufferInPointer = 0;
	bufferOutPointer = 0;
	needNewNormalCalc = true;

	// this will cause read cycle to fire up again
	bytesInBuffer = 0;

	// make sure ClearAll is sync'd
	LeaveCriticalSection(&syncCritReset);

	return generalStatus;
}


// // Use to set a device error status
void CDevice::SetStatus(HRESULT Status)
{
	generalStatus = Status;
}