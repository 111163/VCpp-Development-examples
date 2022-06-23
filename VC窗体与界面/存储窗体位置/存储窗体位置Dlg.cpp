
// 存储窗体位置Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "存储窗体位置.h"
#include "存储窗体位置Dlg.h"
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


// C存储窗体位置Dlg 对话框




C存储窗体位置Dlg::C存储窗体位置Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C存储窗体位置Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strConfigPath = _T("");
}

void C存储窗体位置Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT, m_ConCaption);
}

BEGIN_MESSAGE_MAP(C存储窗体位置Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// C存储窗体位置Dlg 消息处理程序

BOOL C存储窗体位置Dlg::OnInitDialog()
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
	char path[128];
	::GetCurrentDirectory(128, path); //获取到应用程序的路径
	m_strConfigPath = strcat(path ,"\\Config.ini");
	::GetPrivateProfileString("配置信息", "标题", "", path, 128, m_strConfigPath); //得到ini配置文件中的信息
	if (path != "")
	{
		SetWindowTextA(path);
	}
	ConfigInfo configinfo;
	if (GetPrivateProfileStruct("配置信息", "位置", &configinfo, sizeof(ConfigInfo), m_strConfigPath))
	{
		CRect rect;
		rect.left = configinfo.left;
		rect.top = configinfo.top;
		rect.right = configinfo.left + configinfo.width;
		rect.bottom = configinfo.top + configinfo.height;
		this->MoveWindow(&rect, TRUE);
	}
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C存储窗体位置Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C存储窗体位置Dlg::OnPaint()
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
HCURSOR C存储窗体位置Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C存储窗体位置Dlg::OnDestroy() // 注意这里是响应了WM_DESTROY标准信息
{
	CString caption;
	m_ConCaption.GetWindowText(caption); //对控件来说是没有标题这个属性的，所以WindowText就是它的内容
	if (caption != "")
	{
		::WritePrivateProfileString("配置信息", "标题", caption, m_strConfigPath); // 写信息到配置文件中
	}
	ConfigInfo configinfo;
	CRect rect;
	this->GetWindowRect(&rect);
	configinfo.left = rect.left;
	configinfo.top = rect.top;
	configinfo.width = rect.Width();
	configinfo.height = rect.Height();
	::WritePrivateProfileStruct("配置信息","位置", &configinfo, sizeof(ConfigInfo), m_strConfigPath);
	CDialogEx::OnDestroy();
}
