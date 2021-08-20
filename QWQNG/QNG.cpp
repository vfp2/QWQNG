// QNG.cpp : Implementation of CQNG
#include "stdafx.h"
#include "QNG.h"

// CQNG

// Overridden to distinguish between "Design Time" vs "Run Time"
STDMETHODIMP CQNG::SetClientSite(IOleClientSite* pClientSite)
{
	// call original function
	HRESULT RetVal = IOleObjectImpl<CQNG>::SetClientSite(pClientSite);

	BOOL bIsRunMode = TRUE;
	GetAmbientUserMode(bIsRunMode);

	if ((bIsRunMode==TRUE) && (RetVal==S_OK) && (pDevice==NULL))
	{
		// run mode... get a real device
		pDevice = new CDevice;

		// open the next available hardware device, or return error
		// need to fire error if needed or return other than S_OK
		int devicePopulation = pDevice->QueryDevicePopulation();
		char serialNumber[20];
		for (int i=1; i<=devicePopulation; i++)
		{
			if (pDevice->QuerySerialNumber(i-1, serialNumber))
			{
				// make sure SerialNum starts with "QWR..."
				if ((serialNumber[0]=='Q') && (serialNumber[1]=='W') && (serialNumber[2]=='R'))
				{
					if (pDevice->Open(serialNumber) == QNG_S_OK)
					{
						RetVal = S_OK;
						break;
					}
					else
						RetVal = QNG_E_DEVICE_NOT_OPENED;
				}
			}
		}

		if (RetVal == QNG_E_DEVICE_NOT_OPENED)
			pDevice->SetStatus(QNG_E_DEVICE_NOT_OPENED);

		if (devicePopulation<1)
			pDevice->SetStatus(QNG_E_DEVICE_NOT_OPENED);
	}
	else
	{
		// design mode, start dummy hardware device
		if (pDevice==NULL)
			pDevice = new CDummyDevice;
	}

	return RetVal;
}


// Property to return a 32 bit random number
STDMETHODIMP CQNG::get_RandInt32(LONG* pVal)
{
	// read from device
	HRESULT DevResult = pDevice->GetInt32(pVal);

	switch (DevResult)
	{
	case QNG_S_OK:
		return S_OK;
		break;

	case QNG_E_IO_TIMEOUT:
		return Error(_T("QNG I/O request has timed out."), IID_IQNG, QNG_E_IO_TIMEOUT);
		break;

	case QNG_E_IO_ERROR:
		return Error(_T("QNG I/O error."), IID_IQNG, QNG_E_IO_ERROR);
		break;

	case QNG_E_DEVICE_NOT_OPENED:
		return Error(_T("QNG device not found or already in use."), IID_IQNG, QNG_E_DEVICE_NOT_OPENED);
		break;

	default:
		return Error(_T("QNG general error."), IID_IQNG, QNG_E_GENERAL_FAILURE);
	}
}


// Property to return a uniform number [0,1)
STDMETHODIMP CQNG::get_RandUniform(DOUBLE* pVal)
{
	// read from device
	HRESULT DevResult = pDevice->GetUniform(pVal);

	switch (DevResult)
	{
	case QNG_S_OK:
		return S_OK;
		break;

	case QNG_E_IO_TIMEOUT:
		return Error(_T("QNG I/O request has timed out."), IID_IQNG, QNG_E_IO_TIMEOUT);
		break;

	case QNG_E_IO_ERROR:
		return Error(_T("QNG I/O error."), IID_IQNG, QNG_E_IO_ERROR);
		break;

	case QNG_E_DEVICE_NOT_OPENED:
		return Error(_T("QNG device not found or already in use."), IID_IQNG, QNG_E_DEVICE_NOT_OPENED);
		break;

	default:
		return Error(_T("QNG general error."), IID_IQNG, QNG_E_GENERAL_FAILURE);
	}
}


// Property to return a normal number
STDMETHODIMP CQNG::get_RandNormal(DOUBLE* pVal)
{
	HRESULT DevResult = pDevice->GetNormal(pVal);
	switch (DevResult)
	{
	case QNG_S_OK:
		return S_OK;
		break;

	case QNG_E_IO_TIMEOUT:
		return Error(_T("QNG I/O request has timed out."), IID_IQNG, QNG_E_IO_TIMEOUT);
		break;

	case QNG_E_IO_ERROR:
		return Error(_T("QNG I/O error."), IID_IQNG, QNG_E_IO_ERROR);
		break;

	case QNG_E_DEVICE_NOT_OPENED:
		return Error(_T("QNG device not found or already in use."), IID_IQNG, QNG_E_DEVICE_NOT_OPENED);
		break;

	default:
		return Error(_T("QNG general error."), IID_IQNG, QNG_E_GENERAL_FAILURE);
	}
}


// Property to read byte-array
STDMETHODIMP CQNG::get_RandBytes(LONG Length, VARIANT* pVal)
{
	// check if valid Length <= 7168
	if (Length>7168)
		return Error(_T("QNG read array size exceeds 7168 bytes."), IID_IQNG, QNG_E_IO_ARRAY_OVERSIZED);

	// initialize variant as an array of unisigned char/byte
	VariantInit(pVal);
	pVal->vt = VT_ARRAY | VT_UI1;

	// create the SAFEARRAY with Length elements and zero indexed
	SAFEARRAY* pSafeArray;
	SAFEARRAYBOUND SABounds = {Length, 0};
	pSafeArray = SafeArrayCreate(VT_I1, 1, &SABounds);

	// fill safe array with data
	unsigned char* charArray;
	SafeArrayAccessData(pSafeArray, reinterpret_cast<void**>(&charArray));
		HRESULT DevResult = pDevice->GetBytes(charArray, Length);
	SafeArrayUnaccessData(pSafeArray);

	// return array to user
	pVal->parray = pSafeArray;

	switch (DevResult)
	{
	case QNG_S_OK:
		return S_OK;
		break;

	case QNG_E_IO_TIMEOUT:
		return Error(_T("QNG I/O request has timed out."), IID_IQNG, QNG_E_IO_TIMEOUT);
		break;

	case QNG_E_IO_ERROR:
		return Error(_T("QNG I/O error."), IID_IQNG, QNG_E_IO_ERROR);
		break;

	case QNG_E_DEVICE_NOT_OPENED:
		return Error(_T("QNG device not found or already in use."), IID_IQNG, QNG_E_DEVICE_NOT_OPENED);
		break;

	default:
		return Error(_T("QNG general error."), IID_IQNG, QNG_E_GENERAL_FAILURE);
	}
}


// Method to clear all buffers
STDMETHODIMP CQNG::Clear(void)
{
	// clear all buffers in hardware, driver and control
	HRESULT DevResult = pDevice->ClearAll();

	switch (DevResult)
	{
	case QNG_S_OK:
		return S_OK;
		break;

	case QNG_E_IO_TIMEOUT:
		return Error(_T("QNG I/O request has timed out."), IID_IQNG, QNG_E_IO_TIMEOUT);
		break;

	case QNG_E_IO_ERROR:
		return Error(_T("QNG I/O error."), IID_IQNG, QNG_E_IO_ERROR);
		break;

	case QNG_E_DEVICE_NOT_OPENED:
		return Error(_T("QNG device not found or already in use."), IID_IQNG, QNG_E_DEVICE_NOT_OPENED);
		break;

	default:
		return Error(_T("QNG general error."), IID_IQNG, QNG_E_GENERAL_FAILURE);
	}
}

// Method to attempt to restart the hardware
STDMETHODIMP CQNG::Reset(void)
{
	HRESULT RetVal = S_OK;

	BOOL bIsRunMode = TRUE;
	GetAmbientUserMode(bIsRunMode);

	if (bIsRunMode)
	{
		// run mode... get a real device
		if (pDevice!=NULL)
		{
			pDevice->ClearAll();
			pDevice->Close();
			delete pDevice;
		}
		pDevice = new CDevice;

		// open the next available hardware device, or return error
		// need to fire error if needed or return other than S_OK
		int devicePopulation = pDevice->QueryDevicePopulation();
		char serialNumber[20];
		for (int i=1; i<=devicePopulation; i++)
		{
			if (pDevice->QuerySerialNumber(i-1, serialNumber))
			{
				// make sure SerialNum starts with "QWR..."
				if ((serialNumber[0]=='Q') && (serialNumber[1]=='W') && (serialNumber[2]=='R'))
				{
					if (pDevice->Open(serialNumber) == QNG_S_OK)
					{
						RetVal = S_OK;
						break;
					}
					else
						RetVal = QNG_E_DEVICE_NOT_OPENED;
				}
			}
		}

		if ((RetVal == QNG_E_DEVICE_NOT_OPENED) || (devicePopulation<1))
			return Error(_T("QNG device not found or already in use."), IID_IQNG, QNG_E_DEVICE_NOT_OPENED);
	}

	return RetVal;
}
