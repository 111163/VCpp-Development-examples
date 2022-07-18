
// 带历史信息的菜单Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "带历史信息的菜单.h"
#include "带历史信息的菜单Dlg.h"
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


// C带历史信息的菜单Dlg 对话框




C带历史信息的菜单Dlg::C带历史信息的菜单Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C带历史信息的菜单Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C带历史信息的菜单Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C带历史信息的菜单Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32771, &C带历史信息的菜单Dlg::On32771)
	ON_COMMAND(ID_OOPEN, &C带历史信息的菜单Dlg::OnOopen)
	ON_COMMAND(ID_CCL, &C带历史信息的菜单Dlg::OnCcl)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// C带历史信息的菜单Dlg 消息处理程序

BOOL C带历史信息的菜单Dlg::OnInitDialog()
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
	m_Menu.LoadMenu(IDR_MENU1);
	SetMenu(&m_Menu);

	num = 32772;

	CMenu* pMenu = m_Menu.GetSubMenu(1);
	pMenu->EnableMenuItem(ID_CCL, 1);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C带历史信息的菜单Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C带历史信息的菜单Dlg::OnPaint()
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
HCURSOR C带历史信息的菜单Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C带历史信息的菜单Dlg::On32771()
{
	CString strText;
	CFileDialog m_File(TRUE, NULL, NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, 
		"All Files(*.*)|*.*|", AfxGetMainWnd());
	if (m_File.DoModal() == IDOK)
	{
		strText = m_File.GetPathName();
		CMenu* m_pMenu = m_Menu.GetSubMenu(0);
		m_pMenu->InsertMenu(2, MF_BYPOSITION, num, strText);
		//SetMenu(&m_Menu);
		num++;
	}
	else
		return;

}


void C带历史信息的菜单Dlg::OnOopen()
{
	CMenu* pMenu = m_Menu.GetSubMenu(1);
	//pMenu->AppendMenu(MF_STRING,10001, "文本1");
	//pMenu->AppendMenu(MF_STRING,10002, "文本2");
	//pMenu->AppendMenu(MF_STRING,10003, "文本3");
	pMenu->InsertMenu(1, MF_BYPOSITION, 10001, "文本1");
	pMenu->InsertMenu(1, MF_BYPOSITION, 10002, "文本1");
	pMenu->InsertMenu(1, MF_BYPOSITION, 10003, "文本1");

	pMenu->EnableMenuItem(ID_OOPEN, MF_GRAYED); // 该方法用于设置菜单项有效、无效或变灰
	pMenu->EnableMenuItem(ID_CCL, MF_ENABLED);
	
}


void C带历史信息的菜单Dlg::OnCcl()
{
	CMenu* pMenu = m_Menu.GetSubMenu(1);
	pMenu->RemoveMenu(10001,MF_BYCOMMAND);
	pMenu->RemoveMenu(10002,MF_BYCOMMAND);
	pMenu->RemoveMenu(10003,MF_BYCOMMAND);

	pMenu->EnableMenuItem(ID_CCL, MF_GRAYED);
	pMenu->EnableMenuItem(ID_OOPEN, MF_ENABLED);
}


BOOL C带历史信息的菜单Dlg::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetWindowRect(&rect);
	CDC memDC;
	CBitmap bitmap;
	CBitmap* bmp = NULL;
	bitmap.LoadBitmap(IDB_BITMAP1);
	memDC.CreateCompatibleDC(pDC);
	bmp = memDC.SelectObject(&bitmap);
	pDC->BitBlt(0,0,rect.Width(),rect.Height(),&memDC,0,0,SRCCOPY);
	if (bmp) memDC.SelectObject(bmp);
	return TRUE;
	// return CDialogEx::OnEraseBkgnd(pDC);
}
