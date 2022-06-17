
// ListBox的操作Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ListBox的操作.h"
#include "ListBox的操作Dlg.h"
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


// CListBox的操作Dlg 对话框




CListBox的操作Dlg::CListBox的操作Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CListBox的操作Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strEdit = _T("");
}

void CListBox的操作Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT, m_strEdit);
	DDX_Control(pDX, IDC_LIST, m_conList);
}

BEGIN_MESSAGE_MAP(CListBox的操作Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CListBox的操作Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CListBox的操作Dlg 消息处理程序

BOOL CListBox的操作Dlg::OnInitDialog()
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

	CString str;
	for (int i=0;i < 10;i++)
	{
		str.Format(_T("item string %d"), i);
		m_conList.AddString(str);
	}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CListBox的操作Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CListBox的操作Dlg::OnPaint()
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
HCURSOR CListBox的操作Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CListBox的操作Dlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	char buf[1024];
	/* 
	// 这里注意使用SendMessage(m_conList.GetSafeHwnd(),LB_FINDSTRINGEXACT,-1,(LPARAM)(LPCTSTR)m_strEdit)
	// = m_conList.FindString(-1,(LPCTSTR)m_strEdit)
	CString strres;
	int index=::SendMessage(m_conList.GetSafeHwnd(),LB_FINDSTRINGEXACT,-1,
		(LPARAM)(LPCTSTR)m_strEdit);
	if(index>=0)
	{
		strres.Format("字符串索引是%d",index);
		MessageBox(strres);
	}
	else
	{
		MessageBox("没有找到");
	}
	*/
	CString strres;
	int index = m_conList.FindString(-1,(LPCTSTR)m_strEdit);
	if(index>=0)
	{
		strres.Format("字符串索引是%d",index);
		MessageBox(strres);
	}
	else
	{
		MessageBox("没有找到");
	}
}
