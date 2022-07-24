
// 状态栏操作Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "状态栏操作.h"
#include "状态栏操作Dlg.h"
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


// C状态栏操作Dlg 对话框




C状态栏操作Dlg::C状态栏操作Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C状态栏操作Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C状态栏操作Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C状态栏操作Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// C状态栏操作Dlg 消息处理程序

BOOL C状态栏操作Dlg::OnInitDialog()
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
	UINT array[4];
	for(int i=0;i<4;i++)
	{
		array[i] = 1001 + i;
	}
	m_StatusBar.Create(this); //创建状态栏窗口
	m_StatusBar.SetIndicators(array,sizeof(array)/sizeof(UINT)); //添加面板
	for(int n=0;n<4;n++)
	{
		m_StatusBar.SetPaneInfo(n,array[n],0,90); //设置面板宽度
	}
	//设置面板文本
	m_StatusBar.SetPaneText(0,"当前用户：");
	m_StatusBar.SetPaneText(1,"TM");
	m_StatusBar.SetPaneText(2,"当前状态：");
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0); //显示状态栏
	RECT m_rect;
	
	m_Progress.Create( WS_CHILD|WS_VISIBLE|PBS_SMOOTH, CRect(0,0,0,0), this, 1);
	m_StatusBar.GetItemRect(3,&m_rect); //获取第四个面板的区域	
	m_Progress.SetParent(&m_StatusBar); //设置进度条的父窗口为状态栏
	m_Progress.MoveWindow(&m_rect);     //设置进度条显示的位置
	//m_Progress.Create( WS_CHILD|WS_VISIBLE|PBS_SMOOTH, m_rect, &m_StatusBar, 1); //这句和上面的是等效的--同时说明一个道理，就是必须创建 进度条，且创建进度条的时候父窗口类必须存在 
	m_Progress.ShowWindow(SW_SHOW);     //显示进度条控件
	m_Progress.SetRange(0,100);          //设置进度条范围
	m_Progress.SetPos(50);              //设置进度条当前位置

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE


}

void C状态栏操作Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C状态栏操作Dlg::OnPaint()
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
HCURSOR C状态栏操作Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

