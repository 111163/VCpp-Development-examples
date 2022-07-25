
// 根据菜单生成工具栏Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "根据菜单生成工具栏.h"
#include "根据菜单生成工具栏Dlg.h"
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


// C根据菜单生成工具栏Dlg 对话框




C根据菜单生成工具栏Dlg::C根据菜单生成工具栏Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C根据菜单生成工具栏Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C根据菜单生成工具栏Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C根据菜单生成工具栏Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND_RANGE(ID_32771, ID_32781, OnCom)
END_MESSAGE_MAP()


// C根据菜单生成工具栏Dlg 消息处理程序

BOOL C根据菜单生成工具栏Dlg::OnInitDialog()
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
	m_imagelist.Create(32,32,ILC_COLOR32|ILC_MASK,0,0);
	CString strpath;
	HICON hicon;
	for(int i = 0; i<10;++i)
	{
		strpath.Format(".\\res\\toolbar\\%02d.ico", i);
		hicon = (HICON)::LoadImage(NULL, strpath, IMAGE_ICON,32,32,LR_LOADFROMFILE);
		m_imagelist.Add(hicon);
	}
	m_toolbar.Create(WS_CHILD|WS_VISIBLE, CRect(0,0,0,0), this, 154230);
	m_toolbar.EnableAutomation();
	m_toolbar.SetImageList(&m_imagelist);
	m_Menu.LoadMenu(IDR_MENU1);
	TBBUTTON button[11];
	for (int i = 0; i<11; ++i)
	{
		button[i].dwData = 0;
		button[i].fsState = TBSTATE_ENABLED;
		button[i].fsStyle = TBSTYLE_BUTTON;
	}

	int iMenuButtonCount=0;
	MENUITEMINFO info;
	CString strMenuName;

	int coun = m_Menu.GetMenuItemCount(); // 得到菜单元素数量
	for (int i =0; i<coun; ++i)
	{
		CMenu* m_tmpMenu = m_Menu.GetSubMenu(i);
		int coun1 = m_tmpMenu->GetMenuItemCount();
		for(int j = 0; j<coun1;++j)
		{
			m_tmpMenu->GetMenuString(i, strMenuName, MF_BYPOSITION);
			button[iMenuButtonCount].idCommand = m_tmpMenu->GetMenuItemID(j);
			button[iMenuButtonCount].iBitmap = iMenuButtonCount%9;
			button[iMenuButtonCount].iString =m_toolbar.AddStrings(strMenuName);
			iMenuButtonCount++;
			if (iMenuButtonCount>10)
				break;
		}
	}
	
	m_toolbar.AddButtons(iMenuButtonCount, button);
	m_toolbar.AutoSize();
	m_toolbar.SetStyle(TBSTYLE_FLAT|CCS_TOP);

	SetMenu(&m_Menu);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C根据菜单生成工具栏Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C根据菜单生成工具栏Dlg::OnPaint()
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
HCURSOR C根据菜单生成工具栏Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void C根据菜单生成工具栏Dlg::OnCom(UINT nID)
{
	CString tmp;
	tmp.Format("%d", nID);
	AfxMessageBox("点击了"+tmp+ "命令");
}

