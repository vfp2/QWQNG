// QNG.h : Declaration of the CQNG
#pragma once
#include "resource.h"       // main symbols
#include <atlctl.h>
#include "QWQNG.h"
#include "Device.h"
#include "DummyDevice.h"

// CQNG
class ATL_NO_VTABLE CQNG : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IQNG, &IID_IQNG, &LIBID_QWQNG, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IPersistStreamInitImpl<CQNG>,
	public IOleControlImpl<CQNG>,
	public IOleObjectImpl<CQNG>,
	public IOleInPlaceActiveObjectImpl<CQNG>,
	public IViewObjectExImpl<CQNG>,
	public IOleInPlaceObjectWindowlessImpl<CQNG>,
	public ISupportErrorInfo,
	public IObjectWithSiteImpl<CQNG>,
	public IServiceProviderImpl<CQNG>,
	public IPersistStorageImpl<CQNG>,
	public IQuickActivateImpl<CQNG>,
	public IProvideClassInfo2Impl<&CLSID_QNG, NULL, &LIBID_QWQNG>,
	public CComCoClass<CQNG, &CLSID_QNG>,
	public CComControl<CQNG>
{
public:

	CQNG()
		: pDevice(NULL)
	{
	}

DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE | 
	OLEMISC_INVISIBLEATRUNTIME |
	OLEMISC_CANTLINKINSIDE | 
	OLEMISC_INSIDEOUT | 
	OLEMISC_ACTIVATEWHENVISIBLE | 
	OLEMISC_SETCLIENTSITEFIRST
)

DECLARE_REGISTRY_RESOURCEID(IDR_QNG)

BEGIN_COM_MAP(CQNG)
	COM_INTERFACE_ENTRY(IQNG)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	COM_INTERFACE_ENTRY(IServiceProvider)
END_COM_MAP()

BEGIN_PROP_MAP(CQNG)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()


BEGIN_MSG_MAP(CQNG)
	CHAIN_MSG_MAP(CComControl<CQNG>)
	DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid)
	{
		static const IID* arr[] = 
		{
			&IID_IQNG,
		};

		for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
		{
			if (InlineIsEqualGUID(*arr[i], riid))
				return S_OK;
		}
		return S_FALSE;
	}

// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IQNG
public:
	HRESULT OnDraw(ATL_DRAWINFO& di)
	{
		// draws an icon at design time
		static HICON hIcon = NULL;
		RECT& rc = *(RECT*)di.prcBounds;
		if( NULL == hIcon ) hIcon = LoadIcon(_AtlBaseModule.GetResourceInstance(), MAKEINTRESOURCE(IDI_QNG));
		DrawIcon(di.hdcDraw,rc.left,rc.top,hIcon);

		return S_OK;
	}

	STDMETHOD(_InternalQueryService)(REFGUID guidService, REFIID riid, void** ppvObject)
	{
		return E_NOTIMPL;
	}

	// Overridden to distinguish between "Design Time" vs "Run Time"
	virtual STDMETHODIMP SetClientSite(IOleClientSite* pClientSite);

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		// force size of design time icon
		m_bAutoSize = TRUE;		// no resize
		SIZEL size = {32,32};	// pixel size
		AtlPixelToHiMetric(&size, &m_sizeExtent);
		m_sizeNatural = m_sizeExtent;

		// pDevice = NULL, for clean destruction
		pDevice = NULL;

		return S_OK;
	}
	
	void FinalRelease() 
	{
		if (pDevice!=NULL)
		{
			delete pDevice;
			pDevice = NULL;
		}
	}
protected:
	// Represents hardware
	CDevice* pDevice;
public:
	// Property to return a 32 bit random number
	STDMETHOD(get_RandInt32)(LONG* pVal);
	// Property to return a uniform number [0,1)
	STDMETHOD(get_RandUniform)(DOUBLE* pVal);
	// Property to return a normal number
	STDMETHOD(get_RandNormal)(DOUBLE* pVal);
	// Property to read byte-array
	STDMETHOD(get_RandBytes)(LONG Length, VARIANT* pVal);
	// Method to clear all buffers
	STDMETHOD(Clear)(void);
	// Method to reset/restart hardware
	STDMETHOD(Reset)(void);
};

OBJECT_ENTRY_AUTO(__uuidof(QNG), CQNG)
