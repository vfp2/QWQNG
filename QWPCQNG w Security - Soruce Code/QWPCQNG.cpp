//////////////////////////////////////////////////////////////////////////////
//
// Copyright © 2001-2003 The Quantum World Corporation. All rights reserved.
//

// Version History:
// 2003.07.01    PAW    Creation

// QWPCQNG.cpp : Implementation of DLL Exports.

#include "stdafx.h"
#include "resource.h"
#include "QWPCQNG.h"
#include "dlldatax.h"

class CQWPCQNGModule : public CAtlDllModuleT< CQWPCQNGModule >
{
public :
	DECLARE_LIBID(LIBID_QWPCQNGLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_QWPCQNG, "{8BFC3C02-E4C0-4431-B561-AD7CCC60EDCF}")
};

CQWPCQNGModule _AtlModule;


// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
#ifdef _MERGE_PROXYSTUB
    if (!PrxDllMain(hInstance, dwReason, lpReserved))
        return FALSE;
#endif
	hInstance;
    return _AtlModule.DllMain(dwReason, lpReserved); 
}


// Used to determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow(void)
{
#ifdef _MERGE_PROXYSTUB
    HRESULT hr = PrxDllCanUnloadNow();
    if (FAILED(hr))
        return hr;
#endif
    return _AtlModule.DllCanUnloadNow();
}


// Returns a class factory to create an object of the requested type
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
#ifdef _MERGE_PROXYSTUB
    if (PrxDllGetClassObject(rclsid, riid, ppv) == S_OK)
        return S_OK;
#endif
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}

// Create Secutiy date code
void CreateSecurityDate()
{
	// Check if control has been formally registered
	HKEY RegKey;
	BOOL RegKeyExists = (RegOpenKeyEx(HKEY_CLASSES_ROOT, "CLSID\\{59DA5E62-69A4-4505-A9D0-CAEE53C49E07}", NULL, KEY_ALL_ACCESS, &RegKey)==ERROR_SUCCESS);
	RegCloseKey(RegKey);

	// Check if trying to cheat by re-registering control
	if (!RegKeyExists)
	{
		RegKeyExists = (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\QWC\\PCQNG", NULL, KEY_ALL_ACCESS, &RegKey)==ERROR_SUCCESS);
		RegCloseKey(RegKey);
	}

	// Not registered yet? Then create security codes.
	if (!RegKeyExists)
	{
		// Encodes seconds of QWPCQNG.dll creation to match rest of date
		HANDLE hFile;
		FILETIME ftCreate;
		SYSTEMTIME stCreate, stCurrent;

		OFSTRUCT OfStruct;
		char sPath[500];
		GetModuleFileName(GetModuleHandle("QWPCQNG.dll"), sPath, 500);
		hFile = (HANDLE)OpenFile(sPath, &OfStruct, OF_READ);
		DWORD errr = GetLastError();

		// Fetch file creation time of QWPCQNG.dll and current system time
		GetFileTime(hFile, &ftCreate, NULL, NULL);
		FileTimeToSystemTime(&ftCreate, &stCreate);
		GetSystemTime(&stCurrent);

		// Add year, month, day, seconds of times together, then mod by 60 - this is the security code
		stCreate.wSecond = (stCreate.wYear+stCreate.wMonth+stCreate.wDay+stCreate.wSecond
						   +stCurrent.wYear+stCurrent.wMonth+stCurrent.wDay) % 60;	// no seconds here!
	
		// This is the time to save in registry with encoded seconds
		SystemTimeToFileTime(&stCreate, &ftCreate);

		// Open License in Registry
		RegCreateKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\QWC\\PCQNG\\License", NULL, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &RegKey, NULL);

		// Set Licensee to "Evalutation
		char* sLicensee ="Evaluation";
		DWORD Type = REG_SZ;
		DWORD Length = 11;
		RegSetValueEx(RegKey, "Licensee", NULL, Type, (LPBYTE)sLicensee, Length);

		// Set Product Key to time code
		Type = REG_QWORD;
		unsigned __int64 Date64 = ftCreate.dwHighDateTime;
		Date64 <<= 32;
		Date64 += ftCreate.dwLowDateTime;
		char sProductKey[25];
		Length = 8;
		RegSetValueEx(RegKey, "ProductKey", NULL, Type, (LPBYTE)&Date64, Length);

		RegCloseKey(RegKey);
		CloseHandle(hFile);
	}
}

// DllRegisterServer - Adds entries to the system registry
STDAPI DllRegisterServer(void)
{
	// Security enhancement here
	CreateSecurityDate();

    // registers object, typelib and all interfaces in typelib
    HRESULT hr = _AtlModule.DllRegisterServer();
#ifdef _MERGE_PROXYSTUB
    if (FAILED(hr))
        return hr;
    hr = PrxDllRegisterServer();
#endif
	return hr;
}


// DllUnregisterServer - Removes entries from the system registry
STDAPI DllUnregisterServer(void)
{
	// Remove security settings

	HRESULT hr = _AtlModule.DllUnregisterServer();
#ifdef _MERGE_PROXYSTUB
    if (FAILED(hr))
        return hr;
    hr = PrxDllRegisterServer();
    if (FAILED(hr))
        return hr;
    hr = PrxDllUnregisterServer();
#endif
	return hr;
}
