
// 查找编辑框中是否有某个字符串Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "查找编辑框中是否有某个字符串.h"
#include "查找编辑框中是否有某个字符串Dlg.h"
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


// C查找编辑框中是否有某个字符串Dlg 对话框




C查找编辑框中是否有某个字符串Dlg::C查找编辑框中是否有某个字符串Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C查找编辑框中是否有某个字符串Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strInput = _T("");
	m_strFind = _T("");
}

void C查找编辑框中是否有某个字符串Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INPUT, m_strInput);
	DDX_Text(pDX, IDC_FIND, m_strFind);
}

BEGIN_MESSAGE_MAP(C查找编辑框中是否有某个字符串Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C查找编辑框中是否有某个字符串Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C查找编辑框中是否有某个字符串Dlg 消息处理程序

BOOL C查找编辑框中是否有某个字符串Dlg::OnInitDialog()
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

void C查找编辑框中是否有某个字符串Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C查找编辑框中是否有某个字符串Dlg::OnPaint()
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
HCURSOR C查找编辑框中是否有某个字符串Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C查找编辑框中是否有某个字符串Dlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	CString tmp = m_strInput;
	int pos = tmp.Find("\r\n"), i = 0; // \r\n被视为一个字符   ---- 查找\r\n来分行[行数据操作]
	while (pos >= 0)
	{
		strArray.Add(tmp.Left(pos));  // 正确操作CStringArray字符串数组
		tmp = tmp.Right(tmp.GetLength() - pos - 1);
		pos = tmp.Find("\r\n");
	}
	for (int j = 0; j < strArray.GetSize(); j++)
	{
		if (strArray.GetAt(j) == m_strFind)   // 这里比较也可以用 !strArray.GetAt(j).Compare(m_strFind)   [因为相等时返回0]          
		{
			AfxMessageBox("找到了");
			return;
		}
	}
	AfxMessageBox("未找到");
}
