
// 进制转换器Dlg.cpp : 实现文件
//
#define  _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "进制转换器.h"
#include "进制转换器Dlg.h"
#include "afxdialogex.h"

#define ADDNAME(s,q) s##q 


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


// C进制转换器Dlg 对话框




C进制转换器Dlg::C进制转换器Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C进制转换器Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C进制转换器Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_m1);
	DDX_Control(pDX, IDC_EDIT2, m_m2);
	DDX_Control(pDX, IDC_EDIT3, m_m3);
	DDX_Control(pDX, IDC_EDIT4, m_m4);
}

BEGIN_MESSAGE_MAP(C进制转换器Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BUTTON1, IDC_BUTTON4, OnButtonClick)
END_MESSAGE_MAP()


// C进制转换器Dlg 消息处理程序

BOOL C进制转换器Dlg::OnInitDialog()
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
	m_m1.SetChange(2);
	m_m2.SetChange(8);
	m_m3.SetChange(10);
	m_m4.SetChange(16);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C进制转换器Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C进制转换器Dlg::OnPaint()
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
HCURSOR C进制转换器Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void C进制转换器Dlg::OnButtonClick(UINT nID)  
{
	CString str1;
	int i;
	char aa[50]={};
	int j[4] = {2, 8, 10, 16};
	GetDlgItem(nID - 4)->GetWindowText(str1); // 全部在10进制的基础上进行，通过查表的方式，可以拓展为2-36进制的
	i = strtol(str1, NULL, j[nID-4-1000]); str1.Format("%d", i);GetDlgItem(IDC_EDIT3)->SetWindowText(str1);
	_itoa(i, aa, 2);GetDlgItem(IDC_EDIT1)->SetWindowText(aa);
	_itoa(i, aa, 8);GetDlgItem(IDC_EDIT2)->SetWindowText(aa);
	_itoa(i, aa, 16);GetDlgItem(IDC_EDIT4)->SetWindowText(aa);
}
