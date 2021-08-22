

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for QWQNG.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_)


#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "QWQNG.h"

#define TYPE_FORMAT_STRING_SIZE   1197                              
#define PROC_FORMAT_STRING_SIZE   211                               
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   1            

typedef struct _QWQNG_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } QWQNG_MIDL_TYPE_FORMAT_STRING;

typedef struct _QWQNG_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } QWQNG_MIDL_PROC_FORMAT_STRING;

typedef struct _QWQNG_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } QWQNG_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const QWQNG_MIDL_TYPE_FORMAT_STRING QWQNG__MIDL_TypeFormatString;
extern const QWQNG_MIDL_PROC_FORMAT_STRING QWQNG__MIDL_ProcFormatString;
extern const QWQNG_MIDL_EXPR_FORMAT_STRING QWQNG__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IQNG_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IQNG_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif
#if !(TARGET_IS_NT60_OR_LATER)
#error You need Windows Vista or later to run this stub because it uses these features:
#error   forced complex structure or array, new range semantics, compiled for Windows Vista.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const QWQNG_MIDL_PROC_FORMAT_STRING QWQNG__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure get_RandInt32 */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x24 ),	/* 36 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 24 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RandUniform */

/* 36 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x2c ),	/* 44 */
/* 50 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 52 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 60 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 62 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 64 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 66 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 68 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RandNormal */

/* 72 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 74 */	NdrFcLong( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x9 ),	/* 9 */
/* 80 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 82 */	NdrFcShort( 0x0 ),	/* 0 */
/* 84 */	NdrFcShort( 0x2c ),	/* 44 */
/* 86 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 88 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 96 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 98 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 100 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 102 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RandBytes */

/* 108 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0xa ),	/* 10 */
/* 116 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 118 */	NdrFcShort( 0x8 ),	/* 8 */
/* 120 */	NdrFcShort( 0x8 ),	/* 8 */
/* 122 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 124 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 126 */	NdrFcShort( 0x1 ),	/* 1 */
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Length */

/* 132 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 134 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 138 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 140 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 142 */	NdrFcShort( 0x4a2 ),	/* Type Offset=1186 */

	/* Return value */

/* 144 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 146 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 148 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clear */

/* 150 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 152 */	NdrFcLong( 0x0 ),	/* 0 */
/* 156 */	NdrFcShort( 0xb ),	/* 11 */
/* 158 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 162 */	NdrFcShort( 0x8 ),	/* 8 */
/* 164 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 166 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 174 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 176 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Reset */

/* 180 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 182 */	NdrFcLong( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0xc ),	/* 12 */
/* 188 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 192 */	NdrFcShort( 0x8 ),	/* 8 */
/* 194 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 196 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 204 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 206 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const QWQNG_MIDL_TYPE_FORMAT_STRING QWQNG__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  4 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  8 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 10 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 12 */	NdrFcShort( 0x496 ),	/* Offset= 1174 (1186) */
/* 14 */	
			0x13, 0x0,	/* FC_OP */
/* 16 */	NdrFcShort( 0x47e ),	/* Offset= 1150 (1166) */
/* 18 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 20 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 22 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 24 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 26 */	0x0 , 
			0x0,		/* 0 */
/* 28 */	NdrFcLong( 0x0 ),	/* 0 */
/* 32 */	NdrFcLong( 0x0 ),	/* 0 */
/* 36 */	NdrFcShort( 0x2 ),	/* Offset= 2 (38) */
/* 38 */	NdrFcShort( 0x10 ),	/* 16 */
/* 40 */	NdrFcShort( 0x2f ),	/* 47 */
/* 42 */	NdrFcLong( 0x14 ),	/* 20 */
/* 46 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 48 */	NdrFcLong( 0x3 ),	/* 3 */
/* 52 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 54 */	NdrFcLong( 0x11 ),	/* 17 */
/* 58 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 60 */	NdrFcLong( 0x2 ),	/* 2 */
/* 64 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 66 */	NdrFcLong( 0x4 ),	/* 4 */
/* 70 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 72 */	NdrFcLong( 0x5 ),	/* 5 */
/* 76 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 78 */	NdrFcLong( 0xb ),	/* 11 */
/* 82 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 84 */	NdrFcLong( 0xa ),	/* 10 */
/* 88 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 90 */	NdrFcLong( 0x6 ),	/* 6 */
/* 94 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (326) */
/* 96 */	NdrFcLong( 0x7 ),	/* 7 */
/* 100 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 102 */	NdrFcLong( 0x8 ),	/* 8 */
/* 106 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (332) */
/* 108 */	NdrFcLong( 0xd ),	/* 13 */
/* 112 */	NdrFcShort( 0x100 ),	/* Offset= 256 (368) */
/* 114 */	NdrFcLong( 0x9 ),	/* 9 */
/* 118 */	NdrFcShort( 0x10c ),	/* Offset= 268 (386) */
/* 120 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 124 */	NdrFcShort( 0x118 ),	/* Offset= 280 (404) */
/* 126 */	NdrFcLong( 0x24 ),	/* 36 */
/* 130 */	NdrFcShort( 0x3c2 ),	/* Offset= 962 (1092) */
/* 132 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 136 */	NdrFcShort( 0x3bc ),	/* Offset= 956 (1092) */
/* 138 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 142 */	NdrFcShort( 0x3ba ),	/* Offset= 954 (1096) */
/* 144 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 148 */	NdrFcShort( 0x3b8 ),	/* Offset= 952 (1100) */
/* 150 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 154 */	NdrFcShort( 0x3b6 ),	/* Offset= 950 (1104) */
/* 156 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 160 */	NdrFcShort( 0x3b4 ),	/* Offset= 948 (1108) */
/* 162 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 166 */	NdrFcShort( 0x3b2 ),	/* Offset= 946 (1112) */
/* 168 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 172 */	NdrFcShort( 0x3b0 ),	/* Offset= 944 (1116) */
/* 174 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 178 */	NdrFcShort( 0x39a ),	/* Offset= 922 (1100) */
/* 180 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 184 */	NdrFcShort( 0x398 ),	/* Offset= 920 (1104) */
/* 186 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 190 */	NdrFcShort( 0x3a2 ),	/* Offset= 930 (1120) */
/* 192 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 196 */	NdrFcShort( 0x398 ),	/* Offset= 920 (1116) */
/* 198 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 202 */	NdrFcShort( 0x39a ),	/* Offset= 922 (1124) */
/* 204 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 208 */	NdrFcShort( 0x398 ),	/* Offset= 920 (1128) */
/* 210 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 214 */	NdrFcShort( 0x396 ),	/* Offset= 918 (1132) */
/* 216 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 220 */	NdrFcShort( 0x394 ),	/* Offset= 916 (1136) */
/* 222 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 226 */	NdrFcShort( 0x392 ),	/* Offset= 914 (1140) */
/* 228 */	NdrFcLong( 0x10 ),	/* 16 */
/* 232 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 234 */	NdrFcLong( 0x12 ),	/* 18 */
/* 238 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 240 */	NdrFcLong( 0x13 ),	/* 19 */
/* 244 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 246 */	NdrFcLong( 0x15 ),	/* 21 */
/* 250 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 252 */	NdrFcLong( 0x16 ),	/* 22 */
/* 256 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 258 */	NdrFcLong( 0x17 ),	/* 23 */
/* 262 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 264 */	NdrFcLong( 0xe ),	/* 14 */
/* 268 */	NdrFcShort( 0x370 ),	/* Offset= 880 (1148) */
/* 270 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 274 */	NdrFcShort( 0x374 ),	/* Offset= 884 (1158) */
/* 276 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 280 */	NdrFcShort( 0x372 ),	/* Offset= 882 (1162) */
/* 282 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 286 */	NdrFcShort( 0x32e ),	/* Offset= 814 (1100) */
/* 288 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 292 */	NdrFcShort( 0x32c ),	/* Offset= 812 (1104) */
/* 294 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 298 */	NdrFcShort( 0x32a ),	/* Offset= 810 (1108) */
/* 300 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 304 */	NdrFcShort( 0x320 ),	/* Offset= 800 (1104) */
/* 306 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 310 */	NdrFcShort( 0x31a ),	/* Offset= 794 (1104) */
/* 312 */	NdrFcLong( 0x0 ),	/* 0 */
/* 316 */	NdrFcShort( 0x0 ),	/* Offset= 0 (316) */
/* 318 */	NdrFcLong( 0x1 ),	/* 1 */
/* 322 */	NdrFcShort( 0x0 ),	/* Offset= 0 (322) */
/* 324 */	NdrFcShort( 0xffff ),	/* Offset= -1 (323) */
/* 326 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 328 */	NdrFcShort( 0x8 ),	/* 8 */
/* 330 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 332 */	
			0x13, 0x0,	/* FC_OP */
/* 334 */	NdrFcShort( 0x18 ),	/* Offset= 24 (358) */
/* 336 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 338 */	NdrFcShort( 0x2 ),	/* 2 */
/* 340 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 342 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 344 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 346 */	0x0 , 
			0x0,		/* 0 */
/* 348 */	NdrFcLong( 0x0 ),	/* 0 */
/* 352 */	NdrFcLong( 0x0 ),	/* 0 */
/* 356 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 358 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 360 */	NdrFcShort( 0x8 ),	/* 8 */
/* 362 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (336) */
/* 364 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 366 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 368 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 370 */	NdrFcLong( 0x0 ),	/* 0 */
/* 374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 378 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 380 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 382 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 384 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 386 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 388 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 396 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 398 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 400 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 402 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 404 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 406 */	NdrFcShort( 0x2 ),	/* Offset= 2 (408) */
/* 408 */	
			0x13, 0x0,	/* FC_OP */
/* 410 */	NdrFcShort( 0x298 ),	/* Offset= 664 (1074) */
/* 412 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 414 */	NdrFcShort( 0x18 ),	/* 24 */
/* 416 */	NdrFcShort( 0xa ),	/* 10 */
/* 418 */	NdrFcLong( 0x8 ),	/* 8 */
/* 422 */	NdrFcShort( 0x64 ),	/* Offset= 100 (522) */
/* 424 */	NdrFcLong( 0xd ),	/* 13 */
/* 428 */	NdrFcShort( 0x9c ),	/* Offset= 156 (584) */
/* 430 */	NdrFcLong( 0x9 ),	/* 9 */
/* 434 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (642) */
/* 436 */	NdrFcLong( 0xc ),	/* 12 */
/* 440 */	NdrFcShort( 0x104 ),	/* Offset= 260 (700) */
/* 442 */	NdrFcLong( 0x24 ),	/* 36 */
/* 446 */	NdrFcShort( 0x174 ),	/* Offset= 372 (818) */
/* 448 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 452 */	NdrFcShort( 0x190 ),	/* Offset= 400 (852) */
/* 454 */	NdrFcLong( 0x10 ),	/* 16 */
/* 458 */	NdrFcShort( 0x1b4 ),	/* Offset= 436 (894) */
/* 460 */	NdrFcLong( 0x2 ),	/* 2 */
/* 464 */	NdrFcShort( 0x1d8 ),	/* Offset= 472 (936) */
/* 466 */	NdrFcLong( 0x3 ),	/* 3 */
/* 470 */	NdrFcShort( 0x1fc ),	/* Offset= 508 (978) */
/* 472 */	NdrFcLong( 0x14 ),	/* 20 */
/* 476 */	NdrFcShort( 0x220 ),	/* Offset= 544 (1020) */
/* 478 */	NdrFcShort( 0xffff ),	/* Offset= -1 (477) */
/* 480 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 482 */	NdrFcShort( 0x4 ),	/* 4 */
/* 484 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 488 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 490 */	0x0 , 
			0x0,		/* 0 */
/* 492 */	NdrFcLong( 0x0 ),	/* 0 */
/* 496 */	NdrFcLong( 0x0 ),	/* 0 */
/* 500 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 502 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 504 */	NdrFcShort( 0x4 ),	/* 4 */
/* 506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 508 */	NdrFcShort( 0x1 ),	/* 1 */
/* 510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 514 */	0x13, 0x0,	/* FC_OP */
/* 516 */	NdrFcShort( 0xff62 ),	/* Offset= -158 (358) */
/* 518 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 520 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 522 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 524 */	NdrFcShort( 0x8 ),	/* 8 */
/* 526 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 528 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 530 */	NdrFcShort( 0x4 ),	/* 4 */
/* 532 */	NdrFcShort( 0x4 ),	/* 4 */
/* 534 */	0x11, 0x0,	/* FC_RP */
/* 536 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (480) */
/* 538 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 540 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 542 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 546 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 550 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 552 */	0x0 , 
			0x0,		/* 0 */
/* 554 */	NdrFcLong( 0x0 ),	/* 0 */
/* 558 */	NdrFcLong( 0x0 ),	/* 0 */
/* 562 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 566 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 568 */	0x0 , 
			0x0,		/* 0 */
/* 570 */	NdrFcLong( 0x0 ),	/* 0 */
/* 574 */	NdrFcLong( 0x0 ),	/* 0 */
/* 578 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 580 */	NdrFcShort( 0xff2c ),	/* Offset= -212 (368) */
/* 582 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 584 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 586 */	NdrFcShort( 0x8 ),	/* 8 */
/* 588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 590 */	NdrFcShort( 0x6 ),	/* Offset= 6 (596) */
/* 592 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 594 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 596 */	
			0x11, 0x0,	/* FC_RP */
/* 598 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (542) */
/* 600 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 604 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 608 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 610 */	0x0 , 
			0x0,		/* 0 */
/* 612 */	NdrFcLong( 0x0 ),	/* 0 */
/* 616 */	NdrFcLong( 0x0 ),	/* 0 */
/* 620 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 624 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 626 */	0x0 , 
			0x0,		/* 0 */
/* 628 */	NdrFcLong( 0x0 ),	/* 0 */
/* 632 */	NdrFcLong( 0x0 ),	/* 0 */
/* 636 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 638 */	NdrFcShort( 0xff04 ),	/* Offset= -252 (386) */
/* 640 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 642 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 644 */	NdrFcShort( 0x8 ),	/* 8 */
/* 646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 648 */	NdrFcShort( 0x6 ),	/* Offset= 6 (654) */
/* 650 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 652 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 654 */	
			0x11, 0x0,	/* FC_RP */
/* 656 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (600) */
/* 658 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 660 */	NdrFcShort( 0x4 ),	/* 4 */
/* 662 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 666 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 668 */	0x0 , 
			0x0,		/* 0 */
/* 670 */	NdrFcLong( 0x0 ),	/* 0 */
/* 674 */	NdrFcLong( 0x0 ),	/* 0 */
/* 678 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 680 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 682 */	NdrFcShort( 0x4 ),	/* 4 */
/* 684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 686 */	NdrFcShort( 0x1 ),	/* 1 */
/* 688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 692 */	0x13, 0x0,	/* FC_OP */
/* 694 */	NdrFcShort( 0x1d8 ),	/* Offset= 472 (1166) */
/* 696 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 698 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 700 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 702 */	NdrFcShort( 0x8 ),	/* 8 */
/* 704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 706 */	NdrFcShort( 0x6 ),	/* Offset= 6 (712) */
/* 708 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 710 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 712 */	
			0x11, 0x0,	/* FC_RP */
/* 714 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (658) */
/* 716 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 718 */	NdrFcLong( 0x2f ),	/* 47 */
/* 722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 726 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 728 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 730 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 732 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 734 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 736 */	NdrFcShort( 0x1 ),	/* 1 */
/* 738 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 740 */	NdrFcShort( 0x4 ),	/* 4 */
/* 742 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 744 */	0x0 , 
			0x0,		/* 0 */
/* 746 */	NdrFcLong( 0x0 ),	/* 0 */
/* 750 */	NdrFcLong( 0x0 ),	/* 0 */
/* 754 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 756 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 758 */	NdrFcShort( 0x10 ),	/* 16 */
/* 760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 762 */	NdrFcShort( 0xa ),	/* Offset= 10 (772) */
/* 764 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 766 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 768 */	NdrFcShort( 0xffcc ),	/* Offset= -52 (716) */
/* 770 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 772 */	
			0x13, 0x20,	/* FC_OP [maybenull_sizeis] */
/* 774 */	NdrFcShort( 0xffd8 ),	/* Offset= -40 (734) */
/* 776 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 778 */	NdrFcShort( 0x4 ),	/* 4 */
/* 780 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 784 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 786 */	0x0 , 
			0x0,		/* 0 */
/* 788 */	NdrFcLong( 0x0 ),	/* 0 */
/* 792 */	NdrFcLong( 0x0 ),	/* 0 */
/* 796 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 798 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 800 */	NdrFcShort( 0x4 ),	/* 4 */
/* 802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 804 */	NdrFcShort( 0x1 ),	/* 1 */
/* 806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 810 */	0x13, 0x0,	/* FC_OP */
/* 812 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (756) */
/* 814 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 816 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 818 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 820 */	NdrFcShort( 0x8 ),	/* 8 */
/* 822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 824 */	NdrFcShort( 0x6 ),	/* Offset= 6 (830) */
/* 826 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 828 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 830 */	
			0x11, 0x0,	/* FC_RP */
/* 832 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (776) */
/* 834 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 836 */	NdrFcShort( 0x8 ),	/* 8 */
/* 838 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 840 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 842 */	NdrFcShort( 0x10 ),	/* 16 */
/* 844 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 846 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 848 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (834) */
			0x5b,		/* FC_END */
/* 852 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 854 */	NdrFcShort( 0x18 ),	/* 24 */
/* 856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 858 */	NdrFcShort( 0xa ),	/* Offset= 10 (868) */
/* 860 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 862 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 864 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (840) */
/* 866 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 868 */	
			0x11, 0x0,	/* FC_RP */
/* 870 */	NdrFcShort( 0xfeb8 ),	/* Offset= -328 (542) */
/* 872 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 874 */	NdrFcShort( 0x1 ),	/* 1 */
/* 876 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 878 */	NdrFcShort( 0x0 ),	/* 0 */
/* 880 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 882 */	0x0 , 
			0x0,		/* 0 */
/* 884 */	NdrFcLong( 0x0 ),	/* 0 */
/* 888 */	NdrFcLong( 0x0 ),	/* 0 */
/* 892 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 894 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 896 */	NdrFcShort( 0x8 ),	/* 8 */
/* 898 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 900 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 902 */	NdrFcShort( 0x4 ),	/* 4 */
/* 904 */	NdrFcShort( 0x4 ),	/* 4 */
/* 906 */	0x13, 0x20,	/* FC_OP [maybenull_sizeis] */
/* 908 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (872) */
/* 910 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 912 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 914 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 916 */	NdrFcShort( 0x2 ),	/* 2 */
/* 918 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 922 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 924 */	0x0 , 
			0x0,		/* 0 */
/* 926 */	NdrFcLong( 0x0 ),	/* 0 */
/* 930 */	NdrFcLong( 0x0 ),	/* 0 */
/* 934 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 936 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 938 */	NdrFcShort( 0x8 ),	/* 8 */
/* 940 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 942 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 944 */	NdrFcShort( 0x4 ),	/* 4 */
/* 946 */	NdrFcShort( 0x4 ),	/* 4 */
/* 948 */	0x13, 0x20,	/* FC_OP [maybenull_sizeis] */
/* 950 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (914) */
/* 952 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 954 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 956 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 958 */	NdrFcShort( 0x4 ),	/* 4 */
/* 960 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 964 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 966 */	0x0 , 
			0x0,		/* 0 */
/* 968 */	NdrFcLong( 0x0 ),	/* 0 */
/* 972 */	NdrFcLong( 0x0 ),	/* 0 */
/* 976 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 978 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 980 */	NdrFcShort( 0x8 ),	/* 8 */
/* 982 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 984 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 986 */	NdrFcShort( 0x4 ),	/* 4 */
/* 988 */	NdrFcShort( 0x4 ),	/* 4 */
/* 990 */	0x13, 0x20,	/* FC_OP [maybenull_sizeis] */
/* 992 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (956) */
/* 994 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 996 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 998 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 1000 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1002 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1006 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1008 */	0x0 , 
			0x0,		/* 0 */
/* 1010 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1014 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1018 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1020 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1022 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1024 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1026 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1028 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1030 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1032 */	0x13, 0x20,	/* FC_OP [maybenull_sizeis] */
/* 1034 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (998) */
/* 1036 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1038 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1040 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 1042 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1044 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1046 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1048 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1050 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1052 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 1054 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 1056 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1058 */	0x0 , 
			0x0,		/* 0 */
/* 1060 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1064 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1068 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1070 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (1040) */
/* 1072 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1074 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1076 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1078 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (1048) */
/* 1080 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1080) */
/* 1082 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1084 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1086 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1088 */	NdrFcShort( 0xfd5c ),	/* Offset= -676 (412) */
/* 1090 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1092 */	
			0x13, 0x0,	/* FC_OP */
/* 1094 */	NdrFcShort( 0xfeae ),	/* Offset= -338 (756) */
/* 1096 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1098 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 1100 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1102 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1104 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1106 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1108 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1110 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 1112 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1114 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 1116 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1118 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 1120 */	
			0x13, 0x0,	/* FC_OP */
/* 1122 */	NdrFcShort( 0xfce4 ),	/* Offset= -796 (326) */
/* 1124 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1126 */	NdrFcShort( 0xfce6 ),	/* Offset= -794 (332) */
/* 1128 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1130 */	NdrFcShort( 0xfd06 ),	/* Offset= -762 (368) */
/* 1132 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1134 */	NdrFcShort( 0xfd14 ),	/* Offset= -748 (386) */
/* 1136 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1138 */	NdrFcShort( 0xfd22 ),	/* Offset= -734 (404) */
/* 1140 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1142 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1144) */
/* 1144 */	
			0x13, 0x0,	/* FC_OP */
/* 1146 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1166) */
/* 1148 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 1150 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1152 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 1154 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 1156 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1158 */	
			0x13, 0x0,	/* FC_OP */
/* 1160 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1148) */
/* 1162 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1164 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1166 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1168 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1172 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1172) */
/* 1174 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1176 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1178 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1180 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1182 */	NdrFcShort( 0xfb74 ),	/* Offset= -1164 (18) */
/* 1184 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1186 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1190 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1194 */	NdrFcShort( 0xfb64 ),	/* Offset= -1180 (14) */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            }

        };



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IQNG, ver. 0.0,
   GUID={0x49747D38,0xE3ED,0x4CA8,{0xBD,0x48,0xF2,0x83,0xD0,0xB4,0x68,0xFB}} */

#pragma code_seg(".orpc")
static const unsigned short IQNG_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    36,
    72,
    108,
    150,
    180
    };

static const MIDL_STUBLESS_PROXY_INFO IQNG_ProxyInfo =
    {
    &Object_StubDesc,
    QWQNG__MIDL_ProcFormatString.Format,
    &IQNG_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IQNG_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    QWQNG__MIDL_ProcFormatString.Format,
    &IQNG_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IQNGProxyVtbl = 
{
    &IQNG_ProxyInfo,
    &IID_IQNG,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IQNG::get_RandInt32 */ ,
    (void *) (INT_PTR) -1 /* IQNG::get_RandUniform */ ,
    (void *) (INT_PTR) -1 /* IQNG::get_RandNormal */ ,
    (void *) (INT_PTR) -1 /* IQNG::get_RandBytes */ ,
    (void *) (INT_PTR) -1 /* IQNG::Clear */ ,
    (void *) (INT_PTR) -1 /* IQNG::Reset */
};


static const PRPC_STUB_FUNCTION IQNG_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IQNGStubVtbl =
{
    &IID_IQNG,
    &IQNG_ServerInfo,
    13,
    &IQNG_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    QWQNG__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x60001, /* Ndr library version */
    0,
    0x801026e, /* MIDL Version 8.1.622 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _QWQNG_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IQNGProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _QWQNG_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IQNGStubVtbl,
    0
};

PCInterfaceName const _QWQNG_InterfaceNamesList[] = 
{
    "IQNG",
    0
};

const IID *  const _QWQNG_BaseIIDList[] = 
{
    &IID_IDispatch,
    0
};


#define _QWQNG_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _QWQNG, pIID, n)

int __stdcall _QWQNG_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_QWQNG_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo QWQNG_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _QWQNG_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _QWQNG_StubVtblList,
    (const PCInterfaceName * ) & _QWQNG_InterfaceNamesList,
    (const IID ** ) & _QWQNG_BaseIIDList,
    & _QWQNG_IID_Lookup, 
    1,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_) */

