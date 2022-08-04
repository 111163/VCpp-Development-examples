
// TestShowMsgDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TestShowMsg.h"
#include "TestShowMsgDlg.h"
#include "afxdialogex.h"
#include "ShowMsg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma  comment(lib, "..\\Debug\\ShowMsg.lib")


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


// CTestShowMsgDlg 对话框




CTestShowMsgDlg::CTestShowMsgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestShowMsgDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestShowMsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestShowMsgDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CTestShowMsgDlg 消息处理程序

BOOL CTestShowMsgDlg::OnInitDialog()
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
	/*
	HMODULE hMod = LoadLibrary("..\\Debug\\ShowMsg.dll");                //加载动态链接库

	if (hMod != NULL)                                           //判断是否加载成功
	{
		//获取动态链接库中的GetTextDlg函数
		typedef void ( *ShMsg)(char*);                       //定义函数指针类型
		typedef int  (WINAPI *ShM)(HWND,LPCSTR,LPCSTR,UINT);     //定义函数指针类型
		ShMsg GetTextDlg = (ShMsg)GetProcAddress(hMod,"ShowMsg");
		ShM ReleaseTextDlg= (ShM)GetProcAddress(hMod,
			"ShowM");//获取动态链接库中的ReleaseTextDlg 函数
		if (GetTextDlg != NULL && ReleaseTextDlg != NULL) //判断函数指针是否为空
		{
			GetTextDlg("你好世界");
			ReleaseTextDlg(NULL, "你好", "世界", MB_OKCANCEL);
		}
		FreeLibrary(hMod);                                     //卸载动态链接库
	}
	*/
	ShowM(NULL, "你好", "世界", MB_OKCANCEL);


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTestShowMsgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTestShowMsgDlg::OnPaint()
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
HCURSOR CTestShowMsgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

