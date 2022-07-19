
// 从数据库动态生成菜单.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "从数据库动态生成菜单.h"
#include "从数据库动态生成菜单Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C从数据库动态生成菜单App

BEGIN_MESSAGE_MAP(C从数据库动态生成菜单App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// C从数据库动态生成菜单App 构造

C从数据库动态生成菜单App::C从数据库动态生成菜单App()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 C从数据库动态生成菜单App 对象

C从数据库动态生成菜单App theApp;
_ConnectionPtr m_pCon;
_RecordsetPtr m_pRecord;

// C从数据库动态生成菜单App 初始化

BOOL C从数据库动态生成菜单App::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	::CoInitialize(NULL);
	m_pCon = NULL;
	m_pCon.CreateInstance(__uuidof(Connection));
	m_pRecord = NULL;
	m_pRecord.CreateInstance(__uuidof(Recordset));
	m_pCon->ConnectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Menu.accdb;Persist Security Info=False";
	try 
	{
		m_pCon->Open(L"", L"", L"", -1);
	}
	catch (...)
	{
		AfxMessageBox("数据库连接错误");
		exit(0);
	}



	C从数据库动态生成菜单Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}



int C从数据库动态生成菜单App::ExitInstance()
{
	// TODO: 在此添加专用代码和/或调用基类
	m_pRecord->Close();
	m_pRecord = NULL;
	m_pCon->Close();
	m_pCon = NULL;
	::CoUninitialize();
	return CWinApp::ExitInstance();
}
