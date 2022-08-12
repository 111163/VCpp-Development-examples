
// 线程操作Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "线程操作.h"
#include "线程操作Dlg.h"
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


// C线程操作Dlg 对话框




C线程操作Dlg::C线程操作Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C线程操作Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C线程操作Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_Prog);
}

BEGIN_MESSAGE_MAP(C线程操作Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CREATE, &C线程操作Dlg::OnBnClickedCreate)
	ON_BN_CLICKED(IDC_SESPEND, &C线程操作Dlg::OnBnClickedSespend)
	ON_BN_CLICKED(IDC_RESUME, &C线程操作Dlg::OnBnClickedResume)
	ON_BN_CLICKED(IDC_TERMINATE, &C线程操作Dlg::OnBnClickedTerminate)
	ON_BN_CLICKED(IDC_EXIT, &C线程操作Dlg::OnBnClickedExit)
END_MESSAGE_MAP()


// C线程操作Dlg 消息处理程序

BOOL C线程操作Dlg::OnInitDialog()
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
	//((CProgressCtrl*)GetDlgItem(IDC_PROGRESS1))->SetRange32(0, 99999);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C线程操作Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C线程操作Dlg::OnPaint()
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
HCURSOR C线程操作Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

UINT ThreatePrc(LPVOID lpParameter)
{
	C线程操作Dlg* pDlg = (C线程操作Dlg*)lpParameter;	//获取对话框指针
	pDlg->m_Prog.SetRange32(0,99999);							//设置进度条的范围
	for (int i=0; i<99999;i++)									//设计循环
	{
		pDlg->m_Prog.SetPos(i);									//设置进度条的位置
	}
	return 0;
}


void C线程操作Dlg::OnBnClickedCreate()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pThread = AfxBeginThread(ThreatePrc, this);	//创建线程   //////////////////////////////////////////////////////////////////////////
}


void C线程操作Dlg::OnBnClickedSespend() // 挂起线程
{
	// TODO: 在此添加控件通知处理程序代码
	SuspendThread(m_pThread->m_hThread); //////////////////////////////////////////////////////////////////////////
}


void C线程操作Dlg::OnBnClickedResume() // 唤醒线程
{
	// TODO: 在此添加控件通知处理程序代码
	ResumeThread(m_pThread->m_hThread); //////////////////////////////////////////////////////////////////////////
}


void C线程操作Dlg::OnBnClickedTerminate() // 强制终止线性
{
	// TODO: 在此添加控件通知处理程序代码
	DWORD dsExit;
	if (m_pThread != NULL)
	{
		GetExitCodeThread(m_pThread, &dsExit);
		if (dsExit == STILL_ACTIVE)
			TerminateThread(m_pThread->m_hThread, 0); //////////////////////////////////////////////////////////////////////////
		delete m_pThread;
	}
}


void C线程操作Dlg::OnBnClickedExit()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
