
// ClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Client.h"
#include "ClientDlg.h"
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


// CClientDlg 对话框




CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CClientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_MsgList);
	DDX_Control(pDX, IDC_SERVERIP, m_ServerIP);
	DDX_Control(pDX, IDC_SERVERPORT, m_ServerPort);
	DDX_Control(pDX, IDC_NICKNAME, m_NickName);
	DDX_Control(pDX, IDC_SENDDATA, m_SendData);
}

BEGIN_MESSAGE_MAP(CClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOGIN, &CClientDlg::OnBnClickedLogin)
	ON_BN_CLICKED(IDC_SEND, &CClientDlg::OnBnClickedSend)
	ON_MESSAGE(CM_RECEIVE, ReceiveInfo)
END_MESSAGE_MAP()


// CClientDlg 消息处理程序

BOOL CClientDlg::OnInitDialog()
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
	m_SockClient = socket(AF_INET, SOCK_STREAM, 0);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CClientDlg::OnPaint()
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
HCURSOR CClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CClientDlg::OnBnClickedLogin()
{
	// TODO: 在此添加控件通知处理程序代码
	sockaddr_in serveraddr;
	CString strport;
	m_ServerPort.GetWindowText(strport);
	m_ServerIP.GetWindowText(m_IP);
	if (strport.IsEmpty() || m_IP.IsEmpty())
	{
		MessageBox("请设置服务器IP和端口号");
		return;
	}
	m_Port = atoi(strport);

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(m_Port);
	serveraddr.sin_addr.S_un.S_addr = inet_addr(m_IP);

	if (connect(m_SockClient, (sockaddr*)&serveraddr, sizeof(serveraddr))!= 0)
	{
		MessageBox("连接失败");
		return;
	}
// 	else
// 		MessageBox("连接成功");
	WSAAsyncSelect(m_SockClient, m_hWnd, CM_RECEIVE, FD_READ|FD_WRITE|FD_CONNECT);
	CString strname, info;
	m_NickName.GetWindowText(strname);
	info.Format("%s------>%s", strname, "进入聊天室");
	send(m_SockClient, info.GetBuffer(0), info.GetLength(), 0);
}


void CClientDlg::OnBnClickedSend()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strData, name, info;
	m_NickName.GetWindowText(name);
	m_SendData.GetWindowText(strData);
	if (!name.IsEmpty() && !strData.IsEmpty())
	{
		info.Format("%s说:%s", name, strData);
		send(m_SockClient, info.GetBuffer(0), info.GetLength(), 0);
		m_MsgList.AddString(info);
		m_SendData.SetWindowText("");
	}
}

LRESULT  CClientDlg::ReceiveInfo(WPARAM, LPARAM)
{
	char buffer[1024] = {0} ;
	int num = recv(m_SockClient, buffer, 1024, 0);
	//buffer[num] = 0;
	int a = strlen(buffer);
	if (strlen(buffer))
		m_MsgList.AddString(buffer);
	return 0;
}
