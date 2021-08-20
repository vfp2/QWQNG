
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 6.00.0347 */
/* at Sat Nov 09 17:08:41 2002
 */
/* Compiler settings for QWQNG.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if !defined(_M_IA64) && !defined(_M_AMD64)
#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 440
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "QWQNG.h"

#define TYPE_FORMAT_STRING_SIZE   1017                              
#define PROC_FORMAT_STRING_SIZE   163                               
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   1            

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IQNG_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IQNG_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub because it uses these features:
#error   -Oif or -Oicf, [wire_marshal] or [user_marshal] attribute.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
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
/* 14 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 16 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 18 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 20 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 22 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 24 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 26 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RandUniform */

/* 28 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 30 */	NdrFcLong( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0x8 ),	/* 8 */
/* 36 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 38 */	NdrFcShort( 0x0 ),	/* 0 */
/* 40 */	NdrFcShort( 0x2c ),	/* 44 */
/* 42 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 44 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 46 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 48 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 50 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 52 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 54 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RandNormal */

/* 56 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 58 */	NdrFcLong( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x9 ),	/* 9 */
/* 64 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 66 */	NdrFcShort( 0x0 ),	/* 0 */
/* 68 */	NdrFcShort( 0x2c ),	/* 44 */
/* 70 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 72 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 74 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 76 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 78 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 80 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 82 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RandBytes */

/* 84 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 86 */	NdrFcLong( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0xa ),	/* 10 */
/* 92 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 94 */	NdrFcShort( 0x8 ),	/* 8 */
/* 96 */	NdrFcShort( 0x8 ),	/* 8 */
/* 98 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x3,		/* 3 */

	/* Parameter Length */

/* 100 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 102 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 106 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 108 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 110 */	NdrFcShort( 0x3ee ),	/* Type Offset=1006 */

	/* Return value */

/* 112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 114 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clear */

/* 118 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0xb ),	/* 11 */
/* 126 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 132 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 134 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 136 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Reset */

/* 140 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 142 */	NdrFcLong( 0x0 ),	/* 0 */
/* 146 */	NdrFcShort( 0xc ),	/* 12 */
/* 148 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 152 */	NdrFcShort( 0x8 ),	/* 8 */
/* 154 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 156 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 158 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 160 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
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
/* 12 */	NdrFcShort( 0x3e2 ),	/* Offset= 994 (1006) */
/* 14 */	
			0x13, 0x0,	/* FC_OP */
/* 16 */	NdrFcShort( 0x3ca ),	/* Offset= 970 (986) */
/* 18 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 20 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 22 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 24 */	NdrFcShort( 0x2 ),	/* Offset= 2 (26) */
/* 26 */	NdrFcShort( 0x10 ),	/* 16 */
/* 28 */	NdrFcShort( 0x2f ),	/* 47 */
/* 30 */	NdrFcLong( 0x14 ),	/* 20 */
/* 34 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 36 */	NdrFcLong( 0x3 ),	/* 3 */
/* 40 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 42 */	NdrFcLong( 0x11 ),	/* 17 */
/* 46 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 48 */	NdrFcLong( 0x2 ),	/* 2 */
/* 52 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 54 */	NdrFcLong( 0x4 ),	/* 4 */
/* 58 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 60 */	NdrFcLong( 0x5 ),	/* 5 */
/* 64 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 66 */	NdrFcLong( 0xb ),	/* 11 */
/* 70 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 72 */	NdrFcLong( 0xa ),	/* 10 */
/* 76 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 78 */	NdrFcLong( 0x6 ),	/* 6 */
/* 82 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (314) */
/* 84 */	NdrFcLong( 0x7 ),	/* 7 */
/* 88 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 90 */	NdrFcLong( 0x8 ),	/* 8 */
/* 94 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (320) */
/* 96 */	NdrFcLong( 0xd ),	/* 13 */
/* 100 */	NdrFcShort( 0xf4 ),	/* Offset= 244 (344) */
/* 102 */	NdrFcLong( 0x9 ),	/* 9 */
/* 106 */	NdrFcShort( 0x100 ),	/* Offset= 256 (362) */
/* 108 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 112 */	NdrFcShort( 0x10c ),	/* Offset= 268 (380) */
/* 114 */	NdrFcLong( 0x24 ),	/* 36 */
/* 118 */	NdrFcShort( 0x31a ),	/* Offset= 794 (912) */
/* 120 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 124 */	NdrFcShort( 0x314 ),	/* Offset= 788 (912) */
/* 126 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 130 */	NdrFcShort( 0x312 ),	/* Offset= 786 (916) */
/* 132 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 136 */	NdrFcShort( 0x310 ),	/* Offset= 784 (920) */
/* 138 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 142 */	NdrFcShort( 0x30e ),	/* Offset= 782 (924) */
/* 144 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 148 */	NdrFcShort( 0x30c ),	/* Offset= 780 (928) */
/* 150 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 154 */	NdrFcShort( 0x30a ),	/* Offset= 778 (932) */
/* 156 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 160 */	NdrFcShort( 0x308 ),	/* Offset= 776 (936) */
/* 162 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 166 */	NdrFcShort( 0x2f2 ),	/* Offset= 754 (920) */
/* 168 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 172 */	NdrFcShort( 0x2f0 ),	/* Offset= 752 (924) */
/* 174 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 178 */	NdrFcShort( 0x2fa ),	/* Offset= 762 (940) */
/* 180 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 184 */	NdrFcShort( 0x2f0 ),	/* Offset= 752 (936) */
/* 186 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 190 */	NdrFcShort( 0x2f2 ),	/* Offset= 754 (944) */
/* 192 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 196 */	NdrFcShort( 0x2f0 ),	/* Offset= 752 (948) */
/* 198 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 202 */	NdrFcShort( 0x2ee ),	/* Offset= 750 (952) */
/* 204 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 208 */	NdrFcShort( 0x2ec ),	/* Offset= 748 (956) */
/* 210 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 214 */	NdrFcShort( 0x2ea ),	/* Offset= 746 (960) */
/* 216 */	NdrFcLong( 0x10 ),	/* 16 */
/* 220 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 222 */	NdrFcLong( 0x12 ),	/* 18 */
/* 226 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 228 */	NdrFcLong( 0x13 ),	/* 19 */
/* 232 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 234 */	NdrFcLong( 0x15 ),	/* 21 */
/* 238 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 240 */	NdrFcLong( 0x16 ),	/* 22 */
/* 244 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 246 */	NdrFcLong( 0x17 ),	/* 23 */
/* 250 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 252 */	NdrFcLong( 0xe ),	/* 14 */
/* 256 */	NdrFcShort( 0x2c8 ),	/* Offset= 712 (968) */
/* 258 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 262 */	NdrFcShort( 0x2cc ),	/* Offset= 716 (978) */
/* 264 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 268 */	NdrFcShort( 0x2ca ),	/* Offset= 714 (982) */
/* 270 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 274 */	NdrFcShort( 0x286 ),	/* Offset= 646 (920) */
/* 276 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 280 */	NdrFcShort( 0x284 ),	/* Offset= 644 (924) */
/* 282 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 286 */	NdrFcShort( 0x282 ),	/* Offset= 642 (928) */
/* 288 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 292 */	NdrFcShort( 0x278 ),	/* Offset= 632 (924) */
/* 294 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 298 */	NdrFcShort( 0x272 ),	/* Offset= 626 (924) */
/* 300 */	NdrFcLong( 0x0 ),	/* 0 */
/* 304 */	NdrFcShort( 0x0 ),	/* Offset= 0 (304) */
/* 306 */	NdrFcLong( 0x1 ),	/* 1 */
/* 310 */	NdrFcShort( 0x0 ),	/* Offset= 0 (310) */
/* 312 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (311) */
/* 314 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 316 */	NdrFcShort( 0x8 ),	/* 8 */
/* 318 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 320 */	
			0x13, 0x0,	/* FC_OP */
/* 322 */	NdrFcShort( 0xc ),	/* Offset= 12 (334) */
/* 324 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 326 */	NdrFcShort( 0x2 ),	/* 2 */
/* 328 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 330 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 332 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 334 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 336 */	NdrFcShort( 0x8 ),	/* 8 */
/* 338 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (324) */
/* 340 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 342 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 344 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 346 */	NdrFcLong( 0x0 ),	/* 0 */
/* 350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 354 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 356 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 358 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 360 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 362 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 364 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 372 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 374 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 376 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 378 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 380 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 382 */	NdrFcShort( 0x2 ),	/* Offset= 2 (384) */
/* 384 */	
			0x13, 0x0,	/* FC_OP */
/* 386 */	NdrFcShort( 0x1fc ),	/* Offset= 508 (894) */
/* 388 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 390 */	NdrFcShort( 0x18 ),	/* 24 */
/* 392 */	NdrFcShort( 0xa ),	/* 10 */
/* 394 */	NdrFcLong( 0x8 ),	/* 8 */
/* 398 */	NdrFcShort( 0x58 ),	/* Offset= 88 (486) */
/* 400 */	NdrFcLong( 0xd ),	/* 13 */
/* 404 */	NdrFcShort( 0x78 ),	/* Offset= 120 (524) */
/* 406 */	NdrFcLong( 0x9 ),	/* 9 */
/* 410 */	NdrFcShort( 0x94 ),	/* Offset= 148 (558) */
/* 412 */	NdrFcLong( 0xc ),	/* 12 */
/* 416 */	NdrFcShort( 0xbc ),	/* Offset= 188 (604) */
/* 418 */	NdrFcLong( 0x24 ),	/* 36 */
/* 422 */	NdrFcShort( 0x114 ),	/* Offset= 276 (698) */
/* 424 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 428 */	NdrFcShort( 0x130 ),	/* Offset= 304 (732) */
/* 430 */	NdrFcLong( 0x10 ),	/* 16 */
/* 434 */	NdrFcShort( 0x148 ),	/* Offset= 328 (762) */
/* 436 */	NdrFcLong( 0x2 ),	/* 2 */
/* 440 */	NdrFcShort( 0x160 ),	/* Offset= 352 (792) */
/* 442 */	NdrFcLong( 0x3 ),	/* 3 */
/* 446 */	NdrFcShort( 0x178 ),	/* Offset= 376 (822) */
/* 448 */	NdrFcLong( 0x14 ),	/* 20 */
/* 452 */	NdrFcShort( 0x190 ),	/* Offset= 400 (852) */
/* 454 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (453) */
/* 456 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 458 */	NdrFcShort( 0x4 ),	/* 4 */
/* 460 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 464 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 466 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 468 */	NdrFcShort( 0x4 ),	/* 4 */
/* 470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 472 */	NdrFcShort( 0x1 ),	/* 1 */
/* 474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 478 */	0x13, 0x0,	/* FC_OP */
/* 480 */	NdrFcShort( 0xffffff6e ),	/* Offset= -146 (334) */
/* 482 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 484 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 486 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 488 */	NdrFcShort( 0x8 ),	/* 8 */
/* 490 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 492 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 494 */	NdrFcShort( 0x4 ),	/* 4 */
/* 496 */	NdrFcShort( 0x4 ),	/* 4 */
/* 498 */	0x11, 0x0,	/* FC_RP */
/* 500 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (456) */
/* 502 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 504 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 506 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 510 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 514 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 518 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 520 */	NdrFcShort( 0xffffff50 ),	/* Offset= -176 (344) */
/* 522 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 524 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 526 */	NdrFcShort( 0x8 ),	/* 8 */
/* 528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 530 */	NdrFcShort( 0x6 ),	/* Offset= 6 (536) */
/* 532 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 534 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 536 */	
			0x11, 0x0,	/* FC_RP */
/* 538 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (506) */
/* 540 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 544 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 548 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 552 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 554 */	NdrFcShort( 0xffffff40 ),	/* Offset= -192 (362) */
/* 556 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 558 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 560 */	NdrFcShort( 0x8 ),	/* 8 */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 564 */	NdrFcShort( 0x6 ),	/* Offset= 6 (570) */
/* 566 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 568 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 570 */	
			0x11, 0x0,	/* FC_RP */
/* 572 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (540) */
/* 574 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 576 */	NdrFcShort( 0x4 ),	/* 4 */
/* 578 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 582 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 584 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 586 */	NdrFcShort( 0x4 ),	/* 4 */
/* 588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 590 */	NdrFcShort( 0x1 ),	/* 1 */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 596 */	0x13, 0x0,	/* FC_OP */
/* 598 */	NdrFcShort( 0x184 ),	/* Offset= 388 (986) */
/* 600 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 602 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 604 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 606 */	NdrFcShort( 0x8 ),	/* 8 */
/* 608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 610 */	NdrFcShort( 0x6 ),	/* Offset= 6 (616) */
/* 612 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 614 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 616 */	
			0x11, 0x0,	/* FC_RP */
/* 618 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (574) */
/* 620 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 622 */	NdrFcLong( 0x2f ),	/* 47 */
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 630 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 632 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 634 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 636 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 638 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 640 */	NdrFcShort( 0x1 ),	/* 1 */
/* 642 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 644 */	NdrFcShort( 0x4 ),	/* 4 */
/* 646 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 648 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 650 */	NdrFcShort( 0x10 ),	/* 16 */
/* 652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 654 */	NdrFcShort( 0xa ),	/* Offset= 10 (664) */
/* 656 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 658 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 660 */	NdrFcShort( 0xffffffd8 ),	/* Offset= -40 (620) */
/* 662 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 664 */	
			0x13, 0x0,	/* FC_OP */
/* 666 */	NdrFcShort( 0xffffffe4 ),	/* Offset= -28 (638) */
/* 668 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 670 */	NdrFcShort( 0x4 ),	/* 4 */
/* 672 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 676 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 678 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 680 */	NdrFcShort( 0x4 ),	/* 4 */
/* 682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 684 */	NdrFcShort( 0x1 ),	/* 1 */
/* 686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 690 */	0x13, 0x0,	/* FC_OP */
/* 692 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (648) */
/* 694 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 696 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 698 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 700 */	NdrFcShort( 0x8 ),	/* 8 */
/* 702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 704 */	NdrFcShort( 0x6 ),	/* Offset= 6 (710) */
/* 706 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 708 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 710 */	
			0x11, 0x0,	/* FC_RP */
/* 712 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (668) */
/* 714 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 716 */	NdrFcShort( 0x8 ),	/* 8 */
/* 718 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 720 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 722 */	NdrFcShort( 0x10 ),	/* 16 */
/* 724 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 726 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 728 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffff1 ),	/* Offset= -15 (714) */
			0x5b,		/* FC_END */
/* 732 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 734 */	NdrFcShort( 0x18 ),	/* 24 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	NdrFcShort( 0xa ),	/* Offset= 10 (748) */
/* 740 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 742 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 744 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (720) */
/* 746 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 748 */	
			0x11, 0x0,	/* FC_RP */
/* 750 */	NdrFcShort( 0xffffff0c ),	/* Offset= -244 (506) */
/* 752 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 754 */	NdrFcShort( 0x1 ),	/* 1 */
/* 756 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 760 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 762 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 764 */	NdrFcShort( 0x8 ),	/* 8 */
/* 766 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 768 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 770 */	NdrFcShort( 0x4 ),	/* 4 */
/* 772 */	NdrFcShort( 0x4 ),	/* 4 */
/* 774 */	0x13, 0x0,	/* FC_OP */
/* 776 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (752) */
/* 778 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 780 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 782 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 784 */	NdrFcShort( 0x2 ),	/* 2 */
/* 786 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 790 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 792 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 794 */	NdrFcShort( 0x8 ),	/* 8 */
/* 796 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 798 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 800 */	NdrFcShort( 0x4 ),	/* 4 */
/* 802 */	NdrFcShort( 0x4 ),	/* 4 */
/* 804 */	0x13, 0x0,	/* FC_OP */
/* 806 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (782) */
/* 808 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 810 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 812 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 814 */	NdrFcShort( 0x4 ),	/* 4 */
/* 816 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 820 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 822 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 824 */	NdrFcShort( 0x8 ),	/* 8 */
/* 826 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 828 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 830 */	NdrFcShort( 0x4 ),	/* 4 */
/* 832 */	NdrFcShort( 0x4 ),	/* 4 */
/* 834 */	0x13, 0x0,	/* FC_OP */
/* 836 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (812) */
/* 838 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 840 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 842 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 844 */	NdrFcShort( 0x8 ),	/* 8 */
/* 846 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 850 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 852 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 854 */	NdrFcShort( 0x8 ),	/* 8 */
/* 856 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 858 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 860 */	NdrFcShort( 0x4 ),	/* 4 */
/* 862 */	NdrFcShort( 0x4 ),	/* 4 */
/* 864 */	0x13, 0x0,	/* FC_OP */
/* 866 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (842) */
/* 868 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 870 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 872 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 874 */	NdrFcShort( 0x8 ),	/* 8 */
/* 876 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 878 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 880 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 882 */	NdrFcShort( 0x8 ),	/* 8 */
/* 884 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 886 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 888 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 890 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (872) */
/* 892 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 894 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 896 */	NdrFcShort( 0x28 ),	/* 40 */
/* 898 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (880) */
/* 900 */	NdrFcShort( 0x0 ),	/* Offset= 0 (900) */
/* 902 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 904 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 906 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 908 */	NdrFcShort( 0xfffffdf8 ),	/* Offset= -520 (388) */
/* 910 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 912 */	
			0x13, 0x0,	/* FC_OP */
/* 914 */	NdrFcShort( 0xfffffef6 ),	/* Offset= -266 (648) */
/* 916 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 918 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 920 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 922 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 924 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 926 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 928 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 930 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 932 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 934 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 936 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 938 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 940 */	
			0x13, 0x0,	/* FC_OP */
/* 942 */	NdrFcShort( 0xfffffd8c ),	/* Offset= -628 (314) */
/* 944 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 946 */	NdrFcShort( 0xfffffd8e ),	/* Offset= -626 (320) */
/* 948 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 950 */	NdrFcShort( 0xfffffda2 ),	/* Offset= -606 (344) */
/* 952 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 954 */	NdrFcShort( 0xfffffdb0 ),	/* Offset= -592 (362) */
/* 956 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 958 */	NdrFcShort( 0xfffffdbe ),	/* Offset= -578 (380) */
/* 960 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 962 */	NdrFcShort( 0x2 ),	/* Offset= 2 (964) */
/* 964 */	
			0x13, 0x0,	/* FC_OP */
/* 966 */	NdrFcShort( 0x14 ),	/* Offset= 20 (986) */
/* 968 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 970 */	NdrFcShort( 0x10 ),	/* 16 */
/* 972 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 974 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 976 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 978 */	
			0x13, 0x0,	/* FC_OP */
/* 980 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (968) */
/* 982 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 984 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 986 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 988 */	NdrFcShort( 0x20 ),	/* 32 */
/* 990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 992 */	NdrFcShort( 0x0 ),	/* Offset= 0 (992) */
/* 994 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 996 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 998 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1000 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1002 */	NdrFcShort( 0xfffffc28 ),	/* Offset= -984 (18) */
/* 1004 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1006 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1010 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1014 */	NdrFcShort( 0xfffffc18 ),	/* Offset= -1000 (14) */

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
    28,
    56,
    84,
    118,
    140
    };

static const MIDL_STUBLESS_PROXY_INFO IQNG_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IQNG_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IQNG_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
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
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
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
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x600015b, /* MIDL Version 6.0.347 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0   /* Reserved5 */
    };

const CInterfaceProxyVtbl * _QWQNG_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IQNGProxyVtbl,
    0
};

const CInterfaceStubVtbl * _QWQNG_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IQNGStubVtbl,
    0
};

PCInterfaceName const _QWQNG_InterfaceNamesList[] = 
{
    "IQNG",
    0
};

const IID *  _QWQNG_BaseIIDList[] = 
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


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

