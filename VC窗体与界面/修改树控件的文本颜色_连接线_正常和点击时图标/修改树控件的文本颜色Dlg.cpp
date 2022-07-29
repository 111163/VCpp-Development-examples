
// 修改树控件的文本颜色Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "修改树控件的文本颜色.h"
#include "修改树控件的文本颜色Dlg.h"
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


// C修改树控件的文本颜色Dlg 对话框




C修改树控件的文本颜色Dlg::C修改树控件的文本颜色Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C修改树控件的文本颜色Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C修改树控件的文本颜色Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C修改树控件的文本颜色Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// C修改树控件的文本颜色Dlg 消息处理程序

BOOL C修改树控件的文本颜色Dlg::OnInitDialog()
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
	m_TreeCtrl.Create(TVS_LINESATROOT |TVS_HASLINES |TVS_HASBUTTONS|WS_BORDER
		|LVS_SHOWSELALWAYS,CRect(0,0,0,0),this,10001);
	m_TreeCtrl.MoveWindow(10,10,200,300);                                           //设置控件显示位置
	m_TreeCtrl.ShowWindow(SW_SHOW);                                                     //显示控件
	m_ImageList.Create(16, 16, ILC_COLOR24|ILC_MASK, 1, 1);
	m_ImageList.Add(LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON1))); // 市 0
	m_ImageList.Add(LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON2))); // 区 1
	m_ImageList.Add(LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON3))); // 省 2
	m_TreeCtrl.SetImageList(&m_ImageList, TVSIL_NORMAL);

	HTREEITEM hProvince = m_TreeCtrl.InsertItem("吉林省",2,2);
	HTREEITEM hTown = m_TreeCtrl.InsertItem("松原市", 0, 0, hProvince);
	m_TreeCtrl.InsertItem("白城市", 0, 0, hProvince);
	m_TreeCtrl.InsertItem("吉林市", 0, 0, hProvince);
	m_TreeCtrl.InsertItem("长春市", 0, 0, hProvince);
	m_TreeCtrl.InsertItem("扶余县", 1, 1, hTown);
	m_TreeCtrl.InsertItem("前郭县", 1, 1, hTown);
	m_TreeCtrl.InsertItem("长岭县", 1, 1, hTown);
	m_TreeCtrl.InsertItem("农安县", 1, 1, hTown);
	m_TreeCtrl.InsertItem("宁江区", 1, 1, hTown);
	m_TreeCtrl.SetTextColor(RGB(255, 0, 0));		  //设置文本颜色
	m_TreeCtrl.SetLineColor(RGB(0,255,0));            //设置连接线颜色
	m_TreeCtrl.Expand(hProvince,TVE_EXPAND);          //展开根节点
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C修改树控件的文本颜色Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C修改树控件的文本颜色Dlg::OnPaint()
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
HCURSOR C修改树控件的文本颜色Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

