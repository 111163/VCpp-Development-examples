
// MFC使用win32动态库Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC使用win32动态库.h"
#include "MFC使用win32动态库Dlg.h"
#include "afxdialogex.h"
//#include "ShowDlg.h"          // -----------------------规则动态库，静态调用
#include "MyDlg.h"				//  -----------------------拓展动态库，静态调用

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//#pragma comment(lib, "..\\Debug\\ShowDlg.lib")  //  -----------------------规则动态库，静态调用
#pragma  comment(lib, "..\\Debug\\ClassAndRS.lib") //  -----------------------拓展动态库，静态调用


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


// CMFC使用win32动态库Dlg 对话框




CMFC使用win32动态库Dlg::CMFC使用win32动态库Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC使用win32动态库Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC使用win32动态库Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFC使用win32动态库Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMFC使用win32动态库Dlg 消息处理程序

BOOL CMFC使用win32动态库Dlg::OnInitDialog()
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
	//////////////////////////////////////////////////////////////////////////规则动态库的动态加载
	//typedef int (*funShowInfo)(void); // 函数指针对象
	//int *pa = NULL;
	//HMODULE hMod = LoadLibrary("ShowDlg.dll");                             //加载动态链接库
	//if (hMod != NULL)                                                                //判断加载是否成功
	//{
	//	funShowInfo ShowInfo;                                                   //定义函数指针
	//	ShowInfo = (funShowInfo)GetProcAddress(hMod,"fnShowDlg");     //获取动态链接库中的函数
	//	pa = (int*)GetProcAddress(hMod, "nShowDlg");
	//	int a = ShowInfo();
	//	CString tmp;
	//	tmp.Format("%d %d", a, *pa);
	//	AfxMessageBox(tmp);
	//}
	//FreeLibrary(hMod);                                                                //卸载动态链接库

 	CMyDlg dlg;
 	if (dlg.DoModal() == IDOK)
 	{
		AfxMessageBox("OK");
 	}
	else
		AfxMessageBox("NO");

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC使用win32动态库Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC使用win32动态库Dlg::OnPaint()
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
HCURSOR CMFC使用win32动态库Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

