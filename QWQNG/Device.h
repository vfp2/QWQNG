#pragma once

#pragma once

#include "FTD2XX.h"

class CDevice
{
public:
	// ctor
	CDevice(void);
	// dtor
	virtual ~CDevice(void);

	// Returns number of devices connected
	virtual int QueryDevicePopulation(void);
	// Returns the SerialNumber of the corresponding DeviceIndex
	virtual bool QuerySerialNumber(int DeviceIndex, char* SerialNumber);

	// Opens the hardware by serial number string
	virtual HRESULT Open(char* SerialNumber);
	// Closes an opened device
	virtual HRESULT Close(void);
	// Clears all buffers - provides "fresh" data
	virtual HRESULT ClearAll(void);

	// Returns a 32 bit integer
	virtual HRESULT GetInt32(long* pInt32);
	// Returns a uniform number of (0, 1]
	virtual HRESULT GetUniform(double* pUniform);
	// Returns a normal number from the buffer (generated in pairs)
	virtual HRESULT GetNormal(double* pNormal);
	// Returns a block of bytes from the hardware
	virtual HRESULT GetBytes(void* pOutBuffer, unsigned long Length);

protected:
	// FTDI handle to hardware device
	FT_HANDLE deviceHandle;
	// Keeps the serial number of an opened device
	char* serialNumber;

	// Handle to the run thread
	HANDLE handleThreadRun;
	// Runs in a thread to read data from device
	static unsigned int _stdcall Run(void* pObject);
	// Handle to manual-reset event to ask the run thread to stop
	HANDLE eventRequestStopRun;
	// Handle to auto-reset event to show that bytes available
	HANDLE eventNewBytesAvailable;
	// Run thread identifier
	unsigned int idThreadRun;

	// Pointer of reading data into the buffer from the device
	int bufferInPointer;
	// Pointer for reading data out of raw data buffer
	int bufferOutPointer;
	// Buffer, feed from device - out to client
	char* pBuffer;
	// Bytes available for client
	int bytesInBuffer;

	// Second normal number produced by GetNormal property
	double normalConjugate;
	// Indicates if two new normal numbers need to be calculated, or if the normalConjugate should be read
	bool needNewNormalCalc;	
	// Half of LSB (49th bit) in 48 bit encoded uniform number for normal calc
	double halfOfLSB;

	// Failure status of device
	HRESULT generalStatus;

private:
	// Critical section syncronization object
	CRITICAL_SECTION syncCritical;
	// Syncronizes ClearAll method
	CRITICAL_SECTION syncCritReset;
public:
	// // Use to set a device error status
	void SetStatus(HRESULT Status);
};