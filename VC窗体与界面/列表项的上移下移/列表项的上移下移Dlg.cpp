
// 列表项的上移下移Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "列表项的上移下移.h"
#include "列表项的上移下移Dlg.h"
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


// C列表项的上移下移Dlg 对话框




C列表项的上移下移Dlg::C列表项的上移下移Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C列表项的上移下移Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C列表项的上移下移Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ConListBox);
	DDX_Control(pDX, IDC_DOWN, m_ConDown);
	DDX_Control(pDX, IDC_UP, m_ConUp);
}

BEGIN_MESSAGE_MAP(C列表项的上移下移Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_UP, &C列表项的上移下移Dlg::OnBnClickedUp)
	ON_BN_CLICKED(IDC_DOWN, &C列表项的上移下移Dlg::OnBnClickedDown)
END_MESSAGE_MAP()


// C列表项的上移下移Dlg 消息处理程序

BOOL C列表项的上移下移Dlg::OnInitDialog()
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
	m_ConListBox.AddString("帘外雨潺潺");
	m_ConListBox.AddString("春意阑珊");
	m_ConListBox.AddString("罗衾不耐五更寒");
	m_ConListBox.AddString("梦里不知身是客");
	m_ConListBox.AddString("一晌贪欢");
	m_ConListBox.AddString("独自莫凭栏");
	m_ConListBox.AddString("无限江山");
	m_ConListBox.AddString("别时容易见时难");
	m_ConListBox.AddString("流水落花春去也");
	m_ConListBox.AddString("天上人间");

	m_ConUp.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP3)));
	m_ConDown.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP2)));
	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C列表项的上移下移Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C列表项的上移下移Dlg::OnPaint()
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
HCURSOR C列表项的上移下移Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C列表项的上移下移Dlg::OnBnClickedUp()
{
	// TODO: 在此添加控件通知处理程序代码
	int pos = m_ConListBox.GetCurSel();
	if(pos < 0)
	{
		MessageBox("请选择要移动的文件！");
		return;
	}
	if(pos == 0)								//如果索引为0
	{
		MessageBox("已经是最上边了！");			//提示是第一个文件
		return;
	}
	CString Text;
	m_ConListBox.GetText(pos-1, Text);
	m_ConListBox.DeleteString(pos-1);
	m_ConListBox.InsertString(pos, Text);
}


void C列表项的上移下移Dlg::OnBnClickedDown()
{
	// TODO: 在此添加控件通知处理程序代码
	int pos = m_ConListBox.GetCurSel();
	if(pos < 0)
	{
		MessageBox("请选择要移动的文件！");
		return;
	}
	if(pos >= m_ConListBox.GetCount()-1)								//如果索引为最大
	{
		MessageBox("已经是最下边了！");			//提示是最后一个文件
		return;
	}
	CString Text;
	m_ConListBox.GetText(pos+1, Text);
	m_ConListBox.DeleteString(pos+1);
	m_ConListBox.InsertString(pos, Text);
}
