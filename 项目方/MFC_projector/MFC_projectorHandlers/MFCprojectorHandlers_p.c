

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for MFCprojectorHandlers.idl:
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


#include "MFCprojectorHandlers_i.h"

#define TYPE_FORMAT_STRING_SIZE   3                                 
#define PROC_FORMAT_STRING_SIZE   1                                 
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _MFCprojectorHandlers_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MFCprojectorHandlers_MIDL_TYPE_FORMAT_STRING;

typedef struct _MFCprojectorHandlers_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MFCprojectorHandlers_MIDL_PROC_FORMAT_STRING;

typedef struct _MFCprojectorHandlers_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } MFCprojectorHandlers_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const MFCprojectorHandlers_MIDL_TYPE_FORMAT_STRING MFCprojectorHandlers__MIDL_TypeFormatString;
extern const MFCprojectorHandlers_MIDL_PROC_FORMAT_STRING MFCprojectorHandlers__MIDL_ProcFormatString;
extern const MFCprojectorHandlers_MIDL_EXPR_FORMAT_STRING MFCprojectorHandlers__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IPreview_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IPreview_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IThumbnail_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IThumbnail_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISearch_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ISearch_ProxyInfo;



#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif
#if !(TARGET_IS_NT60_OR_LATER)
#error You need Windows Vista or later to run this stub because it uses these features:
#error   forced complex structure or array, compiled for Windows Vista.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MFCprojectorHandlers_MIDL_PROC_FORMAT_STRING MFCprojectorHandlers__MIDL_ProcFormatString =
    {
        0,
        {

			0x0
        }
    };

static const MFCprojectorHandlers_MIDL_TYPE_FORMAT_STRING MFCprojectorHandlers__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IPreview, ver. 0.0,
   GUID={0x6103e95c,0xeac6,0x4168,{0xbf,0x09,0x6c,0xe1,0xe3,0x64,0x28,0x13}} */

#pragma code_seg(".orpc")
static const unsigned short IPreview_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IPreview_ProxyInfo =
    {
    &Object_StubDesc,
    MFCprojectorHandlers__MIDL_ProcFormatString.Format,
    &IPreview_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IPreview_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    MFCprojectorHandlers__MIDL_ProcFormatString.Format,
    &IPreview_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(3) _IPreviewProxyVtbl = 
{
    0,
    &IID_IPreview,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy
};

const CInterfaceStubVtbl _IPreviewStubVtbl =
{
    &IID_IPreview,
    &IPreview_ServerInfo,
    3,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IThumbnail, ver. 0.0,
   GUID={0x91a04f4b,0xf299,0x448d,{0x8b,0xf5,0x34,0x7f,0xf2,0xb5,0x14,0x8c}} */

#pragma code_seg(".orpc")
static const unsigned short IThumbnail_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IThumbnail_ProxyInfo =
    {
    &Object_StubDesc,
    MFCprojectorHandlers__MIDL_ProcFormatString.Format,
    &IThumbnail_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IThumbnail_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    MFCprojectorHandlers__MIDL_ProcFormatString.Format,
    &IThumbnail_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(3) _IThumbnailProxyVtbl = 
{
    0,
    &IID_IThumbnail,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy
};

const CInterfaceStubVtbl _IThumbnailStubVtbl =
{
    &IID_IThumbnail,
    &IThumbnail_ServerInfo,
    3,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ISearch, ver. 0.0,
   GUID={0x67a4af73,0x200a,0x47fd,{0xb8,0x20,0x0f,0x2f,0x53,0xf4,0x24,0x13}} */

#pragma code_seg(".orpc")
static const unsigned short ISearch_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ISearch_ProxyInfo =
    {
    &Object_StubDesc,
    MFCprojectorHandlers__MIDL_ProcFormatString.Format,
    &ISearch_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ISearch_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    MFCprojectorHandlers__MIDL_ProcFormatString.Format,
    &ISearch_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(3) _ISearchProxyVtbl = 
{
    0,
    &IID_ISearch,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy
};

const CInterfaceStubVtbl _ISearchStubVtbl =
{
    &IID_ISearch,
    &ISearch_ServerInfo,
    3,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
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
    MFCprojectorHandlers__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x60001, /* Ndr library version */
    0,
    0x801026e, /* MIDL Version 8.1.622 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _MFCprojectorHandlers_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IThumbnailProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IPreviewProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISearchProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _MFCprojectorHandlers_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IThumbnailStubVtbl,
    ( CInterfaceStubVtbl *) &_IPreviewStubVtbl,
    ( CInterfaceStubVtbl *) &_ISearchStubVtbl,
    0
};

PCInterfaceName const _MFCprojectorHandlers_InterfaceNamesList[] = 
{
    "IThumbnail",
    "IPreview",
    "ISearch",
    0
};


#define _MFCprojectorHandlers_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _MFCprojectorHandlers, pIID, n)

int __stdcall _MFCprojectorHandlers_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _MFCprojectorHandlers, 3, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _MFCprojectorHandlers, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _MFCprojectorHandlers, 3, *pIndex )
    
}

const ExtendedProxyFileInfo MFCprojectorHandlers_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _MFCprojectorHandlers_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _MFCprojectorHandlers_StubVtblList,
    (const PCInterfaceName * ) & _MFCprojectorHandlers_InterfaceNamesList,
    0, /* no delegation */
    & _MFCprojectorHandlers_IID_Lookup, 
    3,
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

