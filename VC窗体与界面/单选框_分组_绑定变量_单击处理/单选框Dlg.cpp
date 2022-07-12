
// 单选框Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "单选框.h"
#include "单选框Dlg.h"
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


// C单选框Dlg 对话框




C单选框Dlg::C单选框Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C单选框Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_ValFir = 0;
	m_VarSec = 0;
}

void C单选框Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_RADIO1, m_ConFir);
	//  DDX_Control(pDX, IDC_RADIO5, m_ConSec);
	DDX_Radio(pDX, IDC_RADIO1, m_ValFir);
	DDX_Radio(pDX, IDC_RADIO5, m_VarSec);
}

BEGIN_MESSAGE_MAP(C单选框Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &C单选框Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &C单选框Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &C单选框Dlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &C单选框Dlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &C单选框Dlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &C单选框Dlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO7, &C单选框Dlg::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO8, &C单选框Dlg::OnBnClickedRadio8)
	ON_BN_CLICKED(IDC_BUTTON1, &C单选框Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C单选框Dlg 消息处理程序

BOOL C单选框Dlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C单选框Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C单选框Dlg::OnPaint()
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
HCURSOR C单选框Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C单选框Dlg::OnBnClickedRadio1()
{
	m_ValFir = 0;
	AfxMessageBox("m_ValFir");
}


void C单选框Dlg::OnBnClickedRadio2()
{
	m_ValFir = 1;
	AfxMessageBox("m_ValFir");
}


void C单选框Dlg::OnBnClickedRadio3()
{
	m_ValFir = 2;
	AfxMessageBox("m_ValFir");
}


void C单选框Dlg::OnBnClickedRadio4()
{
	m_ValFir = 3;
	AfxMessageBox("m_ValFir");
}


void C单选框Dlg::OnBnClickedRadio5()
{
	m_VarSec = 0;
}


void C单选框Dlg::OnBnClickedRadio6()
{
	m_VarSec = 1;
	AfxMessageBox("m_VarSec");
}


void C单选框Dlg::OnBnClickedRadio7()
{
	m_VarSec = 2;
	AfxMessageBox("m_VarSec");
}


void C单选框Dlg::OnBnClickedRadio8()
{
	m_VarSec = 3;
	AfxMessageBox("m_VarSec");
}


void C单选框Dlg::OnBnClickedButton1()
{
	CString str,text;
	CButton* but = (CButton*)GetDlgItem(IDC_RADIO1 + m_ValFir);
	but->GetWindowText(text);
	str += text + "\r\n";
	but = (CButton*)GetDlgItem(IDC_RADIO5 + m_VarSec);
	but->GetWindowText(text);
	str +=text;
	MessageBox(str);
}
