// dllmain.h: 模块类的声明。

class CMFCprojectorHandlersModule : public ATL::CAtlDllModuleT<CMFCprojectorHandlersModule>
{
public :
	DECLARE_LIBID(LIBID_MFCprojectorHandlersLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_MFCPROJECTORHANDLERS, "{dbce0ad9-8bbb-450a-956d-7788ee16adf3}")
};

extern class CMFCprojectorHandlersModule _AtlModule;
