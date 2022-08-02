
// 验证码生成Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "验证码生成.h"
#include "验证码生成Dlg.h"
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


// C验证码生成Dlg 对话框




C验证码生成Dlg::C验证码生成Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C验证码生成Dlg::IDD, pParent)
{
	m_bNew = TRUE;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C验证码生成Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECKPICTURE, m_CheckPicture);
}

BEGIN_MESSAGE_MAP(C验证码生成Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ENTER, &C验证码生成Dlg::OnBnClickedBtnEnter)
	ON_BN_CLICKED(IDC_BTN_EXIT, &C验证码生成Dlg::OnBnClickedBtnExit)
END_MESSAGE_MAP()


// C验证码生成Dlg 消息处理程序

BOOL C验证码生成Dlg::OnInitDialog()
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

void C验证码生成Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C验证码生成Dlg::OnPaint()
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
		CPaintDC dc(this);
		CRect rc;
		if (m_bNew)
		{
			// m_strTemp = CreateRegionCode();
			m_strTemp = CreateRegionCode1();
			m_bNew = FALSE;
		}
		CFont font;
		font.CreatePointFont(200, "宋体");
		CFont *oldFont = dc.SelectObject(&font);
		m_CheckPicture.GetWindowRect(&rc);
		ScreenToClient(rc);
		dc.FillRect(rc, &CBrush(RGB(255, 255, 255))); // 填充白色背景
		dc.DrawText(m_strTemp, rc, DT_CENTER|DT_VCENTER); // 写文字
		//dc.TextOut(rc.left, rc.top, m_strTemp);
		dc.SelectObject(oldFont);
		font.DeleteObject();
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C验证码生成Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C验证码生成Dlg::OnBnClickedBtnEnter()
{
	// TODO: 在此添加控件通知处理程序代码
}


void C验证码生成Dlg::OnBnClickedBtnExit()
{
	// TODO: 在此添加控件通知处理程序代码
}

int n = 1;
CString C验证码生成Dlg::CreateRegionCode()
{
	char buf[] = {'0', '1', '2','3','4','5','6','7','8','9',
		'a','b','c','d','e','f','g','h','i','j','k','l',
		'm','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int r1, r2, r3, r4;
	time_t t;
	n = time(&t);
	srand(n);
	r1 = rand()%36;
	r2 = rand()%36;
	r3 = rand()%36;
	r4 = rand()%36;
	CString str;
	str.Format("%c%c%c%c", buf[r1],buf[r2],buf[r3],buf[r4]);
	return str;
}

CString C验证码生成Dlg::CreateRegionCode1()
{
	char buf[][3] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
		"a", "b", "c", "d", "e", "f" ,"g" ,"h" ,"i" ,"j" ,"k" ,"l",
		"m" ,"n" ,"o" ,"p" ,"q" ,"r" ,"s" ,"t" ,"u" ,"v" ,"w" ,"x" ,"y" ,"z",
		"格","且","汜","愉","就","经","宫","办","亿","纱"};
	int r1, r2, r3, r4;
	time_t t;
	n = time(&t);
	srand(n);
	r1 = rand()%46;
	r2 = rand()%46;
	r3 = rand()%46;
	r4 = rand()%46;
	CString str;
	str.Format("%s%s%s%s", buf[r1],buf[r2],buf[r3],buf[r4]); // 二维数组
	return str;
}

