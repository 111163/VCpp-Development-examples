
// QQ登录式用户选择列表Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "QQ登录式用户选择列表.h"
#include "QQ登录式用户选择列表Dlg.h"
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


// CQQ登录式用户选择列表Dlg 对话框




CQQ登录式用户选择列表Dlg::CQQ登录式用户选择列表Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CQQ登录式用户选择列表Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CQQ登录式用户选择列表Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_ConPw);
	DDX_Control(pDX, IDC_BUTTON1, m_ConLog);
	DDX_Control(pDX, IDC_BUTTON2, m_ConCel);
	DDX_Control(pDX, IDC_COMBOBOXEX1, m_ConUserNme);
}

BEGIN_MESSAGE_MAP(CQQ登录式用户选择列表Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CQQ登录式用户选择列表Dlg 消息处理程序

BOOL CQQ登录式用户选择列表Dlg::OnInitDialog()
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
	CString str[]={"钱夫人","小丹尼","卡卡罗特","琪琪","特兰克斯","贝吉塔","天津饭"};
	m_ImageList.Create(16,16,ILC_COLOR24|ILC_MASK,1,0);		//创建列表视图窗口
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON1));		
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON2)); 		
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON3)); 		
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON4)); 		
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON5)); 		
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON6)); 		
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON7)); 		
							// 有了类但是要有窗口(数据，规格，风格等)才行，所以要Create才行
	m_ConUserNme.SetImageList(&m_ImageList);  // 告诉组合框图标从这里拿
	for (int i = 0; i<7; ++i)
	{
		COMBOBOXEXITEM cbi;
		cbi.mask = CBEIF_IMAGE|CBEIF_INDENT|CBEIF_OVERLAY|
			CBEIF_SELECTEDIMAGE|CBEIF_TEXT;
		cbi.iItem 			= i;
		cbi.pszText 		= str[i].GetBuffer(0);	//设置列表项文本
		cbi.cchTextMax		= str[i].GetLength();	//设置文本最大长度
		cbi.iImage 			= i;
		cbi.iSelectedImage	= i;
		cbi.iOverlay 		= 0;
		cbi.iIndent 		= (0 & 0x03); 
		m_ConUserNme.InsertItem(&cbi);					//填充好节点后(这个节点是包含数据，图像，位置等等) 插入数据-到节点
	} 
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CQQ登录式用户选择列表Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CQQ登录式用户选择列表Dlg::OnPaint()
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
HCURSOR CQQ登录式用户选择列表Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


