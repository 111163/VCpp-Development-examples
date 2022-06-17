
// 在光标位置加入字符串Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "在光标位置加入字符串.h"
#include "在光标位置加入字符串Dlg.h"
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


// C在光标位置加入字符串Dlg 对话框




C在光标位置加入字符串Dlg::C在光标位置加入字符串Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C在光标位置加入字符串Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strEdit = _T("");
	m_strAdd = _T("");
}

void C在光标位置加入字符串Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT, m_strEdit);
	DDX_Control(pDX, IDC_EDIT, m_celEdit);
	DDX_Text(pDX, IDC_ADD, m_strAdd);
}

BEGIN_MESSAGE_MAP(C在光标位置加入字符串Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_KILLFOCUS(IDC_EDIT, &C在光标位置加入字符串Dlg::OnEnKillfocusEdit)
	ON_BN_CLICKED(IDC_BUTTON1, &C在光标位置加入字符串Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C在光标位置加入字符串Dlg 消息处理程序

BOOL C在光标位置加入字符串Dlg::OnInitDialog()
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

void C在光标位置加入字符串Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C在光标位置加入字符串Dlg::OnPaint()
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
HCURSOR C在光标位置加入字符串Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// 编辑框失去焦点的时候保存焦点的位置
void C在光标位置加入字符串Dlg::OnEnKillfocusEdit()
{
	pt = GetCaretPos();
}


void C在光标位置加入字符串Dlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	int n = m_celEdit.CharFromPos(pt);
	int nCharIndex = LOWORD(n);
	//这里注意分割的话我们不需要分割字符，就要减掉1就是m_strEdit.GetLength()-n-1，但是我们
	//这里只需要的是添加，所以不必-1
	m_strEdit = m_strEdit.Left(n) + m_strAdd + m_strEdit.Right(m_strEdit.GetLength()-n);
	UpdateData(FALSE);
}
