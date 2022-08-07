
// ini文件的操作Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ini文件的操作.h"
#include "ini文件的操作Dlg.h"
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


// Cini文件的操作Dlg 对话框




Cini文件的操作Dlg::Cini文件的操作Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cini文件的操作Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cini文件的操作Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_IP);
	DDX_Control(pDX, IDC_EDIT2, m_Database);
	DDX_Control(pDX, IDC_EDIT3, m_UID);
	DDX_Control(pDX, IDC_EDIT4, m_PWD);
	DDX_Control(pDX, IDC_EDIT5, m_ID);
}

BEGIN_MESSAGE_MAP(Cini文件的操作Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cini文件的操作Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cini文件的操作Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// Cini文件的操作Dlg 消息处理程序

BOOL Cini文件的操作Dlg::OnInitDialog()
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
	CFileFind finder;
	if (!finder.FindFile(".\\xxx.ini"))   //查询文件是否存在也是很重要的一项事情
	{
		WritePrivateProfileString("XXX", "IP", "192.168.0.0", ".\\xxx.ini");
		WritePrivateProfileString("XXX", "Database", "RoadNetData", ".\\xxx.ini");
		WritePrivateProfileString("XXX", "UID", "sa", ".\\xxx.ini");
		WritePrivateProfileString("XXX", "PWD", "4814278", ".\\xxx.ini");
		WritePrivateProfileString("XXX", "ID", "001", ".\\xxx.ini");
	}

	//////////////////////////////////////////////////////////////////////////
	// 这里是完全读取，是可以抽象出来到一个函数的
	CHAR bufName[256] = {0}, *pbufName = bufName; // memset也可以初始化
	int a = sizeof(bufName);
	CHAR bufSec[256] = {0}, *pbufSec = bufSec;
	GetPrivateProfileSectionNames(bufName, sizeof(bufName), ".\\xxx.ini");  // 得到 节
	while(strcmp(pbufName, ""))
	{
		GetPrivateProfileSection(pbufName, bufSec, sizeof(bufSec), ".\\xxx.ini"); // 得到 key-value
		while(strcmp(pbufSec, ""))
		{
			CString tmp = pbufSec;
			CString m_key;
			int pos = tmp.Find("=");
			m_key = tmp.Left(pos);
			/*  // 获取到所以的节下所有的键名和键值，通过 = 区分键和值 知道了节
			CString m_value;
			m_value = tmp.Right(tmp.GetLength() - pos - 1);
			*/
			///// 通过键直接获取值(CString类型的值)  ---知道了键获取值
			CHAR m_value[30];
			GetPrivateProfileString(pbufName, m_key, NULL, m_value , sizeof(m_value), ".\\xxx.ini");
			////
			if (m_key == "IP") m_IP.SetWindowText(m_value);
			if (m_key == "Database") m_Database.SetWindowText(m_value);
			if (m_key == "UID") m_UID.SetWindowText(m_value);
			if (m_key == "PWD") m_PWD.SetWindowText(m_value);
			if (m_key == "ID") m_ID.SetWindowText(m_value);

			if (m_key == "PWD")
			{
				int b = GetPrivateProfileInt(pbufName, m_key, -1, ".\\xxx.ini"); // 获取到数字，实际上和取得键值的值后转整型是一样的
				CString tmpt;
				tmpt.Format("%d", b);
				AfxMessageBox(tmpt);
			}
			
			pbufSec += strlen(pbufSec) + 1;
		}

		pbufName += strlen(pbufName)+1;
	}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cini文件的操作Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cini文件的操作Dlg::OnPaint()
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
HCURSOR Cini文件的操作Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cini文件的操作Dlg::OnBnClickedButton1()
{
	CDialogEx::OnCancel();
}


void Cini文件的操作Dlg::OnBnClickedButton2() // 设置配置—修改配置
{
	// TODO: 在此添加控件通知处理程序代码
	CString tmp;
	m_IP.GetWindowText(tmp);
	WritePrivateProfileString("XXX", "IP", tmp, ".\\xxx.ini");
	m_Database.GetWindowText(tmp);
	WritePrivateProfileString("XXX", "Database", tmp, ".\\xxx.ini");
	m_UID.GetWindowText(tmp);
	WritePrivateProfileString("XXX", "UID", tmp, ".\\xxx.ini");
	m_PWD.GetWindowText(tmp);
	WritePrivateProfileString("XXX", "PWD", tmp, ".\\xxx.ini");
	m_ID.GetWindowText(tmp);
	WritePrivateProfileString("XXX", "ID", tmp, ".\\xxx.ini");
}
