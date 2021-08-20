// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef STRICT
#define STRICT
#endif

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER				// Allow use of features specific to Windows 95 and Windows NT 4 or later.
#define WINVER 0x0400		// Change this to the appropriate value to target Windows 98 and Windows 2000 or later.
#endif

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows NT 4 or later.
#define _WIN32_WINNT 0x0400	// Change this to the appropriate value to target Windows 2000 or later.
#endif						

#ifndef _WIN32_WINDOWS		// Allow use of features specific to Windows 98 or later.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE			// Allow use of features specific to IE 4.0 or later.
#define _WIN32_IE 0x0400	// Change this to the appropriate value to target IE 5.0 or later.
#endif

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit

// turns off ATL's hiding of some common and often safely ignored warning messages
#define _ATL_ALL_WARNINGS

#include "resource.h"
#include <atlbase.h>
#include <atlcom.h>

// Custom QNG HRESULT messages

//
// MessageId: QNG_S_OK
//
// MessageText:
//
//  QNG device reports success.
//
#define QNG_S_OK					_HRESULT_TYPEDEF_(0x00044400L)

//
// MessageId: QNG_E_GENERALFAILURE
//
// MessageText:
//
//  QNG general error.
//
#define QNG_E_GENERAL_FAILURE		_HRESULT_TYPEDEF_(0x80044401L)

//
// MessageId: QNG_E_IO_ERROR
//
// MessageText:
//
//  QNG I/O error.
//
#define QNG_E_IO_ERROR				_HRESULT_TYPEDEF_(0x80044402L)

//
// MessageId: QNG_E_IO_TIMEOUT
//
// MessageText:
//
//  QNG I/O request has timed out.
//
#define QNG_E_IO_TIMEOUT			_HRESULT_TYPEDEF_(0x80044403L)

//
// MessageId: QNG_E_IO_TIMEOUT
//
// MessageText:
//
//  QNG read array size exceeds 7168 bytes.
//
#define QNG_E_IO_ARRAY_OVERSIZED	_HRESULT_TYPEDEF_(0x80044404L)

//
// MessageId: QNG_E_DEVICE_NOT_OPENED
//
// MessageText:
//
//  QNG device not found or already in use.
//
#define QNG_E_DEVICE_NOT_OPENED		_HRESULT_TYPEDEF_(0x8004440AL)


using namespace ATL;