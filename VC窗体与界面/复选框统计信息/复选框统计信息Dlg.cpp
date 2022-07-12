
// 复选框统计信息Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "复选框统计信息.h"
#include "复选框统计信息Dlg.h"
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


// C复选框统计信息Dlg 对话框




C复选框统计信息Dlg::C复选框统计信息Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C复选框统计信息Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C复选框统计信息Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHINA, m_ConChi);
	DDX_Control(pDX, IDC_ENG, m_ConEng);
	DDX_Control(pDX, IDC_F, m_ConF);
	DDX_Control(pDX, IDC_G, m_ConG);
	DDX_Control(pDX, IDC_HUA, m_ConHua);
	DDX_Control(pDX, IDC_JNP, m_ConJnp);
	DDX_Control(pDX, IDC_MATH, m_ConMat);
	DDX_Control(pDX, IDC_PHY, m_ConPhy);
}

BEGIN_MESSAGE_MAP(C复选框统计信息Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C复选框统计信息Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C复选框统计信息Dlg 消息处理程序

BOOL C复选框统计信息Dlg::OnInitDialog()
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
	m_ConChi.SetCheck(1);
	m_ConChi.EnableWindow(FALSE);
	m_ConMat.SetCheck(1);
	m_ConMat.EnableWindow(FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C复选框统计信息Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C复选框统计信息Dlg::OnPaint()
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
HCURSOR C复选框统计信息Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C复选框统计信息Dlg::OnBnClickedButton1()
{
	CString ID, Name;
	GetDlgItem(IDC_NUM)->GetWindowText(ID);
	GetDlgItem(IDC_NAME)->GetWindowText(Name);

	CString str,text;
	str = "学号:" +  ID + " 姓名:" + Name + "\r\n";
	m_ConChi.GetWindowText(text);str += "必修科目:" + text + "、";
	m_ConMat.GetWindowText(text);str += text + "\r\n";
	
	str += "选修科目:";

	for (int i = 0; i < 6; ++i)
	{
		CButton* but =(CButton*)GetDlgItem(IDC_ENG + i);
		if (but->GetCheck())
		{
			but->GetWindowText(text);
			str += text + "、"; 
		}
	}
	str = str.Left(str.GetLength()-2);
	
	MessageBox(str);
}
