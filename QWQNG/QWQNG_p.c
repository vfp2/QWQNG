

/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if defined(_M_AMD64)


#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#include "ndr64types.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "QWQNG.h"

#define TYPE_FORMAT_STRING_SIZE   1177                              
#define PROC_FORMAT_STRING_SIZE   223                               
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

static const RPC_SYNTAX_IDENTIFIER  _NDR64_RpcTransferSyntax = 
{{0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0}};



extern const QWQNG_MIDL_TYPE_FORMAT_STRING QWQNG__MIDL_TypeFormatString;
extern const QWQNG_MIDL_PROC_FORMAT_STRING QWQNG__MIDL_ProcFormatString;
extern const QWQNG_MIDL_EXPR_FORMAT_STRING QWQNG__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IQNG_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IQNG_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE NDR64_UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];
extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
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
/*  8 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x24 ),	/* 36 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0xa,		/* 10 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 26 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 28 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 30 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 32 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 34 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 36 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RandUniform */

/* 38 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 40 */	NdrFcLong( 0x0 ),	/* 0 */
/* 44 */	NdrFcShort( 0x8 ),	/* 8 */
/* 46 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 48 */	NdrFcShort( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x2c ),	/* 44 */
/* 52 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 54 */	0xa,		/* 10 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 64 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 66 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 68 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 70 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 72 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 74 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RandNormal */

/* 76 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 78 */	NdrFcLong( 0x0 ),	/* 0 */
/* 82 */	NdrFcShort( 0x9 ),	/* 9 */
/* 84 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x2c ),	/* 44 */
/* 90 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 92 */	0xa,		/* 10 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */
/* 96 */	NdrFcShort( 0x0 ),	/* 0 */
/* 98 */	NdrFcShort( 0x0 ),	/* 0 */
/* 100 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 102 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 104 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 106 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 110 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RandBytes */

/* 114 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 116 */	NdrFcLong( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0xa ),	/* 10 */
/* 122 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 124 */	NdrFcShort( 0x8 ),	/* 8 */
/* 126 */	NdrFcShort( 0x8 ),	/* 8 */
/* 128 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 130 */	0xa,		/* 10 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 132 */	NdrFcShort( 0x1 ),	/* 1 */
/* 134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Length */

/* 140 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 142 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 144 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 146 */	NdrFcShort( 0x6113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
/* 148 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 150 */	NdrFcShort( 0x48e ),	/* Type Offset=1166 */

	/* Return value */

/* 152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 154 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clear */

/* 158 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0xb ),	/* 11 */
/* 166 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 170 */	NdrFcShort( 0x8 ),	/* 8 */
/* 172 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 174 */	0xa,		/* 10 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 182 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 184 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 186 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 188 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Reset */

/* 190 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 192 */	NdrFcLong( 0x0 ),	/* 0 */
/* 196 */	NdrFcShort( 0xc ),	/* 12 */
/* 198 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0x8 ),	/* 8 */
/* 204 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 206 */	0xa,		/* 10 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 216 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 218 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 220 */	0x8,		/* FC_LONG */
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
/* 12 */	NdrFcShort( 0x482 ),	/* Offset= 1154 (1166) */
/* 14 */	
			0x13, 0x0,	/* FC_OP */
/* 16 */	NdrFcShort( 0x46a ),	/* Offset= 1130 (1146) */
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
/* 130 */	NdrFcShort( 0x3ae ),	/* Offset= 942 (1072) */
/* 132 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 136 */	NdrFcShort( 0x3a8 ),	/* Offset= 936 (1072) */
/* 138 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 142 */	NdrFcShort( 0x3a6 ),	/* Offset= 934 (1076) */
/* 144 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 148 */	NdrFcShort( 0x3a4 ),	/* Offset= 932 (1080) */
/* 150 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 154 */	NdrFcShort( 0x3a2 ),	/* Offset= 930 (1084) */
/* 156 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 160 */	NdrFcShort( 0x3a0 ),	/* Offset= 928 (1088) */
/* 162 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 166 */	NdrFcShort( 0x39e ),	/* Offset= 926 (1092) */
/* 168 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 172 */	NdrFcShort( 0x39c ),	/* Offset= 924 (1096) */
/* 174 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 178 */	NdrFcShort( 0x386 ),	/* Offset= 902 (1080) */
/* 180 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 184 */	NdrFcShort( 0x384 ),	/* Offset= 900 (1084) */
/* 186 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 190 */	NdrFcShort( 0x38e ),	/* Offset= 910 (1100) */
/* 192 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 196 */	NdrFcShort( 0x384 ),	/* Offset= 900 (1096) */
/* 198 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 202 */	NdrFcShort( 0x386 ),	/* Offset= 902 (1104) */
/* 204 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 208 */	NdrFcShort( 0x384 ),	/* Offset= 900 (1108) */
/* 210 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 214 */	NdrFcShort( 0x382 ),	/* Offset= 898 (1112) */
/* 216 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 220 */	NdrFcShort( 0x380 ),	/* Offset= 896 (1116) */
/* 222 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 226 */	NdrFcShort( 0x37e ),	/* Offset= 894 (1120) */
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
/* 268 */	NdrFcShort( 0x35c ),	/* Offset= 860 (1128) */
/* 270 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 274 */	NdrFcShort( 0x360 ),	/* Offset= 864 (1138) */
/* 276 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 280 */	NdrFcShort( 0x35e ),	/* Offset= 862 (1142) */
/* 282 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 286 */	NdrFcShort( 0x31a ),	/* Offset= 794 (1080) */
/* 288 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 292 */	NdrFcShort( 0x318 ),	/* Offset= 792 (1084) */
/* 294 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 298 */	NdrFcShort( 0x316 ),	/* Offset= 790 (1088) */
/* 300 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 304 */	NdrFcShort( 0x30c ),	/* Offset= 780 (1084) */
/* 306 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 310 */	NdrFcShort( 0x306 ),	/* Offset= 774 (1084) */
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
/* 410 */	NdrFcShort( 0x284 ),	/* Offset= 644 (1054) */
/* 412 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x89,		/* 137 */
/* 414 */	NdrFcShort( 0x20 ),	/* 32 */
/* 416 */	NdrFcShort( 0xa ),	/* 10 */
/* 418 */	NdrFcLong( 0x8 ),	/* 8 */
/* 422 */	NdrFcShort( 0x64 ),	/* Offset= 100 (522) */
/* 424 */	NdrFcLong( 0xd ),	/* 13 */
/* 428 */	NdrFcShort( 0x98 ),	/* Offset= 152 (580) */
/* 430 */	NdrFcLong( 0x9 ),	/* 9 */
/* 434 */	NdrFcShort( 0xcc ),	/* Offset= 204 (638) */
/* 436 */	NdrFcLong( 0xc ),	/* 12 */
/* 440 */	NdrFcShort( 0x100 ),	/* Offset= 256 (696) */
/* 442 */	NdrFcLong( 0x24 ),	/* 36 */
/* 446 */	NdrFcShort( 0x170 ),	/* Offset= 368 (814) */
/* 448 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 452 */	NdrFcShort( 0x18c ),	/* Offset= 396 (848) */
/* 454 */	NdrFcLong( 0x10 ),	/* 16 */
/* 458 */	NdrFcShort( 0x1b0 ),	/* Offset= 432 (890) */
/* 460 */	NdrFcLong( 0x2 ),	/* 2 */
/* 464 */	NdrFcShort( 0x1d0 ),	/* Offset= 464 (928) */
/* 466 */	NdrFcLong( 0x3 ),	/* 3 */
/* 470 */	NdrFcShort( 0x1f0 ),	/* Offset= 496 (966) */
/* 472 */	NdrFcLong( 0x14 ),	/* 20 */
/* 476 */	NdrFcShort( 0x210 ),	/* Offset= 528 (1004) */
/* 478 */	NdrFcShort( 0xffff ),	/* Offset= -1 (477) */
/* 480 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 482 */	NdrFcShort( 0x0 ),	/* 0 */
/* 484 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 488 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 490 */	0x0 , 
			0x0,		/* 0 */
/* 492 */	NdrFcLong( 0x0 ),	/* 0 */
/* 496 */	NdrFcLong( 0x0 ),	/* 0 */
/* 500 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 504 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 506 */	0x0 , 
			0x0,		/* 0 */
/* 508 */	NdrFcLong( 0x0 ),	/* 0 */
/* 512 */	NdrFcLong( 0x0 ),	/* 0 */
/* 516 */	
			0x13, 0x0,	/* FC_OP */
/* 518 */	NdrFcShort( 0xff60 ),	/* Offset= -160 (358) */
/* 520 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 522 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 524 */	NdrFcShort( 0x10 ),	/* 16 */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 528 */	NdrFcShort( 0x6 ),	/* Offset= 6 (534) */
/* 530 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 532 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 534 */	
			0x11, 0x0,	/* FC_RP */
/* 536 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (480) */
/* 538 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 542 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 546 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 548 */	0x0 , 
			0x0,		/* 0 */
/* 550 */	NdrFcLong( 0x0 ),	/* 0 */
/* 554 */	NdrFcLong( 0x0 ),	/* 0 */
/* 558 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 562 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 564 */	0x0 , 
			0x0,		/* 0 */
/* 566 */	NdrFcLong( 0x0 ),	/* 0 */
/* 570 */	NdrFcLong( 0x0 ),	/* 0 */
/* 574 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 576 */	NdrFcShort( 0xff30 ),	/* Offset= -208 (368) */
/* 578 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 580 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 582 */	NdrFcShort( 0x10 ),	/* 16 */
/* 584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 586 */	NdrFcShort( 0x6 ),	/* Offset= 6 (592) */
/* 588 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 590 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 592 */	
			0x11, 0x0,	/* FC_RP */
/* 594 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (538) */
/* 596 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 600 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 604 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 606 */	0x0 , 
			0x0,		/* 0 */
/* 608 */	NdrFcLong( 0x0 ),	/* 0 */
/* 612 */	NdrFcLong( 0x0 ),	/* 0 */
/* 616 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 620 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 622 */	0x0 , 
			0x0,		/* 0 */
/* 624 */	NdrFcLong( 0x0 ),	/* 0 */
/* 628 */	NdrFcLong( 0x0 ),	/* 0 */
/* 632 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 634 */	NdrFcShort( 0xff08 ),	/* Offset= -248 (386) */
/* 636 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 638 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 640 */	NdrFcShort( 0x10 ),	/* 16 */
/* 642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 644 */	NdrFcShort( 0x6 ),	/* Offset= 6 (650) */
/* 646 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 648 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 650 */	
			0x11, 0x0,	/* FC_RP */
/* 652 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (596) */
/* 654 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 658 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 662 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 664 */	0x0 , 
			0x0,		/* 0 */
/* 666 */	NdrFcLong( 0x0 ),	/* 0 */
/* 670 */	NdrFcLong( 0x0 ),	/* 0 */
/* 674 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 678 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 680 */	0x0 , 
			0x0,		/* 0 */
/* 682 */	NdrFcLong( 0x0 ),	/* 0 */
/* 686 */	NdrFcLong( 0x0 ),	/* 0 */
/* 690 */	
			0x13, 0x0,	/* FC_OP */
/* 692 */	NdrFcShort( 0x1c6 ),	/* Offset= 454 (1146) */
/* 694 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 696 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 698 */	NdrFcShort( 0x10 ),	/* 16 */
/* 700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 702 */	NdrFcShort( 0x6 ),	/* Offset= 6 (708) */
/* 704 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 706 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 708 */	
			0x11, 0x0,	/* FC_RP */
/* 710 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (654) */
/* 712 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 714 */	NdrFcLong( 0x2f ),	/* 47 */
/* 718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 722 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 724 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 726 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 728 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 730 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 732 */	NdrFcShort( 0x1 ),	/* 1 */
/* 734 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 736 */	NdrFcShort( 0x4 ),	/* 4 */
/* 738 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 740 */	0x0 , 
			0x0,		/* 0 */
/* 742 */	NdrFcLong( 0x0 ),	/* 0 */
/* 746 */	NdrFcLong( 0x0 ),	/* 0 */
/* 750 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 752 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 754 */	NdrFcShort( 0x18 ),	/* 24 */
/* 756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 758 */	NdrFcShort( 0xa ),	/* Offset= 10 (768) */
/* 760 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 762 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 764 */	NdrFcShort( 0xffcc ),	/* Offset= -52 (712) */
/* 766 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 768 */	
			0x13, 0x20,	/* FC_OP [maybenull_sizeis] */
/* 770 */	NdrFcShort( 0xffd8 ),	/* Offset= -40 (730) */
/* 772 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 776 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 780 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 782 */	0x0 , 
			0x0,		/* 0 */
/* 784 */	NdrFcLong( 0x0 ),	/* 0 */
/* 788 */	NdrFcLong( 0x0 ),	/* 0 */
/* 792 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 796 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 798 */	0x0 , 
			0x0,		/* 0 */
/* 800 */	NdrFcLong( 0x0 ),	/* 0 */
/* 804 */	NdrFcLong( 0x0 ),	/* 0 */
/* 808 */	
			0x13, 0x0,	/* FC_OP */
/* 810 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (752) */
/* 812 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 814 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 816 */	NdrFcShort( 0x10 ),	/* 16 */
/* 818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 820 */	NdrFcShort( 0x6 ),	/* Offset= 6 (826) */
/* 822 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 824 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 826 */	
			0x11, 0x0,	/* FC_RP */
/* 828 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (772) */
/* 830 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 832 */	NdrFcShort( 0x8 ),	/* 8 */
/* 834 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 836 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 838 */	NdrFcShort( 0x10 ),	/* 16 */
/* 840 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 842 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 844 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (830) */
			0x5b,		/* FC_END */
/* 848 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 850 */	NdrFcShort( 0x20 ),	/* 32 */
/* 852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 854 */	NdrFcShort( 0xa ),	/* Offset= 10 (864) */
/* 856 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 858 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 860 */	0x0,		/* 0 */
			NdrFcShort( 0xffe7 ),	/* Offset= -25 (836) */
			0x5b,		/* FC_END */
/* 864 */	
			0x11, 0x0,	/* FC_RP */
/* 866 */	NdrFcShort( 0xfeb8 ),	/* Offset= -328 (538) */
/* 868 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 870 */	NdrFcShort( 0x1 ),	/* 1 */
/* 872 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 876 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 878 */	0x0 , 
			0x0,		/* 0 */
/* 880 */	NdrFcLong( 0x0 ),	/* 0 */
/* 884 */	NdrFcLong( 0x0 ),	/* 0 */
/* 888 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 890 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 892 */	NdrFcShort( 0x10 ),	/* 16 */
/* 894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 896 */	NdrFcShort( 0x6 ),	/* Offset= 6 (902) */
/* 898 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 900 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 902 */	
			0x13, 0x20,	/* FC_OP [maybenull_sizeis] */
/* 904 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (868) */
/* 906 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 908 */	NdrFcShort( 0x2 ),	/* 2 */
/* 910 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 914 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 916 */	0x0 , 
			0x0,		/* 0 */
/* 918 */	NdrFcLong( 0x0 ),	/* 0 */
/* 922 */	NdrFcLong( 0x0 ),	/* 0 */
/* 926 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 928 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 930 */	NdrFcShort( 0x10 ),	/* 16 */
/* 932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 934 */	NdrFcShort( 0x6 ),	/* Offset= 6 (940) */
/* 936 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 938 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 940 */	
			0x13, 0x20,	/* FC_OP [maybenull_sizeis] */
/* 942 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (906) */
/* 944 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 946 */	NdrFcShort( 0x4 ),	/* 4 */
/* 948 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 952 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 954 */	0x0 , 
			0x0,		/* 0 */
/* 956 */	NdrFcLong( 0x0 ),	/* 0 */
/* 960 */	NdrFcLong( 0x0 ),	/* 0 */
/* 964 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 966 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 968 */	NdrFcShort( 0x10 ),	/* 16 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 972 */	NdrFcShort( 0x6 ),	/* Offset= 6 (978) */
/* 974 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 976 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 978 */	
			0x13, 0x20,	/* FC_OP [maybenull_sizeis] */
/* 980 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (944) */
/* 982 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 984 */	NdrFcShort( 0x8 ),	/* 8 */
/* 986 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 990 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 992 */	0x0 , 
			0x0,		/* 0 */
/* 994 */	NdrFcLong( 0x0 ),	/* 0 */
/* 998 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1002 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1004 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1006 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1010 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1016) */
/* 1012 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1014 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1016 */	
			0x13, 0x20,	/* FC_OP [maybenull_sizeis] */
/* 1018 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (982) */
/* 1020 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 1022 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1024 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1026 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1028 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1030 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1032 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 1034 */	NdrFcShort( 0xffc8 ),	/* -56 */
/* 1036 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1038 */	0x0 , 
			0x0,		/* 0 */
/* 1040 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1044 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1048 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1050 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (1020) */
/* 1052 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1054 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1056 */	NdrFcShort( 0x38 ),	/* 56 */
/* 1058 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (1028) */
/* 1060 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1060) */
/* 1062 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1064 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1066 */	0x40,		/* FC_STRUCTPAD4 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1068 */	0x0,		/* 0 */
			NdrFcShort( 0xfd6f ),	/* Offset= -657 (412) */
			0x5b,		/* FC_END */
/* 1072 */	
			0x13, 0x0,	/* FC_OP */
/* 1074 */	NdrFcShort( 0xfebe ),	/* Offset= -322 (752) */
/* 1076 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1078 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 1080 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1082 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1084 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1086 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1088 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1090 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 1092 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1094 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 1096 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1098 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 1100 */	
			0x13, 0x0,	/* FC_OP */
/* 1102 */	NdrFcShort( 0xfcf8 ),	/* Offset= -776 (326) */
/* 1104 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1106 */	NdrFcShort( 0xfcfa ),	/* Offset= -774 (332) */
/* 1108 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1110 */	NdrFcShort( 0xfd1a ),	/* Offset= -742 (368) */
/* 1112 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1114 */	NdrFcShort( 0xfd28 ),	/* Offset= -728 (386) */
/* 1116 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1118 */	NdrFcShort( 0xfd36 ),	/* Offset= -714 (404) */
/* 1120 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1122 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1124) */
/* 1124 */	
			0x13, 0x0,	/* FC_OP */
/* 1126 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1146) */
/* 1128 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 1130 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1132 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 1134 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 1136 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1138 */	
			0x13, 0x0,	/* FC_OP */
/* 1140 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1128) */
/* 1142 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1144 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1146 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1148 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1152 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1152) */
/* 1154 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1156 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1158 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1160 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1162 */	NdrFcShort( 0xfb88 ),	/* Offset= -1144 (18) */
/* 1164 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1166 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1170 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1174 */	NdrFcShort( 0xfb78 ),	/* Offset= -1160 (14) */

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
    38,
    76,
    114,
    158,
    190
    };



#endif /* defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if defined(_M_AMD64)



extern const USER_MARSHAL_ROUTINE_QUADRUPLE NDR64_UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];
extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif


#include "ndr64types.h"
#include "pshpack8.h"


typedef 
NDR64_FORMAT_CHAR
__midl_frag167_t;
extern const __midl_frag167_t __midl_frag167;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_PARAM_FORMAT frag2;
}
__midl_frag166_t;
extern const __midl_frag166_t __midl_frag166;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag161_t;
extern const __midl_frag161_t __midl_frag161;

typedef 
NDR64_FORMAT_CHAR
__midl_frag158_t;
extern const __midl_frag158_t __midl_frag158;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag157_t;
extern const __midl_frag157_t __midl_frag157;

typedef 
NDR64_FORMAT_CHAR
__midl_frag154_t;
extern const __midl_frag154_t __midl_frag154;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag153_t;
extern const __midl_frag153_t __midl_frag153;

typedef 
NDR64_FORMAT_CHAR
__midl_frag152_t;
extern const __midl_frag152_t __midl_frag152;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag151_t;
extern const __midl_frag151_t __midl_frag151;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag150_t;
extern const __midl_frag150_t __midl_frag150;

typedef 
struct 
{
    struct _NDR64_STRUCTURE_HEADER_FORMAT frag1;
}
__midl_frag149_t;
extern const __midl_frag149_t __midl_frag149;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag142_t;
extern const __midl_frag142_t __midl_frag142;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag141_t;
extern const __midl_frag141_t __midl_frag141;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag140_t;
extern const __midl_frag140_t __midl_frag140;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag139_t;
extern const __midl_frag139_t __midl_frag139;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag138_t;
extern const __midl_frag138_t __midl_frag138;

typedef 
struct _NDR64_CONSTANT_IID_FORMAT
__midl_frag137_t;
extern const __midl_frag137_t __midl_frag137;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag136_t;
extern const __midl_frag136_t __midl_frag136;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag135_t;
extern const __midl_frag135_t __midl_frag135;

typedef 
struct _NDR64_CONSTANT_IID_FORMAT
__midl_frag134_t;
extern const __midl_frag134_t __midl_frag134;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag133_t;
extern const __midl_frag133_t __midl_frag133;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag132_t;
extern const __midl_frag132_t __midl_frag132;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag131_t;
extern const __midl_frag131_t __midl_frag131;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag130_t;
extern const __midl_frag130_t __midl_frag130;

typedef 
NDR64_FORMAT_CHAR
__midl_frag129_t;
extern const __midl_frag129_t __midl_frag129;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag128_t;
extern const __midl_frag128_t __midl_frag128;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag127_t;
extern const __midl_frag127_t __midl_frag127;

typedef 
NDR64_FORMAT_CHAR
__midl_frag120_t;
extern const __midl_frag120_t __midl_frag120;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag119_t;
extern const __midl_frag119_t __midl_frag119;

typedef 
NDR64_FORMAT_CHAR
__midl_frag112_t;
extern const __midl_frag112_t __midl_frag112;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag111_t;
extern const __midl_frag111_t __midl_frag111;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag110_t;
extern const __midl_frag110_t __midl_frag110;

typedef 
struct 
{
    struct _NDR64_POINTER_FORMAT frag1;
}
__midl_frag109_t;
extern const __midl_frag109_t __midl_frag109;

typedef 
struct 
{
    NDR64_FORMAT_UINT32 frag1;
    struct _NDR64_EXPR_VAR frag2;
}
__midl_frag107_t;
extern const __midl_frag107_t __midl_frag107;

typedef 
struct 
{
    struct _NDR64_CONF_ARRAY_HEADER_FORMAT frag1;
    struct _NDR64_ARRAY_ELEMENT_INFO frag2;
}
__midl_frag106_t;
extern const __midl_frag106_t __midl_frag106;

typedef 
struct 
{
    struct _NDR64_BOGUS_STRUCTURE_HEADER_FORMAT frag1;
    struct 
    {
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag1;
        struct _NDR64_MEMPAD_FORMAT frag2;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag3;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag4;
    } frag2;
}
__midl_frag105_t;
extern const __midl_frag105_t __midl_frag105;

typedef 
struct 
{
    struct _NDR64_POINTER_FORMAT frag1;
}
__midl_frag104_t;
extern const __midl_frag104_t __midl_frag104;

typedef 
struct 
{
    struct _NDR64_CONF_ARRAY_HEADER_FORMAT frag1;
    struct _NDR64_ARRAY_ELEMENT_INFO frag2;
}
__midl_frag101_t;
extern const __midl_frag101_t __midl_frag101;

typedef 
struct 
{
    struct _NDR64_BOGUS_STRUCTURE_HEADER_FORMAT frag1;
    struct 
    {
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag1;
        struct _NDR64_MEMPAD_FORMAT frag2;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag3;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag4;
    } frag2;
}
__midl_frag100_t;
extern const __midl_frag100_t __midl_frag100;

typedef 
struct 
{
    struct _NDR64_POINTER_FORMAT frag1;
}
__midl_frag99_t;
extern const __midl_frag99_t __midl_frag99;

typedef 
struct 
{
    struct _NDR64_CONF_ARRAY_HEADER_FORMAT frag1;
    struct _NDR64_ARRAY_ELEMENT_INFO frag2;
}
__midl_frag96_t;
extern const __midl_frag96_t __midl_frag96;

typedef 
struct 
{
    struct _NDR64_BOGUS_STRUCTURE_HEADER_FORMAT frag1;
    struct 
    {
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag1;
        struct _NDR64_MEMPAD_FORMAT frag2;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag3;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag4;
    } frag2;
}
__midl_frag95_t;
extern const __midl_frag95_t __midl_frag95;

typedef 
struct 
{
    struct _NDR64_POINTER_FORMAT frag1;
}
__midl_frag94_t;
extern const __midl_frag94_t __midl_frag94;

typedef 
struct 
{
    struct _NDR64_CONF_ARRAY_HEADER_FORMAT frag1;
    struct _NDR64_ARRAY_ELEMENT_INFO frag2;
}
__midl_frag91_t;
extern const __midl_frag91_t __midl_frag91;

typedef 
struct 
{
    struct _NDR64_BOGUS_STRUCTURE_HEADER_FORMAT frag1;
    struct 
    {
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag1;
        struct _NDR64_MEMPAD_FORMAT frag2;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag3;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag4;
    } frag2;
}
__midl_frag90_t;
extern const __midl_frag90_t __midl_frag90;

typedef 
struct 
{
    struct _NDR64_FIX_ARRAY_HEADER_FORMAT frag1;
}
__midl_frag89_t;
extern const __midl_frag89_t __midl_frag89;

typedef 
struct 
{
    struct _NDR64_POINTER_FORMAT frag1;
}
__midl_frag88_t;
extern const __midl_frag88_t __midl_frag88;

typedef 
struct 
{
    struct _NDR64_CONF_ARRAY_HEADER_FORMAT frag1;
    struct 
    {
        struct _NDR64_REPEAT_FORMAT frag1;
        struct 
        {
            struct _NDR64_POINTER_INSTANCE_HEADER_FORMAT frag1;
            struct _NDR64_POINTER_FORMAT frag2;
        } frag2;
        NDR64_FORMAT_CHAR frag3;
    } frag2;
    struct _NDR64_ARRAY_ELEMENT_INFO frag3;
}
__midl_frag83_t;
extern const __midl_frag83_t __midl_frag83;

typedef 
struct 
{
    struct _NDR64_BOGUS_STRUCTURE_HEADER_FORMAT frag1;
    struct 
    {
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag1;
        struct _NDR64_MEMPAD_FORMAT frag2;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag3;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag4;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag5;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag6;
        struct _NDR64_EMBEDDED_COMPLEX_FORMAT frag7;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag8;
    } frag2;
}
__midl_frag82_t;
extern const __midl_frag82_t __midl_frag82;

typedef 
struct 
{
    struct _NDR64_POINTER_FORMAT frag1;
}
__midl_frag81_t;
extern const __midl_frag81_t __midl_frag81;

typedef 
struct 
{
    NDR64_FORMAT_UINT32 frag1;
    struct _NDR64_EXPR_VAR frag2;
}
__midl_frag78_t;
extern const __midl_frag78_t __midl_frag78;

typedef 
struct 
{
    struct _NDR64_CONF_ARRAY_HEADER_FORMAT frag1;
    struct _NDR64_ARRAY_ELEMENT_INFO frag2;
}
__midl_frag77_t;
extern const __midl_frag77_t __midl_frag77;

typedef 
struct _NDR64_CONSTANT_IID_FORMAT
__midl_frag76_t;
extern const __midl_frag76_t __midl_frag76;

typedef 
struct 
{
    struct _NDR64_STRUCTURE_HEADER_FORMAT frag1;
    struct 
    {
        struct _NDR64_NO_REPEAT_FORMAT frag1;
        struct _NDR64_POINTER_INSTANCE_HEADER_FORMAT frag2;
        struct _NDR64_POINTER_FORMAT frag3;
        struct _NDR64_NO_REPEAT_FORMAT frag4;
        struct _NDR64_POINTER_INSTANCE_HEADER_FORMAT frag5;
        struct _NDR64_POINTER_FORMAT frag6;
        NDR64_FORMAT_CHAR frag7;
    } frag2;
}
__midl_frag75_t;
extern const __midl_frag75_t __midl_frag75;

typedef 
struct 
{
    struct _NDR64_CONF_ARRAY_HEADER_FORMAT frag1;
    struct 
    {
        struct _NDR64_REPEAT_FORMAT frag1;
        struct 
        {
            struct _NDR64_POINTER_INSTANCE_HEADER_FORMAT frag1;
            struct _NDR64_POINTER_FORMAT frag2;
        } frag2;
        NDR64_FORMAT_CHAR frag3;
    } frag2;
    struct _NDR64_ARRAY_ELEMENT_INFO frag3;
}
__midl_frag73_t;
extern const __midl_frag73_t __midl_frag73;

typedef 
struct 
{
    struct _NDR64_BOGUS_STRUCTURE_HEADER_FORMAT frag1;
    struct 
    {
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag1;
        struct _NDR64_MEMPAD_FORMAT frag2;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag3;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag4;
    } frag2;
}
__midl_frag72_t;
extern const __midl_frag72_t __midl_frag72;

typedef 
struct 
{
    struct _NDR64_POINTER_FORMAT frag1;
}
__midl_frag71_t;
extern const __midl_frag71_t __midl_frag71;

typedef 
struct 
{
    struct _NDR64_CONF_ARRAY_HEADER_FORMAT frag1;
    struct 
    {
        struct _NDR64_REPEAT_FORMAT frag1;
        struct 
        {
            struct _NDR64_POINTER_INSTANCE_HEADER_FORMAT frag1;
            struct _NDR64_POINTER_FORMAT frag2;
        } frag2;
        NDR64_FORMAT_CHAR frag3;
    } frag2;
    struct _NDR64_ARRAY_ELEMENT_INFO frag3;
}
__midl_frag68_t;
extern const __midl_frag68_t __midl_frag68;

typedef 
struct 
{
    struct _NDR64_BOGUS_STRUCTURE_HEADER_FORMAT frag1;
    struct 
    {
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag1;
        struct _NDR64_MEMPAD_FORMAT frag2;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag3;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag4;
    } frag2;
}
__midl_frag67_t;
extern const __midl_frag67_t __midl_frag67;

typedef 
struct 
{
    struct _NDR64_POINTER_FORMAT frag1;
}
__midl_frag66_t;
extern const __midl_frag66_t __midl_frag66;

typedef 
struct 
{
    struct _NDR64_CONF_ARRAY_HEADER_FORMAT frag1;
    struct 
    {
        struct _NDR64_REPEAT_FORMAT frag1;
        struct 
        {
            struct _NDR64_POINTER_INSTANCE_HEADER_FORMAT frag1;
            struct _NDR64_POINTER_FORMAT frag2;
        } frag2;
        NDR64_FORMAT_CHAR frag3;
    } frag2;
    struct _NDR64_ARRAY_ELEMENT_INFO frag3;
}
__midl_frag61_t;
extern const __midl_frag61_t __midl_frag61;

typedef 
struct 
{
    struct _NDR64_BOGUS_STRUCTURE_HEADER_FORMAT frag1;
    struct 
    {
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag1;
        struct _NDR64_MEMPAD_FORMAT frag2;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag3;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag4;
    } frag2;
}
__midl_frag60_t;
extern const __midl_frag60_t __midl_frag60;

typedef 
struct 
{
    struct _NDR64_BOGUS_STRUCTURE_HEADER_FORMAT frag1;
    struct 
    {
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag1;
        struct _NDR64_MEMPAD_FORMAT frag2;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag3;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag4;
    } frag2;
}
__midl_frag53_t;
extern const __midl_frag53_t __midl_frag53;

typedef 
struct 
{
    struct _NDR64_POINTER_FORMAT frag1;
}
__midl_frag52_t;
extern const __midl_frag52_t __midl_frag52;

typedef 
struct 
{
    struct _NDR64_CONF_ARRAY_HEADER_FORMAT frag1;
    struct 
    {
        struct _NDR64_REPEAT_FORMAT frag1;
        struct 
        {
            struct _NDR64_POINTER_INSTANCE_HEADER_FORMAT frag1;
            struct _NDR64_POINTER_FORMAT frag2;
        } frag2;
        NDR64_FORMAT_CHAR frag3;
    } frag2;
    struct _NDR64_ARRAY_ELEMENT_INFO frag3;
}
__midl_frag49_t;
extern const __midl_frag49_t __midl_frag49;

typedef 
struct 
{
    struct _NDR64_BOGUS_STRUCTURE_HEADER_FORMAT frag1;
    struct 
    {
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag1;
        struct _NDR64_MEMPAD_FORMAT frag2;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag3;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag4;
    } frag2;
}
__midl_frag48_t;
extern const __midl_frag48_t __midl_frag48;

typedef 
struct 
{
    struct _NDR64_ENCAPSULATED_UNION frag1;
    struct _NDR64_UNION_ARM_SELECTOR frag2;
    struct _NDR64_UNION_ARM frag3;
    struct _NDR64_UNION_ARM frag4;
    struct _NDR64_UNION_ARM frag5;
    struct _NDR64_UNION_ARM frag6;
    struct _NDR64_UNION_ARM frag7;
    struct _NDR64_UNION_ARM frag8;
    struct _NDR64_UNION_ARM frag9;
    struct _NDR64_UNION_ARM frag10;
    struct _NDR64_UNION_ARM frag11;
    struct _NDR64_UNION_ARM frag12;
    NDR64_UINT32 frag13;
}
__midl_frag47_t;
extern const __midl_frag47_t __midl_frag47;

typedef 
struct 
{
    struct _NDR64_STRUCTURE_HEADER_FORMAT frag1;
}
__midl_frag46_t;
extern const __midl_frag46_t __midl_frag46;

typedef 
struct 
{
    NDR64_FORMAT_UINT32 frag1;
    struct _NDR64_EXPR_VAR frag2;
}
__midl_frag45_t;
extern const __midl_frag45_t __midl_frag45;

typedef 
struct 
{
    struct _NDR64_CONF_ARRAY_HEADER_FORMAT frag1;
    struct _NDR64_ARRAY_ELEMENT_INFO frag2;
}
__midl_frag44_t;
extern const __midl_frag44_t __midl_frag44;

typedef 
struct 
{
    struct _NDR64_CONF_BOGUS_STRUCTURE_HEADER_FORMAT frag1;
    struct 
    {
        struct _NDR64_SIMPLE_REGION_FORMAT frag1;
        struct _NDR64_MEMPAD_FORMAT frag2;
        struct _NDR64_EMBEDDED_COMPLEX_FORMAT frag3;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag4;
    } frag2;
}
__midl_frag43_t;
extern const __midl_frag43_t __midl_frag43;

typedef 
struct 
{
    struct _NDR64_CONF_ARRAY_HEADER_FORMAT frag1;
    struct _NDR64_ARRAY_ELEMENT_INFO frag2;
}
__midl_frag34_t;
extern const __midl_frag34_t __midl_frag34;

typedef 
struct 
{
    struct _NDR64_CONF_STRUCTURE_HEADER_FORMAT frag1;
}
__midl_frag33_t;
extern const __midl_frag33_t __midl_frag33;

typedef 
struct 
{
    struct _NDR64_STRUCTURE_HEADER_FORMAT frag1;
}
__midl_frag30_t;
extern const __midl_frag30_t __midl_frag30;

typedef 
struct 
{
    NDR64_FORMAT_UINT32 frag1;
    struct _NDR64_EXPR_VAR frag2;
}
__midl_frag21_t;
extern const __midl_frag21_t __midl_frag21;

typedef 
struct 
{
    struct _NDR64_NON_ENCAPSULATED_UNION frag1;
    struct _NDR64_UNION_ARM_SELECTOR frag2;
    struct _NDR64_UNION_ARM frag3;
    struct _NDR64_UNION_ARM frag4;
    struct _NDR64_UNION_ARM frag5;
    struct _NDR64_UNION_ARM frag6;
    struct _NDR64_UNION_ARM frag7;
    struct _NDR64_UNION_ARM frag8;
    struct _NDR64_UNION_ARM frag9;
    struct _NDR64_UNION_ARM frag10;
    struct _NDR64_UNION_ARM frag11;
    struct _NDR64_UNION_ARM frag12;
    struct _NDR64_UNION_ARM frag13;
    struct _NDR64_UNION_ARM frag14;
    struct _NDR64_UNION_ARM frag15;
    struct _NDR64_UNION_ARM frag16;
    struct _NDR64_UNION_ARM frag17;
    struct _NDR64_UNION_ARM frag18;
    struct _NDR64_UNION_ARM frag19;
    struct _NDR64_UNION_ARM frag20;
    struct _NDR64_UNION_ARM frag21;
    struct _NDR64_UNION_ARM frag22;
    struct _NDR64_UNION_ARM frag23;
    struct _NDR64_UNION_ARM frag24;
    struct _NDR64_UNION_ARM frag25;
    struct _NDR64_UNION_ARM frag26;
    struct _NDR64_UNION_ARM frag27;
    struct _NDR64_UNION_ARM frag28;
    struct _NDR64_UNION_ARM frag29;
    struct _NDR64_UNION_ARM frag30;
    struct _NDR64_UNION_ARM frag31;
    struct _NDR64_UNION_ARM frag32;
    struct _NDR64_UNION_ARM frag33;
    struct _NDR64_UNION_ARM frag34;
    struct _NDR64_UNION_ARM frag35;
    struct _NDR64_UNION_ARM frag36;
    struct _NDR64_UNION_ARM frag37;
    struct _NDR64_UNION_ARM frag38;
    struct _NDR64_UNION_ARM frag39;
    struct _NDR64_UNION_ARM frag40;
    struct _NDR64_UNION_ARM frag41;
    struct _NDR64_UNION_ARM frag42;
    struct _NDR64_UNION_ARM frag43;
    struct _NDR64_UNION_ARM frag44;
    struct _NDR64_UNION_ARM frag45;
    struct _NDR64_UNION_ARM frag46;
    struct _NDR64_UNION_ARM frag47;
    struct _NDR64_UNION_ARM frag48;
    struct _NDR64_UNION_ARM frag49;
    NDR64_UINT32 frag50;
}
__midl_frag20_t;
extern const __midl_frag20_t __midl_frag20;

typedef 
struct 
{
    struct _NDR64_BOGUS_STRUCTURE_HEADER_FORMAT frag1;
    struct 
    {
        struct _NDR64_SIMPLE_REGION_FORMAT frag1;
        struct _NDR64_EMBEDDED_COMPLEX_FORMAT frag2;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag3;
    } frag2;
}
__midl_frag19_t;
extern const __midl_frag19_t __midl_frag19;

typedef 
struct _NDR64_USER_MARSHAL_FORMAT
__midl_frag17_t;
extern const __midl_frag17_t __midl_frag17;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag16_t;
extern const __midl_frag16_t __midl_frag16;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_PARAM_FORMAT frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
}
__midl_frag14_t;
extern const __midl_frag14_t __midl_frag14;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag11_t;
extern const __midl_frag11_t __midl_frag11;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_PARAM_FORMAT frag2;
    struct _NDR64_PARAM_FORMAT frag3;
}
__midl_frag10_t;
extern const __midl_frag10_t __midl_frag10;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag3_t;
extern const __midl_frag3_t __midl_frag3;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_PARAM_FORMAT frag2;
    struct _NDR64_PARAM_FORMAT frag3;
}
__midl_frag2_t;
extern const __midl_frag2_t __midl_frag2;

typedef 
NDR64_FORMAT_UINT32
__midl_frag1_t;
extern const __midl_frag1_t __midl_frag1;

static const __midl_frag167_t __midl_frag167 =
0x5    /* FC64_INT32 */;

static const __midl_frag166_t __midl_frag166 =
{ 
/* Reset */
    { 
    /* Reset */      /* procedure Reset */
        (NDR64_UINT32) 524611 /* 0x80143 */,    /* auto handle */ /* IsIntrepreted, [object], HasReturn */
        (NDR64_UINT32) 16 /* 0x10 */ ,  /* Stack size */
        (NDR64_UINT32) 0 /* 0x0 */,
        (NDR64_UINT32) 8 /* 0x8 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 1 /* 0x1 */,
        (NDR64_UINT16) 0 /* 0x0 */
    },
    { 
    /* HRESULT */      /* parameter HRESULT */
        &__midl_frag167,
        { 
        /* HRESULT */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    }
};

static const __midl_frag161_t __midl_frag161 =
{ 
/* *UINT */
    0x22,    /* FC64_OP */
    (NDR64_UINT8) 8 /* 0x8 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag167
};

static const __midl_frag158_t __midl_frag158 =
0x7    /* FC64_INT64 */;

static const __midl_frag157_t __midl_frag157 =
{ 
/* *ULONGLONG */
    0x22,    /* FC64_OP */
    (NDR64_UINT8) 8 /* 0x8 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag158
};

static const __midl_frag154_t __midl_frag154 =
0x4    /* FC64_INT16 */;

static const __midl_frag153_t __midl_frag153 =
{ 
/* *USHORT */
    0x22,    /* FC64_OP */
    (NDR64_UINT8) 8 /* 0x8 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag154
};

static const __midl_frag152_t __midl_frag152 =
0x10    /* FC64_CHAR */;

static const __midl_frag151_t __midl_frag151 =
{ 
/* *CHAR */
    0x22,    /* FC64_OP */
    (NDR64_UINT8) 8 /* 0x8 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag152
};

static const __midl_frag150_t __midl_frag150 =
{ 
/* *DECIMAL */
    0x22,    /* FC64_OP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag149
};

static const __midl_frag149_t __midl_frag149 =
{ 
/* DECIMAL */
    { 
    /* DECIMAL */
        0x30,    /* FC64_STRUCT */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* DECIMAL */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 16 /* 0x10 */
    }
};

static const __midl_frag142_t __midl_frag142 =
{ 
/* *_wireVARIANT */
    0x22,    /* FC64_OP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag19
};

static const __midl_frag141_t __midl_frag141 =
{ 
/* **_wireVARIANT */
    0x22,    /* FC64_OP */
    (NDR64_UINT8) 16 /* 0x10 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag142
};

static const __midl_frag140_t __midl_frag140 =
{ 
/* *_wireSAFEARRAY */
    0x22,    /* FC64_OP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag43
};

static const __midl_frag139_t __midl_frag139 =
{ 
/* **_wireSAFEARRAY */
    0x22,    /* FC64_OP */
    (NDR64_UINT8) 16 /* 0x10 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag140
};

static const __midl_frag138_t __midl_frag138 =
{ 
/* ***_wireSAFEARRAY */
    0x22,    /* FC64_OP */
    (NDR64_UINT8) 16 /* 0x10 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag139
};

static const __midl_frag137_t __midl_frag137 =
{ 
/* struct _NDR64_CONSTANT_IID_FORMAT */
    0x24,    /* FC64_IP */
    (NDR64_UINT8) 1 /* 0x1 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    {
        0x00020400,
        0x0000,
        0x0000,
        {0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46}
    }
};

static const __midl_frag136_t __midl_frag136 =
{ 
/* *struct _NDR64_POINTER_FORMAT */
    0x24,    /* FC64_IP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag137
};

static const __midl_frag135_t __midl_frag135 =
{ 
/* **struct _NDR64_POINTER_FORMAT */
    0x22,    /* FC64_OP */
    (NDR64_UINT8) 16 /* 0x10 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag136
};

static const __midl_frag134_t __midl_frag134 =
{ 
/* struct _NDR64_CONSTANT_IID_FORMAT */
    0x24,    /* FC64_IP */
    (NDR64_UINT8) 1 /* 0x1 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    {
        0x00000000,
        0x0000,
        0x0000,
        {0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46}
    }
};

static const __midl_frag133_t __midl_frag133 =
{ 
/* *struct _NDR64_POINTER_FORMAT */
    0x24,    /* FC64_IP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag134
};

static const __midl_frag132_t __midl_frag132 =
{ 
/* **struct _NDR64_POINTER_FORMAT */
    0x22,    /* FC64_OP */
    (NDR64_UINT8) 16 /* 0x10 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag133
};

static const __midl_frag131_t __midl_frag131 =
{ 
/* *FLAGGED_WORD_BLOB */
    0x22,    /* FC64_OP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag33
};

static const __midl_frag130_t __midl_frag130 =
{ 
/* **FLAGGED_WORD_BLOB */
    0x22,    /* FC64_OP */
    (NDR64_UINT8) 16 /* 0x10 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag131
};

static const __midl_frag129_t __midl_frag129 =
0xc    /* FC64_FLOAT64 */;

static const __midl_frag128_t __midl_frag128 =
{ 
/* *DATE */
    0x22,    /* FC64_OP */
    (NDR64_UINT8) 8 /* 0x8 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag129
};

static const __midl_frag127_t __midl_frag127 =
{ 
/* *CY */
    0x22,    /* FC64_OP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag30
};

static const __midl_frag120_t __midl_frag120 =
0xb    /* FC64_FLOAT32 */;

static const __midl_frag119_t __midl_frag119 =
{ 
/* *FLOAT */
    0x22,    /* FC64_OP */
    (NDR64_UINT8) 8 /* 0x8 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag120
};

static const __midl_frag112_t __midl_frag112 =
0x2    /* FC64_INT8 */;

static const __midl_frag111_t __midl_frag111 =
{ 
/* *BYTE */
    0x22,    /* FC64_OP */
    (NDR64_UINT8) 8 /* 0x8 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag112
};

static const __midl_frag110_t __midl_frag110 =
{ 
/* *_wireBRECORD */
    0x22,    /* FC64_OP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag75
};

static const __midl_frag109_t __midl_frag109 =
{ 
/*  */
    { 
    /* *hyper */
        0x22,    /* FC64_OP */
        (NDR64_UINT8) 32 /* 0x20 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        &__midl_frag106
    }
};

static const __midl_frag107_t __midl_frag107 =
{ 
/*  */
    (NDR64_UINT32) 1 /* 0x1 */,
    { 
    /* struct _NDR64_EXPR_VAR */
        0x3,    /* FC_EXPR_VAR */
        0x6,    /* FC64_UINT32 */
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT32) 0 /* 0x0 */
    }
};

static const __midl_frag106_t __midl_frag106 =
{ 
/* *hyper */
    { 
    /* *hyper */
        0x41,    /* FC64_CONF_ARRAY */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* *hyper */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 8 /* 0x8 */,
        &__midl_frag107
    },
    { 
    /* struct _NDR64_ARRAY_ELEMENT_INFO */
        (NDR64_UINT32) 8 /* 0x8 */,
        &__midl_frag158
    }
};

static const __midl_frag105_t __midl_frag105 =
{ 
/* HYPER_SIZEDARR */
    { 
    /* HYPER_SIZEDARR */
        0x35,    /* FC64_FORCED_BOGUS_STRUCT */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* HYPER_SIZEDARR */
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 16 /* 0x10 */,
        0,
        0,
        &__midl_frag109,
    },
    { 
    /*  */
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x5,    /* FC64_INT32 */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_MEMPAD_FORMAT */
            0x90,    /* FC64_STRUCTPADN */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 4 /* 0x4 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x14,    /* FC64_POINTER */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x93,    /* FC64_END */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        }
    }
};

static const __midl_frag104_t __midl_frag104 =
{ 
/*  */
    { 
    /* *ULONG */
        0x22,    /* FC64_OP */
        (NDR64_UINT8) 32 /* 0x20 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        &__midl_frag101
    }
};

static const __midl_frag101_t __midl_frag101 =
{ 
/* *ULONG */
    { 
    /* *ULONG */
        0x41,    /* FC64_CONF_ARRAY */
        (NDR64_UINT8) 3 /* 0x3 */,
        { 
        /* *ULONG */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 4 /* 0x4 */,
        &__midl_frag107
    },
    { 
    /* struct _NDR64_ARRAY_ELEMENT_INFO */
        (NDR64_UINT32) 4 /* 0x4 */,
        &__midl_frag167
    }
};

static const __midl_frag100_t __midl_frag100 =
{ 
/* DWORD_SIZEDARR */
    { 
    /* DWORD_SIZEDARR */
        0x35,    /* FC64_FORCED_BOGUS_STRUCT */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* DWORD_SIZEDARR */
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 16 /* 0x10 */,
        0,
        0,
        &__midl_frag104,
    },
    { 
    /*  */
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x5,    /* FC64_INT32 */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_MEMPAD_FORMAT */
            0x90,    /* FC64_STRUCTPADN */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 4 /* 0x4 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x14,    /* FC64_POINTER */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x93,    /* FC64_END */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        }
    }
};

static const __midl_frag99_t __midl_frag99 =
{ 
/*  */
    { 
    /* *short */
        0x22,    /* FC64_OP */
        (NDR64_UINT8) 32 /* 0x20 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        &__midl_frag96
    }
};

static const __midl_frag96_t __midl_frag96 =
{ 
/* *short */
    { 
    /* *short */
        0x41,    /* FC64_CONF_ARRAY */
        (NDR64_UINT8) 1 /* 0x1 */,
        { 
        /* *short */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 2 /* 0x2 */,
        &__midl_frag107
    },
    { 
    /* struct _NDR64_ARRAY_ELEMENT_INFO */
        (NDR64_UINT32) 2 /* 0x2 */,
        &__midl_frag154
    }
};

static const __midl_frag95_t __midl_frag95 =
{ 
/* WORD_SIZEDARR */
    { 
    /* WORD_SIZEDARR */
        0x35,    /* FC64_FORCED_BOGUS_STRUCT */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* WORD_SIZEDARR */
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 16 /* 0x10 */,
        0,
        0,
        &__midl_frag99,
    },
    { 
    /*  */
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x5,    /* FC64_INT32 */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_MEMPAD_FORMAT */
            0x90,    /* FC64_STRUCTPADN */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 4 /* 0x4 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x14,    /* FC64_POINTER */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x93,    /* FC64_END */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        }
    }
};

static const __midl_frag94_t __midl_frag94 =
{ 
/*  */
    { 
    /* *byte */
        0x22,    /* FC64_OP */
        (NDR64_UINT8) 32 /* 0x20 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        &__midl_frag91
    }
};

static const __midl_frag91_t __midl_frag91 =
{ 
/* *byte */
    { 
    /* *byte */
        0x41,    /* FC64_CONF_ARRAY */
        (NDR64_UINT8) 0 /* 0x0 */,
        { 
        /* *byte */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 1 /* 0x1 */,
        &__midl_frag107
    },
    { 
    /* struct _NDR64_ARRAY_ELEMENT_INFO */
        (NDR64_UINT32) 1 /* 0x1 */,
        &__midl_frag112
    }
};

static const __midl_frag90_t __midl_frag90 =
{ 
/* BYTE_SIZEDARR */
    { 
    /* BYTE_SIZEDARR */
        0x35,    /* FC64_FORCED_BOGUS_STRUCT */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* BYTE_SIZEDARR */
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 16 /* 0x10 */,
        0,
        0,
        &__midl_frag94,
    },
    { 
    /*  */
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x5,    /* FC64_INT32 */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_MEMPAD_FORMAT */
            0x90,    /* FC64_STRUCTPADN */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 4 /* 0x4 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x14,    /* FC64_POINTER */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x93,    /* FC64_END */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        }
    }
};

static const __midl_frag89_t __midl_frag89 =
{ 
/*  */
    { 
    /* struct _NDR64_FIX_ARRAY_HEADER_FORMAT */
        0x40,    /* FC64_FIX_ARRAY */
        (NDR64_UINT8) 0 /* 0x0 */,
        { 
        /* struct _NDR64_FIX_ARRAY_HEADER_FORMAT */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 8 /* 0x8 */
    }
};

static const __midl_frag88_t __midl_frag88 =
{ 
/*  */
    { 
    /* **struct _NDR64_POINTER_FORMAT */
        0x20,    /* FC64_RP */
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        &__midl_frag83
    }
};

static const __midl_frag83_t __midl_frag83 =
{ 
/* ** */
    { 
    /* **struct _NDR64_CONF_ARRAY_HEADER_FORMAT */
        0x41,    /* FC64_CONF_ARRAY */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* **struct _NDR64_CONF_ARRAY_HEADER_FORMAT */
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 8 /* 0x8 */,
        &__midl_frag107
    },
    { 
    /*  */
        { 
        /* struct _NDR64_REPEAT_FORMAT */
            0x82,    /* FC64_VARIABLE_REPEAT */
            { 
            /* struct _NDR64_REPEAT_FORMAT */
                (NDR64_UINT8) 0 /* 0x0 */,
                (NDR64_UINT8) 0 /* 0x0 */
            },
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 8 /* 0x8 */,
            (NDR64_UINT32) 0 /* 0x0 */,
            (NDR64_UINT32) 1 /* 0x1 */
        },
        { 
        /*  */
            { 
            /* struct _NDR64_POINTER_INSTANCE_HEADER_FORMAT */
                (NDR64_UINT32) 0 /* 0x0 */,
                (NDR64_UINT32) 0 /* 0x0 */
            },
            { 
            /* *struct _NDR64_POINTER_FORMAT */
                0x24,    /* FC64_IP */
                (NDR64_UINT8) 0 /* 0x0 */,
                (NDR64_UINT16) 0 /* 0x0 */,
                &__midl_frag134
            }
        },
        0x93    /* FC64_END */
    },
    { 
    /* struct _NDR64_ARRAY_ELEMENT_INFO */
        (NDR64_UINT32) 8 /* 0x8 */,
        &__midl_frag133
    }
};

static const __midl_frag82_t __midl_frag82 =
{ 
/* SAFEARR_HAVEIID */
    { 
    /* SAFEARR_HAVEIID */
        0x35,    /* FC64_FORCED_BOGUS_STRUCT */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* SAFEARR_HAVEIID */
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 32 /* 0x20 */,
        0,
        0,
        &__midl_frag88,
    },
    { 
    /*  */
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x5,    /* FC64_INT32 */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_MEMPAD_FORMAT */
            0x90,    /* FC64_STRUCTPADN */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 4 /* 0x4 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x14,    /* FC64_POINTER */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x5,    /* FC64_INT32 */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x4,    /* FC64_INT16 */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x4,    /* FC64_INT16 */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_EMBEDDED_COMPLEX_FORMAT */
            0x91,    /* FC64_EMBEDDED_COMPLEX */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            &__midl_frag89
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x93,    /* FC64_END */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        }
    }
};

static const __midl_frag81_t __midl_frag81 =
{ 
/*  */
    { 
    /* **_wireBRECORD */
        0x20,    /* FC64_RP */
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        &__midl_frag73
    }
};

static const __midl_frag78_t __midl_frag78 =
{ 
/*  */
    (NDR64_UINT32) 1 /* 0x1 */,
    { 
    /* struct _NDR64_EXPR_VAR */
        0x3,    /* FC_EXPR_VAR */
        0x6,    /* FC64_UINT32 */
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT32) 4 /* 0x4 */
    }
};

static const __midl_frag77_t __midl_frag77 =
{ 
/* *byte */
    { 
    /* *byte */
        0x41,    /* FC64_CONF_ARRAY */
        (NDR64_UINT8) 0 /* 0x0 */,
        { 
        /* *byte */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 1 /* 0x1 */,
        &__midl_frag78
    },
    { 
    /* struct _NDR64_ARRAY_ELEMENT_INFO */
        (NDR64_UINT32) 1 /* 0x1 */,
        &__midl_frag112
    }
};

static const __midl_frag76_t __midl_frag76 =
{ 
/* struct _NDR64_CONSTANT_IID_FORMAT */
    0x24,    /* FC64_IP */
    (NDR64_UINT8) 1 /* 0x1 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    {
        0x0000002f,
        0x0000,
        0x0000,
        {0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46}
    }
};

static const __midl_frag75_t __midl_frag75 =
{ 
/* _wireBRECORD */
    { 
    /* _wireBRECORD */
        0x31,    /* FC64_PSTRUCT */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* _wireBRECORD */
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 24 /* 0x18 */
    },
    { 
    /*  */
        { 
        /* struct _NDR64_NO_REPEAT_FORMAT */
            0x80,    /* FC64_NO_REPEAT */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_POINTER_INSTANCE_HEADER_FORMAT */
            (NDR64_UINT32) 8 /* 0x8 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* *struct _NDR64_POINTER_FORMAT */
            0x24,    /* FC64_IP */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            &__midl_frag76
        },
        { 
        /* struct _NDR64_NO_REPEAT_FORMAT */
            0x80,    /* FC64_NO_REPEAT */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_POINTER_INSTANCE_HEADER_FORMAT */
            (NDR64_UINT32) 16 /* 0x10 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* *byte */
            0x22,    /* FC64_OP */
            (NDR64_UINT8) 32 /* 0x20 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            &__midl_frag77
        },
        0x93    /* FC64_END */
    }
};

static const __midl_frag73_t __midl_frag73 =
{ 
/* **_wireBRECORD */
    { 
    /* **_wireBRECORD */
        0x41,    /* FC64_CONF_ARRAY */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* **_wireBRECORD */
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 8 /* 0x8 */,
        &__midl_frag107
    },
    { 
    /*  */
        { 
        /* struct _NDR64_REPEAT_FORMAT */
            0x82,    /* FC64_VARIABLE_REPEAT */
            { 
            /* struct _NDR64_REPEAT_FORMAT */
                (NDR64_UINT8) 0 /* 0x0 */,
                (NDR64_UINT8) 0 /* 0x0 */
            },
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 8 /* 0x8 */,
            (NDR64_UINT32) 0 /* 0x0 */,
            (NDR64_UINT32) 1 /* 0x1 */
        },
        { 
        /*  */
            { 
            /* struct _NDR64_POINTER_INSTANCE_HEADER_FORMAT */
                (NDR64_UINT32) 0 /* 0x0 */,
                (NDR64_UINT32) 0 /* 0x0 */
            },
            { 
            /* *_wireBRECORD */
                0x22,    /* FC64_OP */
                (NDR64_UINT8) 0 /* 0x0 */,
                (NDR64_UINT16) 0 /* 0x0 */,
                &__midl_frag75
            }
        },
        0x93    /* FC64_END */
    },
    { 
    /* struct _NDR64_ARRAY_ELEMENT_INFO */
        (NDR64_UINT32) 8 /* 0x8 */,
        &__midl_frag110
    }
};

static const __midl_frag72_t __midl_frag72 =
{ 
/* SAFEARR_BRECORD */
    { 
    /* SAFEARR_BRECORD */
        0x35,    /* FC64_FORCED_BOGUS_STRUCT */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* SAFEARR_BRECORD */
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 16 /* 0x10 */,
        0,
        0,
        &__midl_frag81,
    },
    { 
    /*  */
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x5,    /* FC64_INT32 */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_MEMPAD_FORMAT */
            0x90,    /* FC64_STRUCTPADN */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 4 /* 0x4 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x14,    /* FC64_POINTER */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x93,    /* FC64_END */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        }
    }
};

static const __midl_frag71_t __midl_frag71 =
{ 
/*  */
    { 
    /* **_wireVARIANT */
        0x20,    /* FC64_RP */
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        &__midl_frag68
    }
};

static const __midl_frag68_t __midl_frag68 =
{ 
/* **_wireVARIANT */
    { 
    /* **_wireVARIANT */
        0x41,    /* FC64_CONF_ARRAY */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* **_wireVARIANT */
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 8 /* 0x8 */,
        &__midl_frag107
    },
    { 
    /*  */
        { 
        /* struct _NDR64_REPEAT_FORMAT */
            0x82,    /* FC64_VARIABLE_REPEAT */
            { 
            /* struct _NDR64_REPEAT_FORMAT */
                (NDR64_UINT8) 0 /* 0x0 */,
                (NDR64_UINT8) 0 /* 0x0 */
            },
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 8 /* 0x8 */,
            (NDR64_UINT32) 0 /* 0x0 */,
            (NDR64_UINT32) 1 /* 0x1 */
        },
        { 
        /*  */
            { 
            /* struct _NDR64_POINTER_INSTANCE_HEADER_FORMAT */
                (NDR64_UINT32) 0 /* 0x0 */,
                (NDR64_UINT32) 0 /* 0x0 */
            },
            { 
            /* *_wireVARIANT */
                0x22,    /* FC64_OP */
                (NDR64_UINT8) 0 /* 0x0 */,
                (NDR64_UINT16) 0 /* 0x0 */,
                &__midl_frag19
            }
        },
        0x93    /* FC64_END */
    },
    { 
    /* struct _NDR64_ARRAY_ELEMENT_INFO */
        (NDR64_UINT32) 8 /* 0x8 */,
        &__midl_frag142
    }
};

static const __midl_frag67_t __midl_frag67 =
{ 
/* SAFEARR_VARIANT */
    { 
    /* SAFEARR_VARIANT */
        0x35,    /* FC64_FORCED_BOGUS_STRUCT */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* SAFEARR_VARIANT */
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 16 /* 0x10 */,
        0,
        0,
        &__midl_frag71,
    },
    { 
    /*  */
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x5,    /* FC64_INT32 */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_MEMPAD_FORMAT */
            0x90,    /* FC64_STRUCTPADN */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 4 /* 0x4 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x14,    /* FC64_POINTER */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x93,    /* FC64_END */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        }
    }
};

static const __midl_frag66_t __midl_frag66 =
{ 
/*  */
    { 
    /* **struct _NDR64_POINTER_FORMAT */
        0x20,    /* FC64_RP */
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        &__midl_frag61
    }
};

static const __midl_frag61_t __midl_frag61 =
{ 
/* ** */
    { 
    /* **struct _NDR64_CONF_ARRAY_HEADER_FORMAT */
        0x41,    /* FC64_CONF_ARRAY */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* **struct _NDR64_CONF_ARRAY_HEADER_FORMAT */
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 8 /* 0x8 */,
        &__midl_frag107
    },
    { 
    /*  */
        { 
        /* struct _NDR64_REPEAT_FORMAT */
            0x82,    /* FC64_VARIABLE_REPEAT */
            { 
            /* struct _NDR64_REPEAT_FORMAT */
                (NDR64_UINT8) 0 /* 0x0 */,
                (NDR64_UINT8) 0 /* 0x0 */
            },
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 8 /* 0x8 */,
            (NDR64_UINT32) 0 /* 0x0 */,
            (NDR64_UINT32) 1 /* 0x1 */
        },
        { 
        /*  */
            { 
            /* struct _NDR64_POINTER_INSTANCE_HEADER_FORMAT */
                (NDR64_UINT32) 0 /* 0x0 */,
                (NDR64_UINT32) 0 /* 0x0 */
            },
            { 
            /* *struct _NDR64_POINTER_FORMAT */
                0x24,    /* FC64_IP */
                (NDR64_UINT8) 0 /* 0x0 */,
                (NDR64_UINT16) 0 /* 0x0 */,
                &__midl_frag137
            }
        },
        0x93    /* FC64_END */
    },
    { 
    /* struct _NDR64_ARRAY_ELEMENT_INFO */
        (NDR64_UINT32) 8 /* 0x8 */,
        &__midl_frag136
    }
};

static const __midl_frag60_t __midl_frag60 =
{ 
/* SAFEARR_DISPATCH */
    { 
    /* SAFEARR_DISPATCH */
        0x35,    /* FC64_FORCED_BOGUS_STRUCT */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* SAFEARR_DISPATCH */
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 16 /* 0x10 */,
        0,
        0,
        &__midl_frag66,
    },
    { 
    /*  */
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x5,    /* FC64_INT32 */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_MEMPAD_FORMAT */
            0x90,    /* FC64_STRUCTPADN */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 4 /* 0x4 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x14,    /* FC64_POINTER */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x93,    /* FC64_END */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        }
    }
};

static const __midl_frag53_t __midl_frag53 =
{ 
/* SAFEARR_UNKNOWN */
    { 
    /* SAFEARR_UNKNOWN */
        0x35,    /* FC64_FORCED_BOGUS_STRUCT */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* SAFEARR_UNKNOWN */
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 16 /* 0x10 */,
        0,
        0,
        &__midl_frag88,
    },
    { 
    /*  */
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x5,    /* FC64_INT32 */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_MEMPAD_FORMAT */
            0x90,    /* FC64_STRUCTPADN */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 4 /* 0x4 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x14,    /* FC64_POINTER */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x93,    /* FC64_END */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        }
    }
};

static const __midl_frag52_t __midl_frag52 =
{ 
/*  */
    { 
    /* **FLAGGED_WORD_BLOB */
        0x20,    /* FC64_RP */
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        &__midl_frag49
    }
};

static const __midl_frag49_t __midl_frag49 =
{ 
/* **FLAGGED_WORD_BLOB */
    { 
    /* **FLAGGED_WORD_BLOB */
        0x41,    /* FC64_CONF_ARRAY */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* **FLAGGED_WORD_BLOB */
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 8 /* 0x8 */,
        &__midl_frag107
    },
    { 
    /*  */
        { 
        /* struct _NDR64_REPEAT_FORMAT */
            0x82,    /* FC64_VARIABLE_REPEAT */
            { 
            /* struct _NDR64_REPEAT_FORMAT */
                (NDR64_UINT8) 0 /* 0x0 */,
                (NDR64_UINT8) 0 /* 0x0 */
            },
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 8 /* 0x8 */,
            (NDR64_UINT32) 0 /* 0x0 */,
            (NDR64_UINT32) 1 /* 0x1 */
        },
        { 
        /*  */
            { 
            /* struct _NDR64_POINTER_INSTANCE_HEADER_FORMAT */
                (NDR64_UINT32) 0 /* 0x0 */,
                (NDR64_UINT32) 0 /* 0x0 */
            },
            { 
            /* *FLAGGED_WORD_BLOB */
                0x22,    /* FC64_OP */
                (NDR64_UINT8) 0 /* 0x0 */,
                (NDR64_UINT16) 0 /* 0x0 */,
                &__midl_frag33
            }
        },
        0x93    /* FC64_END */
    },
    { 
    /* struct _NDR64_ARRAY_ELEMENT_INFO */
        (NDR64_UINT32) 8 /* 0x8 */,
        &__midl_frag131
    }
};

static const __midl_frag48_t __midl_frag48 =
{ 
/* SAFEARR_BSTR */
    { 
    /* SAFEARR_BSTR */
        0x35,    /* FC64_FORCED_BOGUS_STRUCT */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* SAFEARR_BSTR */
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 16 /* 0x10 */,
        0,
        0,
        &__midl_frag52,
    },
    { 
    /*  */
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x5,    /* FC64_INT32 */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_MEMPAD_FORMAT */
            0x90,    /* FC64_STRUCTPADN */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 4 /* 0x4 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x14,    /* FC64_POINTER */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x93,    /* FC64_END */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        }
    }
};

static const __midl_frag47_t __midl_frag47 =
{ 
/* SAFEARRAYUNION */
    { 
    /* SAFEARRAYUNION */
        0x50,    /* FC64_ENCAPSULATED_UNION */
        (NDR64_UINT8) 7 /* 0x7 */,
        (NDR64_UINT8) 0 /* 0x0 */,
        0x6,    /* FC64_UINT32 */
        (NDR64_UINT32) 8 /* 0x8 */,
        (NDR64_UINT32) 40 /* 0x28 */,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM_SELECTOR */
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT8) 7 /* 0x7 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT32) 10 /* 0xa */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 8 /* 0x8 */,
        &__midl_frag48,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 13 /* 0xd */,
        &__midl_frag53,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 9 /* 0x9 */,
        &__midl_frag60,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 12 /* 0xc */,
        &__midl_frag67,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 36 /* 0x24 */,
        &__midl_frag72,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 32781 /* 0x800d */,
        &__midl_frag82,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16 /* 0x10 */,
        &__midl_frag90,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 2 /* 0x2 */,
        &__midl_frag95,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 3 /* 0x3 */,
        &__midl_frag100,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 20 /* 0x14 */,
        &__midl_frag105,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    (NDR64_UINT32) 4294967295 /* 0xffffffff */
};

static const __midl_frag46_t __midl_frag46 =
{ 
/* SAFEARRAYBOUND */
    { 
    /* SAFEARRAYBOUND */
        0x30,    /* FC64_STRUCT */
        (NDR64_UINT8) 3 /* 0x3 */,
        { 
        /* SAFEARRAYBOUND */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 8 /* 0x8 */
    }
};

static const __midl_frag45_t __midl_frag45 =
{ 
/*  */
    (NDR64_UINT32) 1 /* 0x1 */,
    { 
    /* struct _NDR64_EXPR_VAR */
        0x3,    /* FC_EXPR_VAR */
        0x3,    /* FC64_UINT16 */
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT32) 0 /* 0x0 */
    }
};

static const __midl_frag44_t __midl_frag44 =
{ 
/*  */
    { 
    /* struct _NDR64_CONF_ARRAY_HEADER_FORMAT */
        0x41,    /* FC64_CONF_ARRAY */
        (NDR64_UINT8) 3 /* 0x3 */,
        { 
        /* struct _NDR64_CONF_ARRAY_HEADER_FORMAT */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 8 /* 0x8 */,
        &__midl_frag45
    },
    { 
    /* struct _NDR64_ARRAY_ELEMENT_INFO */
        (NDR64_UINT32) 8 /* 0x8 */,
        &__midl_frag46
    }
};

static const __midl_frag43_t __midl_frag43 =
{ 
/* _wireSAFEARRAY */
    { 
    /* _wireSAFEARRAY */
        0x36,    /* FC64_CONF_BOGUS_STRUCT */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* _wireSAFEARRAY */
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 1 /* 0x1 */,
        (NDR64_UINT32) 56 /* 0x38 */,
        0,
        0,
        0,
        &__midl_frag44,
    },
    { 
    /*  */
        { 
        /* _wireSAFEARRAY */
            0x30,    /* FC64_STRUCT */
            (NDR64_UINT8) 1 /* 0x1 */,
            (NDR64_UINT16) 12 /* 0xc */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_MEMPAD_FORMAT */
            0x90,    /* FC64_STRUCTPADN */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 4 /* 0x4 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_EMBEDDED_COMPLEX_FORMAT */
            0x91,    /* FC64_EMBEDDED_COMPLEX */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            &__midl_frag47
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x93,    /* FC64_END */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        }
    }
};

static const __midl_frag34_t __midl_frag34 =
{ 
/*  */
    { 
    /* struct _NDR64_CONF_ARRAY_HEADER_FORMAT */
        0x41,    /* FC64_CONF_ARRAY */
        (NDR64_UINT8) 1 /* 0x1 */,
        { 
        /* struct _NDR64_CONF_ARRAY_HEADER_FORMAT */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 2 /* 0x2 */,
        &__midl_frag78
    },
    { 
    /* struct _NDR64_ARRAY_ELEMENT_INFO */
        (NDR64_UINT32) 2 /* 0x2 */,
        &__midl_frag154
    }
};

static const __midl_frag33_t __midl_frag33 =
{ 
/* FLAGGED_WORD_BLOB */
    { 
    /* FLAGGED_WORD_BLOB */
        0x32,    /* FC64_CONF_STRUCT */
        (NDR64_UINT8) 3 /* 0x3 */,
        { 
        /* FLAGGED_WORD_BLOB */
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 8 /* 0x8 */,
        &__midl_frag34
    }
};

static const __midl_frag30_t __midl_frag30 =
{ 
/* CY */
    { 
    /* CY */
        0x30,    /* FC64_STRUCT */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* CY */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 8 /* 0x8 */
    }
};

static const __midl_frag21_t __midl_frag21 =
{ 
/*  */
    (NDR64_UINT32) 1 /* 0x1 */,
    { 
    /* struct _NDR64_EXPR_VAR */
        0x3,    /* FC_EXPR_VAR */
        0x3,    /* FC64_UINT16 */
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT32) 8 /* 0x8 */
    }
};

static const __midl_frag20_t __midl_frag20 =
{ 
/* __MIDL_IOleAutomationTypes_0004 */
    { 
    /* __MIDL_IOleAutomationTypes_0004 */
        0x51,    /* FC64_NON_ENCAPSULATED_UNION */
        (NDR64_UINT8) 7 /* 0x7 */,
        (NDR64_UINT8) 0 /* 0x0 */,
        0x6,    /* FC64_UINT32 */
        (NDR64_UINT32) 16 /* 0x10 */,
        &__midl_frag21,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM_SELECTOR */
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT8) 7 /* 0x7 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT32) 47 /* 0x2f */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 20 /* 0x14 */,
        &__midl_frag158,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 3 /* 0x3 */,
        &__midl_frag167,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 17 /* 0x11 */,
        &__midl_frag112,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 2 /* 0x2 */,
        &__midl_frag154,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 4 /* 0x4 */,
        &__midl_frag120,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 5 /* 0x5 */,
        &__midl_frag129,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 11 /* 0xb */,
        &__midl_frag154,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 10 /* 0xa */,
        &__midl_frag167,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 6 /* 0x6 */,
        &__midl_frag30,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 7 /* 0x7 */,
        &__midl_frag129,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 8 /* 0x8 */,
        &__midl_frag131,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 13 /* 0xd */,
        &__midl_frag133,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 9 /* 0x9 */,
        &__midl_frag136,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 8192 /* 0x2000 */,
        &__midl_frag139,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 36 /* 0x24 */,
        &__midl_frag110,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16420 /* 0x4024 */,
        &__midl_frag110,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16401 /* 0x4011 */,
        &__midl_frag111,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16386 /* 0x4002 */,
        &__midl_frag153,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16387 /* 0x4003 */,
        &__midl_frag161,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16404 /* 0x4014 */,
        &__midl_frag157,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16388 /* 0x4004 */,
        &__midl_frag119,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16389 /* 0x4005 */,
        &__midl_frag128,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16395 /* 0x400b */,
        &__midl_frag153,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16394 /* 0x400a */,
        &__midl_frag161,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16390 /* 0x4006 */,
        &__midl_frag127,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16391 /* 0x4007 */,
        &__midl_frag128,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16392 /* 0x4008 */,
        &__midl_frag130,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16397 /* 0x400d */,
        &__midl_frag132,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16393 /* 0x4009 */,
        &__midl_frag135,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 24576 /* 0x6000 */,
        &__midl_frag138,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16396 /* 0x400c */,
        &__midl_frag141,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16 /* 0x10 */,
        &__midl_frag152,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 18 /* 0x12 */,
        &__midl_frag154,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 19 /* 0x13 */,
        &__midl_frag167,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 21 /* 0x15 */,
        &__midl_frag158,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 22 /* 0x16 */,
        &__midl_frag167,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 23 /* 0x17 */,
        &__midl_frag167,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 14 /* 0xe */,
        &__midl_frag149,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16398 /* 0x400e */,
        &__midl_frag150,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16400 /* 0x4010 */,
        &__midl_frag151,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16402 /* 0x4012 */,
        &__midl_frag153,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16403 /* 0x4013 */,
        &__midl_frag161,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16405 /* 0x4015 */,
        &__midl_frag157,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16406 /* 0x4016 */,
        &__midl_frag161,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 16407 /* 0x4017 */,
        &__midl_frag161,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 0 /* 0x0 */,
        0,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    { 
    /* struct _NDR64_UNION_ARM */
        (NDR64_INT64) 1 /* 0x1 */,
        0,
        (NDR64_UINT32) 0 /* 0x0 */
    },
    (NDR64_UINT32) 4294967295 /* 0xffffffff */
};

static const __midl_frag19_t __midl_frag19 =
{ 
/* _wireVARIANT */
    { 
    /* _wireVARIANT */
        0x34,    /* FC64_BOGUS_STRUCT */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* _wireVARIANT */
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 32 /* 0x20 */,
        0,
        0,
        0,
    },
    { 
    /*  */
        { 
        /* _wireVARIANT */
            0x30,    /* FC64_STRUCT */
            (NDR64_UINT8) 3 /* 0x3 */,
            (NDR64_UINT16) 16 /* 0x10 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_EMBEDDED_COMPLEX_FORMAT */
            0x91,    /* FC64_EMBEDDED_COMPLEX */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            &__midl_frag20
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x93,    /* FC64_END */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        }
    }
};

static const __midl_frag17_t __midl_frag17 =
{ 
/* wireVARIANT */
    0xa2,    /* FC64_USER_MARSHAL */
    (NDR64_UINT8) 128 /* 0x80 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    (NDR64_UINT16) 7 /* 0x7 */,
    (NDR64_UINT16) 8 /* 0x8 */,
    (NDR64_UINT32) 24 /* 0x18 */,
    (NDR64_UINT32) 0 /* 0x0 */,
    &__midl_frag142
};

static const __midl_frag16_t __midl_frag16 =
{ 
/* *wireVARIANT */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 4 /* 0x4 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag17
};

static const __midl_frag14_t __midl_frag14 =
{ 
/* get_RandBytes */
    { 
    /* get_RandBytes */      /* procedure get_RandBytes */
        (NDR64_UINT32) 4849987 /* 0x4a0143 */,    /* auto handle */ /* IsIntrepreted, [object], ServerMustSize, HasReturn, ClientCorrelation */
        (NDR64_UINT32) 32 /* 0x20 */ ,  /* Stack size */
        (NDR64_UINT32) 8 /* 0x8 */,
        (NDR64_UINT32) 8 /* 0x8 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 3 /* 0x3 */,
        (NDR64_UINT16) 0 /* 0x0 */
    },
    { 
    /* Length */      /* parameter Length */
        &__midl_frag167,
        { 
        /* Length */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    { 
    /* pVal */      /* parameter pVal */
        &__midl_frag17,
        { 
        /* pVal */
            1,
            1,
            0,
            0,
            1,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            1
        },    /* MustSize, MustFree, [out], SimpleRef, UseCache */
        (NDR64_UINT16) 0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    },
    { 
    /* HRESULT */      /* parameter HRESULT */
        &__midl_frag167,
        { 
        /* HRESULT */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        24 /* 0x18 */,   /* Stack offset */
    }
};

static const __midl_frag11_t __midl_frag11 =
{ 
/* *DOUBLE */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 12 /* 0xc */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag129
};

static const __midl_frag10_t __midl_frag10 =
{ 
/* get_RandNormal */
    { 
    /* get_RandNormal */      /* procedure get_RandNormal */
        (NDR64_UINT32) 524611 /* 0x80143 */,    /* auto handle */ /* IsIntrepreted, [object], HasReturn */
        (NDR64_UINT32) 24 /* 0x18 */ ,  /* Stack size */
        (NDR64_UINT32) 0 /* 0x0 */,
        (NDR64_UINT32) 48 /* 0x30 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 2 /* 0x2 */,
        (NDR64_UINT16) 0 /* 0x0 */
    },
    { 
    /* pVal */      /* parameter pVal */
        &__midl_frag129,
        { 
        /* pVal */
            0,
            0,
            0,
            0,
            1,
            0,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            1
        },    /* [out], Basetype, SimpleRef, UseCache */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    { 
    /* HRESULT */      /* parameter HRESULT */
        &__midl_frag167,
        { 
        /* HRESULT */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    }
};

static const __midl_frag3_t __midl_frag3 =
{ 
/* *LONG */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 12 /* 0xc */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag167
};

static const __midl_frag2_t __midl_frag2 =
{ 
/* get_RandInt32 */
    { 
    /* get_RandInt32 */      /* procedure get_RandInt32 */
        (NDR64_UINT32) 524611 /* 0x80143 */,    /* auto handle */ /* IsIntrepreted, [object], HasReturn */
        (NDR64_UINT32) 24 /* 0x18 */ ,  /* Stack size */
        (NDR64_UINT32) 0 /* 0x0 */,
        (NDR64_UINT32) 40 /* 0x28 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 2 /* 0x2 */,
        (NDR64_UINT16) 0 /* 0x0 */
    },
    { 
    /* pVal */      /* parameter pVal */
        &__midl_frag167,
        { 
        /* pVal */
            0,
            0,
            0,
            0,
            1,
            0,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            1
        },    /* [out], Basetype, SimpleRef, UseCache */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    { 
    /* HRESULT */      /* parameter HRESULT */
        &__midl_frag167,
        { 
        /* HRESULT */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    }
};

static const __midl_frag1_t __midl_frag1 =
(NDR64_UINT32) 0 /* 0x0 */;


#include "poppack.h"


static const USER_MARSHAL_ROUTINE_QUADRUPLE NDR64_UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            VARIANT_UserSize64
            ,VARIANT_UserMarshal64
            ,VARIANT_UserUnmarshal64
            ,VARIANT_UserFree64
            }

        };



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IQNG, ver. 0.0,
   GUID={0x49747D38,0xE3ED,0x4CA8,{0xBD,0x48,0xF2,0x83,0xD0,0xB4,0x68,0xFB}} */

#pragma code_seg(".orpc")
static const FormatInfoRef IQNG_Ndr64ProcTable[] =
    {
    (FormatInfoRef)(LONG_PTR) -1,
    (FormatInfoRef)(LONG_PTR) -1,
    (FormatInfoRef)(LONG_PTR) -1,
    (FormatInfoRef)(LONG_PTR) -1,
    &__midl_frag2,
    &__midl_frag10,
    &__midl_frag10,
    &__midl_frag14,
    &__midl_frag166,
    &__midl_frag166
    };


static const MIDL_SYNTAX_INFO IQNG_SyntaxInfo [  2 ] = 
    {
    {
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    0,
    QWQNG__MIDL_ProcFormatString.Format,
    &IQNG_FormatStringOffsetTable[-3],
    QWQNG__MIDL_TypeFormatString.Format,
    UserMarshalRoutines,
    0,
    0
    }
    ,{
    {{0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0}},
    0,
    0 ,
    (unsigned short *) &IQNG_Ndr64ProcTable[-3],
    0,
    NDR64_UserMarshalRoutines,
    0,
    0
    }
    };

static const MIDL_STUBLESS_PROXY_INFO IQNG_ProxyInfo =
    {
    &Object_StubDesc,
    QWQNG__MIDL_ProcFormatString.Format,
    &IQNG_FormatStringOffsetTable[-3],
    (RPC_SYNTAX_IDENTIFIER*)&_RpcTransferSyntax,
    2,
    (MIDL_SYNTAX_INFO*)IQNG_SyntaxInfo
    
    };


static const MIDL_SERVER_INFO IQNG_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    QWQNG__MIDL_ProcFormatString.Format,
    (unsigned short *) &IQNG_FormatStringOffsetTable[-3],
    0,
    (RPC_SYNTAX_IDENTIFIER*)&_NDR64_RpcTransferSyntax,
    2,
    (MIDL_SYNTAX_INFO*)IQNG_SyntaxInfo
    };
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
    NdrStubCall3,
    NdrStubCall3,
    NdrStubCall3,
    NdrStubCall3,
    NdrStubCall3,
    NdrStubCall3
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
    0x2000001, /* MIDL flag */
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
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/

