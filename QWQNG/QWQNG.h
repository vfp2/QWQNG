

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for QWQNG.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __QWQNG_h__
#define __QWQNG_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IQNG_FWD_DEFINED__
#define __IQNG_FWD_DEFINED__
typedef interface IQNG IQNG;

#endif 	/* __IQNG_FWD_DEFINED__ */


#ifndef __QNG_FWD_DEFINED__
#define __QNG_FWD_DEFINED__

#ifdef __cplusplus
typedef class QNG QNG;
#else
typedef struct QNG QNG;
#endif /* __cplusplus */

#endif 	/* __QNG_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IQNG_INTERFACE_DEFINED__
#define __IQNG_INTERFACE_DEFINED__

/* interface IQNG */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IQNG;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("49747D38-E3ED-4CA8-BD48-F283D0B468FB")
    IQNG : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RandInt32( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RandUniform( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RandNormal( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RandBytes( 
            /* [in] */ LONG Length,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IQNGVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IQNG * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IQNG * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IQNG * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IQNG * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IQNG * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IQNG * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IQNG * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RandInt32 )( 
            IQNG * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RandUniform )( 
            IQNG * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RandNormal )( 
            IQNG * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RandBytes )( 
            IQNG * This,
            /* [in] */ LONG Length,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IQNG * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IQNG * This);
        
        END_INTERFACE
    } IQNGVtbl;

    interface IQNG
    {
        CONST_VTBL struct IQNGVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IQNG_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IQNG_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IQNG_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IQNG_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IQNG_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IQNG_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IQNG_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IQNG_get_RandInt32(This,pVal)	\
    ( (This)->lpVtbl -> get_RandInt32(This,pVal) ) 

#define IQNG_get_RandUniform(This,pVal)	\
    ( (This)->lpVtbl -> get_RandUniform(This,pVal) ) 

#define IQNG_get_RandNormal(This,pVal)	\
    ( (This)->lpVtbl -> get_RandNormal(This,pVal) ) 

#define IQNG_get_RandBytes(This,Length,pVal)	\
    ( (This)->lpVtbl -> get_RandBytes(This,Length,pVal) ) 

#define IQNG_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IQNG_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IQNG_INTERFACE_DEFINED__ */



#ifndef __QWQNG_LIBRARY_DEFINED__
#define __QWQNG_LIBRARY_DEFINED__

/* library QWQNG */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_QWQNG;

EXTERN_C const CLSID CLSID_QNG;

#ifdef __cplusplus

class DECLSPEC_UUID("D7A1BFCF-9A30-45AF-A5E4-2CAF0A344938")
QNG;
#endif
#endif /* __QWQNG_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


