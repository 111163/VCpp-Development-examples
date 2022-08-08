
// API操作注册表Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "API操作注册表.h"
#include "API操作注册表Dlg.h"
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


// CAPI操作注册表Dlg 对话框




CAPI操作注册表Dlg::CAPI操作注册表Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAPI操作注册表Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAPI操作注册表Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_KEYNAME, m_KeyName);
	DDX_Control(pDX, IDC_ITEMVALUE, m_ItemValue);
	DDX_Control(pDX, IDC_ITEMNAME, m_ItemName);
}

BEGIN_MESSAGE_MAP(CAPI操作注册表Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OK, &CAPI操作注册表Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_READ, &CAPI操作注册表Dlg::OnBnClickedRead)
END_MESSAGE_MAP()


// CAPI操作注册表Dlg 消息处理程序

BOOL CAPI操作注册表Dlg::OnInitDialog()
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

void CAPI操作注册表Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAPI操作注册表Dlg::OnPaint()
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
HCURSOR CAPI操作注册表Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAPI操作注册表Dlg::OnBnClickedOk()
{
	HKEY hroot;
	DWORD action;
	CString keyname;
	m_KeyName.GetWindowText(keyname);
	keyname +="\\";
	RegCreateKeyEx(HKEY_CURRENT_USER, keyname, 0, NULL, 0, KEY_WRITE, NULL, &hroot, &action); //////////////////////////////////////////////////////////////////////////
	CString itemname;
	m_ItemName.GetWindowText(itemname);		
	CString itemvalue;
	m_ItemValue.GetWindowText(itemvalue);
	DWORD size = itemvalue.GetLength();
	if (ERROR_SUCCESS == RegSetValueEx(hroot, itemname, 0, REG_SZ, (unsigned char*)itemvalue.GetBuffer(0), size)) //////////////////////////////////////////////////////////////////////////
		MessageBox("Successful");
	RegCloseKey(hroot); //////////////////////////////////////////////////////////////////////////
}


void CAPI操作注册表Dlg::OnBnClickedRead()
{
	HKEY hroot;
	CString keyname;
	m_KeyName.GetWindowText(keyname);
	RegOpenKeyEx(HKEY_CURRENT_USER, keyname, 0, KEY_READ, &hroot); //////////////////////////////////////////////////////////////////////////


	CString itemname;
	m_ItemName.GetWindowText(itemname);		
	CString itemvalue;
	DWORD type = REG_SZ;
	unsigned char data[MAX_PATH]= "temp";                                                                    //定义一个字符串变量
	DWORD size = MAX_PATH;                                                                //设置字符串代码


	RegQueryValueEx(hroot, itemname, 0, &type, data, &size); //////////////////////////////////////////////////////////////////////////
	MessageBox(CString(data), "提示");
	LONG flg = RegDeleteValue(hroot, keyname); //////////////////////////////////////////////////////////////////////////
	if (ERROR_SUCCESS == flg) //---------------------------注意这里就涉及到RegOpenKeyEx时的权限了，如果要删除项，需要KEY_WRITE权限才行
		MessageBox("删除表项成功", "提示");
	else
	{
		CString tmp;
		tmp.Format("%d", flg);
		MessageBox(tmp, "没有删除");
	}
	RegCloseKey(hroot);
	RegDeleteKey(HKEY_CURRENT_USER, keyname); //////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////带EX 的操作的是打开的注册表句柄, 不带EX 的操作的是 父键-子键 形式
}
