#pragma once
#include "device.h"

class CDummyDevice :
	public CDevice
{
public:
	// ctor
	CDummyDevice(void);
	// dtor
	virtual ~CDummyDevice(void);

	// Returns 1
	virtual int QueryDevicePopulation(void);
	// Returns "DummyDev"
	virtual bool QuerySerialNumber(int DeviceIndex, char* SerialNumber);

	// Null function
	virtual HRESULT Open(char* SerialNumber);
	// Null function
	virtual HRESULT Close(void);
	// Null function
	virtual HRESULT ClearAll(void);

	// Returns "123456789"
	virtual HRESULT GetInt32(long* pInt32);
	// Returns "0.123456789"
	virtual HRESULT GetUniform(double* pUniform);
	// Returns "1.23456789"
	virtual HRESULT GetNormal(double* pNormal);
	// Returns a block with repeating "012345678901234567890..." (hex)
	virtual HRESULT GetBytes(void* pOutBuffer, unsigned long Length);

protected:
	// Buffer for block operations.
	char* pBuffer;
};
