
// 跨程序复制操作Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "跨程序复制操作.h"
#include "跨程序复制操作Dlg.h"
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


// C跨程序复制操作Dlg 对话框




C跨程序复制操作Dlg::C跨程序复制操作Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C跨程序复制操作Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strEdit = _T("");
}

void C跨程序复制操作Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_conEdit);
	DDX_Text(pDX, IDC_EDIT1, m_strEdit);
}

BEGIN_MESSAGE_MAP(C跨程序复制操作Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C跨程序复制操作Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C跨程序复制操作Dlg 消息处理程序

BOOL C跨程序复制操作Dlg::OnInitDialog()
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

void C跨程序复制操作Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C跨程序复制操作Dlg::OnPaint()
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
HCURSOR C跨程序复制操作Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C跨程序复制操作Dlg::OnBnClickedButton1()
{
	int mStart, mEnd;
	CString tmp;
	m_conEdit.GetSel(mStart, mEnd);
	if(mStart >= mEnd)return;//没有进行选择
	UpdateData(TRUE);						     // 绑定控件和绑定变量都可以获取到值
	tmp = m_strEdit.Mid(mStart, mEnd - mStart); // ==> m_conEdit.GetWindowText(tmp1),tmp = tmp1(mStart, mEnd-mStart);
												// 应该注意到Mid函数Mid(start, n)

	//将选中的字符复制到剪贴板，将字符复制到剪贴板的步骤是，首先使用GlobalAlloc分配一块内存空间，
	//然后将字符数据复制到该块内存中，最后通过SetClipboardData函数将选定的内容复制到剪贴板中。
	::OpenClipboard(this->GetSafeHwnd()); // 打开剪切板，当前窗口句柄this->GetSaftHwnd()
	EmptyClipboard(); // 清空剪切板
 	HGLOBAL hGlobal=GlobalAlloc(GMEM_FIXED,tmp.GetLength()+1);
 	HANDLE hmem=GlobalLock(hGlobal);
 	memcpy(hmem,tmp.GetBuffer(0),tmp.GetLength()+1);
 	GlobalUnlock(hGlobal);
 	SetClipboardData(CF_TEXT,hGlobal);
	m_conEdit.Paste();
	CloseClipboard();

	// CWnd::Copy()封装了上面的操作 
	/*m_conEdit.Copy();*/
}

