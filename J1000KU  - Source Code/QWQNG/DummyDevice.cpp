#include "StdAfx.h"
#include "dummydevice.h"

CDummyDevice::CDummyDevice(void)
: pBuffer(NULL)
{
	// buffer is 8K + 12 bytes long
	pBuffer = new char[8204];

	// fill buffer with "0123456789012345..." hex
	int PNTER = 0;
	while (PNTER<8200)
	{
		for (BYTE i=0; i<5; i++)
		{
			pBuffer[PNTER] = ((i*2)<<4) || ((i*2+1));
		}
		PNTER += 10;
	}
}

CDummyDevice::~CDummyDevice(void)
{
	// release buffer from mem
	if (pBuffer != NULL)
	{
		delete pBuffer;
		pBuffer = NULL;
	}
}


// Null Function
HRESULT CDummyDevice::Open(char* SerialNumber)
{
	return QNG_S_OK;
}


// Null function
HRESULT CDummyDevice::Close(void)
{
	return QNG_S_OK;
}


// Returns 1
int CDummyDevice::QueryDevicePopulation(void)
{
	return 1;
}


// Returns "DummyDev"
bool CDummyDevice::QuerySerialNumber(int DeviceIndex, char* SerialNumber)
{
	strcpy(SerialNumber, "DummyDev");
	return true;
}


// Null function
HRESULT CDummyDevice::ClearAll(void)
{
	return QNG_S_OK;
}


// Returns "01234567890123..." (hex)
HRESULT CDummyDevice::GetBytes(void* pOutBuffer, unsigned long Length)
{
	memcpy(pOutBuffer, pBuffer, Length);
	return QNG_S_OK;
}


// Returns "123456789"
HRESULT CDummyDevice::GetInt32(long* pInt32)
{
	*pInt32 = 123456789;
	return QNG_S_OK;
}


// Returns "0.123456789"
HRESULT CDummyDevice::GetUniform(double* pUniform)
{
	*pUniform = 0.123456789;
	return QNG_S_OK;
}


// Returns "1.23456789"
HRESULT CDummyDevice::GetNormal(double* pNormal)
{
	*pNormal = 1.23456789;
	return QNG_S_OK;
}