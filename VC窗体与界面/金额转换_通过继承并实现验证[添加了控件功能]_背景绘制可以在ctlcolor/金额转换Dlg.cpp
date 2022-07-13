
// 金额转换Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "金额转换.h"
#include "金额转换Dlg.h"
#include "afxdialogex.h"
#include <WinUser.h>

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


// C金额转换Dlg 对话框




C金额转换Dlg::C金额转换Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C金额转换Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_StrEdit2 = _T("");
}

void C金额转换Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_ConInp);
	//  DDX_Control(pDX, IDC_EDIT2, m_ConOut);
	//  DDX_Control(pDX, IDC_EDIT2, m_StrEdit2);
	DDX_Text(pDX, IDC_EDIT2, m_StrEdit2);
}

BEGIN_MESSAGE_MAP(C金额转换Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C金额转换Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C金额转换Dlg 消息处理程序

BOOL C金额转换Dlg::OnInitDialog()
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
	CButton* bTn =(CButton*) GetDlgItem(IDC_BUTTON1);
	bTn->SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP2)));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C金额转换Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C金额转换Dlg::OnPaint()
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
HCURSOR C金额转换Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


CString C金额转换Dlg::Capitalization(CString str)
{
	str.Replace("0","零");
	str.Replace("1","壹");
	str.Replace("2","贰");
	str.Replace("3","叁");
	str.Replace("4","肆");
	str.Replace("5","伍");
	str.Replace("6","陆");
	str.Replace("7","柒");
	str.Replace("8","捌");
	str.Replace("9","玖");
	return str;
}

void C金额转换Dlg::ChangeMoney(CString str,int num)
{
	CString string[30];
	CString rstr;
	for(int i=1;i<=num;i++)
	{
		rstr = str.Right(1);
		string[2*num-2*(i-1)-1] = Capitalization(rstr);
		str = str.Left(num-i);
		switch(i)
		{
		case 1:
			string[2*num-2*(i-1)] = "元";
			break;
		case 2:
		case 6:
		case 10:
			string[2*num-2*(i-1)] = "拾";
			break;
		case 3:
		case 7:
		case 11:
			string[2*num-2*(i-1)] = "佰";
			break;
		case 4:
		case 8:
		case 12:
			string[2*num-2*(i-1)] = "仟";
			break;
		case 5:
			string[2*num-2*(i-1)] = "万";
			break;
		case 9:
			string[2*num-2*(i-1)] = "亿";
			break;
		}
	}
	for(int i=0;i<=2*num;i++)
		m_StrEdit2 += string[i];
}




void C金额转换Dlg::OnBnClickedButton1()
{
	m_StrEdit2 = "";
	CString str,lstr,rstr;
	CString string[4];
	string[1] = "角";
	string[3] = "分";
	m_ConInp.GetWindowText(str);
	int n,m;
	m = str.GetLength();
	n = str.Find('.',0);
	if(n == -1)
	{
		if(m > 12)
		{
			MessageBox("你输入的金额太大");
			return;
		}
		ChangeMoney(str,m);
	}
	else
	{
		if(m > 12)
		{
			MessageBox("你输入的金额太大");
			return;
		}
		lstr = str.Left(n);
		ChangeMoney(lstr,n);
		if(m-n == 3)
		{
			rstr = str.Right(2);
			lstr = rstr.Left(1);
			rstr = rstr.Right(1);
			string[0] = Capitalization(lstr);
			string[2] = Capitalization(rstr);
		}
		if(m-n == 2)
		{
			rstr = str.Right(1);
			string[0] = Capitalization(rstr);
		}
		for(int i=0;i<2*(m-n-1);i++)
			m_StrEdit2 += string[i];
	}
	UpdateData(FALSE);
}
