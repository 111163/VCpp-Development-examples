
// 根据ini文件动态生成菜单Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "根据ini文件动态生成菜单.h"
#include "根据ini文件动态生成菜单Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C根据ini文件动态生成菜单Dlg 对话框




C根据ini文件动态生成菜单Dlg::C根据ini文件动态生成菜单Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C根据ini文件动态生成菜单Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C根据ini文件动态生成菜单Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C根据ini文件动态生成菜单Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// C根据ini文件动态生成菜单Dlg 消息处理程序

BOOL C根据ini文件动态生成菜单Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_cMenu.CreateMenu();
	CreateMenuFromFile();


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C根据ini文件动态生成菜单Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C根据ini文件动态生成菜单Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C根据ini文件动态生成菜单Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void C根据ini文件动态生成菜单Dlg::LoadSubMenu(CMenu* m_menu,CString str)
{
	CMenu m_tempmenu;
	m_tempmenu.CreatePopupMenu();
//	m_tempmenu.AppendMenu(MF_STRING,-1,str);
	_TCHAR buf[10240];
	CString strFilePath=".\\menu.ini";
	DWORD readlen=::GetPrivateProfileSection(str,buf,12040,strFilePath);
	_TCHAR *pbuf=buf;
	size_t size=strlen(pbuf);
	while(size)
	{
		CString strTmp(pbuf);
		CString strRight;
		int iRightPos=strTmp.Find("=");
		strRight=strTmp.Mid(iRightPos+1);
		m_tempmenu.AppendMenu(MF_STRING,-1,strRight);
		if(IsHaveSubMenu(strRight))//二级目录
			LoadSubMenu(&m_tempmenu,strRight);
		pbuf+=size+1;
		size=strlen(pbuf);
	}	
	m_cMenu.AppendMenu(MF_POPUP,(UINT)m_tempmenu.m_hMenu,str);
	m_tempmenu.Detach();
}



void C根据ini文件动态生成菜单Dlg::CreateMenuFromFile(void)
{
	CString strFilePath=".\\menu.ini";
	CString strSectionName="mainmenu";
	_TCHAR buf[10240];
	DWORD readlen=::GetPrivateProfileSection(strSectionName,buf,12040,strFilePath);
	_TCHAR *pbuf=buf;
	size_t size=strlen(pbuf);
	while(size)
	{
		CString strTmp(pbuf);
		CString strRight;
		int iRightPos=strTmp.Find("=");
		strRight=strTmp.Mid(iRightPos+1);
		LoadSubMenu(&m_cMenu,strRight);		
		pbuf+=size+1;   // 越过当前等号和值(键)
		size=strlen(pbuf);
	}	
	SetMenu(&m_cMenu);
}

BOOL C根据ini文件动态生成菜单Dlg::IsHaveSubMenu(CString strSubMenu)
{
	CString strFilePath=".\\menu.ini";
	CString tmp;
	_TCHAR buf[10240];
	::GetPrivateProfileSectionNames(buf,10240,strFilePath);  // 得到所以的
	_TCHAR *pbuf=buf;
	size_t size=strlen(pbuf);
	while(size)
	{
		CString strTmp(pbuf);
		if(strTmp==strSubMenu)
			return true;
		pbuf+=size+1; // 越过字符长和/0
		size=strlen(pbuf);
	}	
	return false;
}
