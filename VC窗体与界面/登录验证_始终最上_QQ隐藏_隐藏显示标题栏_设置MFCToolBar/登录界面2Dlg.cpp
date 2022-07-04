
// 登录界面2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "登录界面2.h"
#include "登录界面2Dlg.h"
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


// C登录界面2Dlg 对话框




C登录界面2Dlg::C登录界面2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C登录界面2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C登录界面2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SET, m_conSetTop);
	DDX_Control(pDX, IDC_TITLE, m_conTitle);
}

BEGIN_MESSAGE_MAP(C登录界面2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SET, &C登录界面2Dlg::OnBnClickedSet)
	ON_BN_CLICKED(IDC_TITLE, &C登录界面2Dlg::OnBnClickedTitle)
	ON_BN_CLICKED(IDC_BUTTON3, &C登录界面2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &C登录界面2Dlg::OnBnClickedButton4)
	ON_COMMAND(ID_BUTTON32771,&C登录界面2Dlg::OnBnClickedBUTTON32771)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// C登录界面2Dlg 消息处理程序

BOOL C登录界面2Dlg::OnInitDialog()
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

	// 设置ToolBar到对话框上
	if (m_toolB.Create(this, AFX_DEFAULT_TOOLBAR_STYLE, 100))
	{
		m_toolB.SetPaneStyle(m_toolB.GetPaneStyle()
			& ~(CBRS_GRIPPER | CBRS_SIZE_DYNAMIC | CBRS_BORDER_ANY));
		m_toolB.LoadToolBar(IDR_TOOLBAR1);

		CSize   sizeToolBar = m_toolB.CalcFixedLayout(FALSE, TRUE);
		m_toolB.SetWindowPos(NULL, 0, 0, sizeToolBar.cx, sizeToolBar.cy,
			SWP_NOACTIVATE | SWP_NOZORDER);

		m_toolB.SetRouteCommandsViaFrame(FALSE);//设置消息以对话框方式传递
		//m_toolbar.AdjustLayout();
		m_toolB.AdjustSizeImmediate();//根据按钮大小调整工具栏
	}


	// TODO: 在此添加额外的初始化代码
	if (dlgLog.DoModal() != IDOK)
	{
		CDialogEx::OnOK(); // 这里是为了和OnClose()关闭做一个区别
	}
	m_topFlg = 0;
	CRect rect;
	GetWindowRect(&rect);
	::SetWindowPos(m_hWnd,HWND_BOTTOM,rect.left,
		rect.top,0,0,SWP_NOMOVE || SWP_NOSIZE);
	m_titleFlg = TRUE;
	SetTimer(1, 100, NULL);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C登录界面2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C登录界面2Dlg::OnPaint()
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
HCURSOR C登录界面2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C登录界面2Dlg::OnBnClickedSet()
{
	m_topFlg = !m_topFlg;
	CRect rect;
	GetWindowRect(&rect);
	if (m_topFlg)
	{
		m_conSetTop.SetWindowText("置底");
		::SetWindowPos(m_hWnd,HWND_TOPMOST,rect.left,
			rect.top,0,0,SWP_NOMOVE || SWP_NOSIZE);
	}
	else
	{
		m_conSetTop.SetWindowText("置顶");
		::SetWindowPos(m_hWnd,HWND_BOTTOM,rect.left,
			rect.top,0,0,SWP_NOMOVE || SWP_NOSIZE);
	}
}


void C登录界面2Dlg::OnBnClickedTitle()
{
	CWnd *pWB = GetDlgItem(IDC_TITLE);
	m_titleFlg = !m_titleFlg;
	LONG lStyle = ::GetWindowLong(this->m_hWnd, GWL_STYLE);
	if (m_titleFlg)
	{
		pWB->SetWindowText("隐藏标题栏");
		::SetWindowLong(this->m_hWnd, GWL_STYLE, lStyle | WS_CAPTION);
	}
	else
	{
		pWB->SetWindowText("显示标题栏");
		::SetWindowLong(this->m_hWnd, GWL_STYLE, lStyle & ~WS_CAPTION);
	}
	::SetWindowPos(this->m_hWnd, NULL, 0, 0, 0, 0,SWP_NOSIZE 
		| SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);
}


void C登录界面2Dlg::OnBnClickedButton3()
{
	LONG lStyle = ::GetWindowLong(this->m_hWnd, GWL_STYLE);
	::SetWindowLong(this->m_hWnd, GWL_STYLE, lStyle & ~WS_MAXIMIZEBOX);
	::SetWindowPos(this->m_hWnd, NULL, 0, 0, 0, 0,SWP_NOSIZE 
	| SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);
}


void C登录界面2Dlg::OnBnClickedButton4()
{
	LONG lStyle = ::GetWindowLong(this->m_hWnd, GWL_STYLE);
	::SetWindowLong(this->m_hWnd, GWL_STYLE, lStyle & ~WS_MINIMIZEBOX);
	::SetWindowPos(this->m_hWnd, NULL, 0, 0, 0, 0,SWP_NOSIZE 
		| SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);
}


void C登录界面2Dlg::OnBnClickedBUTTON32771()
{
	AfxMessageBox("点击了第一个按钮");
}



void C登录界面2Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rc;
	CRect rect;
	GetWindowRect(&rect);
	rc.CopyRect(&rect);
	CPoint pOint;
	GetCursorPos(&pOint);
	if (rect.top < 0 && PtInRect(rect, pOint))
	{
		rect.top = 0;
		MoveWindow(rect.left, rect.top, rc.Width(), rc.Height());
	}
 	else if(rect.top > -3 && rect.top < 3 && !PtInRect(rect,pOint))
 	{
 		rect.top = 3-rect.Height();
 		MoveWindow(rect.left,rect.top,rc.Width(),rc.Height());
 	}
	CDialogEx::OnTimer(nIDEvent);
}
