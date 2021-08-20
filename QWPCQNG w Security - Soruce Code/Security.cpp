#include "StdAfx.h"
#include "security.h"

CSecurity::CSecurity(void)
{
}

CSecurity::~CSecurity(void)
{
}

int CSecurity::CheckDate(void)
{
	// Check if registry key exists
	HKEY RegKey;
	BOOL RegKeyExists = (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\QWC\\PCQNG", NULL, KEY_ALL_ACCESS, &RegKey)==ERROR_SUCCESS);
	RegCloseKey(RegKey);

	// Encodes seconds of QWPCQNG.dll in QWPCQNG.lic to match rest of date
	HANDLE hFile;
	FILETIME ftCreate;
	SYSTEMTIME stCreate, stCurrent;

	OFSTRUCT OfStruct;
	char sPath[500];
	GetModuleFileName(GetModuleHandle("QWPCQNG.dll"), sPath, 500);
	hFile = (HANDLE)OpenFile(sPath, &OfStruct, OF_READ);
    int errrr = GetLastError();

	GetFileTime(hFile, &ftCreate, NULL, NULL);
	FileTimeToSystemTime(&ftCreate, &stCreate);
    stCreate.wSecond = (stCreate.wYear+stCreate.wMonth+stCreate.wDay) % 60;
    SystemTimeToFileTime(&stCreate, &ftCreate);

    CloseHandle(hFile);
    
    int LicPointer = strlen(sPath) - 3;
    strcpy(&sPath[LicPointer], "lic");
    hFile = (HANDLE)OpenFile(sPath, &OfStruct, OF_CREATE);

	// If this is the first time running, save encoded changes
	if (!RegKeyExists)
	{
		SetFileTime(hFile, &ftCreate, NULL, NULL);
		WrittenSeconds = (int)stCreate.wSecond;
	}

	GetFileTime(hFile, &ftCreate, NULL, NULL);
	FileTimeToSystemTime(&ftCreate, &stCreate);
    int WrittenSeconds = (int)stCreate.wSecond;

    CloseHandle(hFile);

	// If consistent, check expiration
	int DaysLeft = 0;
	if ((WrittenSeconds-(int)stCreate.wSecond)==0)
	{
		GetSystemTime(&stCurrent);
		DaysLeft = 11 - 30*(stCurrent.wMonth-stCreate.wMonth) + (stCurrent.wDay-stCreate.wDay);
		if ((DaysLeft<0) || (DaysLeft>11))
			DaysLeft = 0;
	}

	return DaysLeft;
}

int CSecurity::CheckLicense(void)
{
	// Open License in Registry
	HKEY RegKey;
	BOOL RegKeyExists = (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\QWC\\PCQNG\\License", NULL, KEY_ALL_ACCESS, &RegKey)==ERROR_SUCCESS);

	// Read Licensee (usually an email)
	char sLicensee[80];
	DWORD Type = REG_SZ;
	DWORD Length = 80;
	RegQueryValueEx(RegKey, "Licensee", NULL, &Type, (LPBYTE)sLicensee, &Length);

	// Read Product Key
	char sProductKey[25];
	Length = 25;
	RegQueryValueEx(RegKey, "ProductKey", NULL, &Type, (LPBYTE)sProductKey, &Length);

	RegCloseKey(RegKey);

	// Find 8 digit encrypted code in license
	char sNumberSet[11] = "0123456789";
	int Pos = 0;
	for (int i=0; i<3; i++)
	{
		Pos = strcspn(sProductKey, sNumberSet);
		strcpy(sProductKey, &sProductKey[Pos-1]);
	}
	if (strlen(sProductKey)>=8)
		sProductKey[8] = NULL;

	char* pTermChar;
	DWORD ProductRegCode = strtoul(sProductKey, &pTermChar, 10);

	// Decode Licensee
	// Lowercase and trim whitespace
	strcpy(sLicensee, strlwr(sLicensee));
	while ((strlen(sLicensee)>0) && (sLicensee[0]==' '))
		strcpy(sLicensee, &sLicensee[1]);
	while ((strlen(sLicensee)>0) && (sLicensee[strlen(sLicensee)-1]==' '))
		sLicensee[strlen(sLicensee)-1] = ' ';

	DWORD ProductDecodeCode = 1;
	for (i=0; i<strlen(sLicensee); i++)
	{
		ProductDecodeCode *= sLicensee[i];
		ProductDecodeCode %= 99999989;
	}

	ProductDecodeCode += 13117532;
	ProductDecodeCode %= 99999989;

	return (int)(ProductDecodeCode-ProductRegCode);
}
