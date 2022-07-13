
// 列表框数据交换Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "列表框数据交换.h"
#include "列表框数据交换Dlg.h"
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


// C列表框数据交换Dlg 对话框




C列表框数据交换Dlg::C列表框数据交换Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C列表框数据交换Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C列表框数据交换Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RIGHT, m_ConBr);
	DDX_Control(pDX, IDC_LEFT, m_ConBl);
	DDX_Control(pDX, IDC_LEFTALL, m_ConBla);
	DDX_Control(pDX, IDC_RIGHTALL, m_ConBra);
	DDX_Control(pDX, IDC_LISTLEFT, m_ConLl);
	DDX_Control(pDX, IDC_LISTRIGHT, m_ConLr);
}

BEGIN_MESSAGE_MAP(C列表框数据交换Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RIGHT, &C列表框数据交换Dlg::OnBnClickedRight)
	ON_BN_CLICKED(IDC_LEFT, &C列表框数据交换Dlg::OnBnClickedLeft)
	ON_BN_CLICKED(IDC_RIGHTALL, &C列表框数据交换Dlg::OnBnClickedRightall)
	ON_BN_CLICKED(IDC_LEFTALL, &C列表框数据交换Dlg::OnBnClickedLeftall)
END_MESSAGE_MAP()


// C列表框数据交换Dlg 消息处理程序

BOOL C列表框数据交换Dlg::OnInitDialog()
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
	m_ConLl.AddString("语文");
	m_ConLl.AddString("数学");
	m_ConLl.AddString("英语");
	m_ConLl.AddString("物理");
	m_ConLl.AddString("化学");
	m_ConLl.AddString("历史");
	m_ConLl.AddString("政治");
	m_ConLl.AddString("地理");
	m_ConLl.AddString("生物");
	m_ConLl.AddString("计算机");
	m_ConBr.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP4)));
	m_ConBl.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP2)));
	m_ConBra.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP5)));
	m_ConBla.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP3)));
	m_ConBl.EnableWindow(FALSE);
	m_ConBla.EnableWindow(FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C列表框数据交换Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C列表框数据交换Dlg::OnPaint()
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
HCURSOR C列表框数据交换Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C列表框数据交换Dlg::OnBnClickedRight()
{
	// TODO: 在此添加控件通知处理程序代码
	int  pos = m_ConLl.GetCurSel();
	if (pos < 0)
	{
		MessageBox("请选择要移动的选项");
		return;
	}
	CString text;
	m_ConLl.GetText(pos,text);
	m_ConLl.DeleteString(pos);
	m_ConLr.AddString(text);
	m_ConBl.EnableWindow(TRUE);
	m_ConBla.EnableWindow(TRUE);
	if(m_ConLl.GetCount()==0)
	{
		m_ConBr.EnableWindow(FALSE);
		m_ConBra.EnableWindow(FALSE);
		return;
	}
	m_ConLl.SetCurSel(0);
}


void C列表框数据交换Dlg::OnBnClickedLeft()
{
	// TODO: 在此添加控件通知处理程序代码
	int i=m_ConLr.GetCurSel();
	if(i<0)
	{
		MessageBox("请选择要移动的选项");
		return;
	}
	CString text;
	m_ConLr.GetText(i,text);
	m_ConLr.DeleteString(i);
	m_ConLl.AddString(text);
	m_ConBr.EnableWindow(TRUE);
	m_ConBra.EnableWindow(TRUE);
	if(m_ConLr.GetCount()==0)
	{
		m_ConBl.EnableWindow(FALSE);
		m_ConBla.EnableWindow(FALSE);
		return;
	}
	m_ConLr.SetCurSel(0);
}


void C列表框数据交换Dlg::OnBnClickedRightall()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0;i<m_ConLl.GetCount();++i)
	{
		CString text;
		m_ConLl.GetText(i, text);
		m_ConLr.AddString(text);
	}
	m_ConLl.ResetContent();
	m_ConBl.EnableWindow(TRUE);
	m_ConBla.EnableWindow(TRUE);
	m_ConBr.EnableWindow(FALSE);
	m_ConBra.EnableWindow(FALSE);	
}


void C列表框数据交换Dlg::OnBnClickedLeftall()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0;i<m_ConLr.GetCount();++i)
	{
		CString text;
		m_ConLr.GetText(i, text);
		m_ConLl.AddString(text);
	}
	m_ConLr.ResetContent();
	m_ConBr.EnableWindow(TRUE);
	m_ConBra.EnableWindow(TRUE);
	m_ConBl.EnableWindow(FALSE);
	m_ConBla.EnableWindow(FALSE);	
}
