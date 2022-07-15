
// 编辑框输入时列表框也显示Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "编辑框输入时列表框也显示.h"
#include "编辑框输入时列表框也显示Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

 bool enter=false;
 int i=0;
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


// C编辑框输入时列表框也显示Dlg 对话框




C编辑框输入时列表框也显示Dlg::C编辑框输入时列表框也显示Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C编辑框输入时列表框也显示Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C编辑框输入时列表框也显示Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ConList);
	DDX_Control(pDX, IDC_EDIT1, m_ConEdit);
}

BEGIN_MESSAGE_MAP(C编辑框输入时列表框也显示Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &C编辑框输入时列表框也显示Dlg::OnEnChangeEdit1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &C编辑框输入时列表框也显示Dlg::OnDblclkList1)
END_MESSAGE_MAP()


// C编辑框输入时列表框也显示Dlg 消息处理程序

BOOL C编辑框输入时列表框也显示Dlg::OnInitDialog()
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

	m_ConList.ModifyStyle(0L, LVS_REPORT);
	m_ConList.ModifyStyle(0L, LVS_SHOWSELALWAYS);
	m_ConList.ModifyStyle(0L, LVS_NOSORTHEADER);
	m_ConList.SetExtendedStyle(LVS_EX_GRIDLINES); // 网格风格
	m_ConList.InsertColumn(0, "姓名");
	m_ConList.InsertColumn(1, "性别");
	m_ConList.InsertColumn(2, "出生日期");

	m_ConList.SetColumnWidth(0,50);
	m_ConList.SetColumnWidth(1,50);
	m_ConList.SetColumnWidth(2,100);

	m_ConEdit.MoveWindow(15,15,150,21);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C编辑框输入时列表框也显示Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C编辑框输入时列表框也显示Dlg::OnPaint()
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
HCURSOR C编辑框输入时列表框也显示Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void C编辑框输入时列表框也显示Dlg::SetDataBase(CString sql)
{
	::CoInitialize(NULL);
	m_pConnection=NULL;
	m_pConnection.CreateInstance(__uuidof(Connection)); 
	// 因为有覆盖问题就是Open中的密码和用户名会覆盖ConnectionString中的，所以统一将密码和用户名写到Open中
	// 而ConnectionString中只做 驱动 路径 连接名指定打开客户端连接时使用的提供者名称（仅限于远程数据服务）指定打开客户端连接时使用的服务器的路径名称（仅限于远程数据服务）设定
	m_pConnection->ConnectionString="Provider=Microsoft.ACE.OLEDB.12.0;Data Source=mrdb.accdb;";//uid=;pwd=;
	m_pConnection->Open(L"",L"",L"",adCmdUnspecified);
	CString text;
	text.Format("select * from info where xm like '%s%%'",sql);
	m_pRecordset=m_pConnection->Execute((_bstr_t)text,NULL,adCmdText);
	if(m_pRecordset->GetRecordCount()==0)
	{m_ConList.ShowWindow(SW_HIDE);}
	int i=0;
	while(!m_pRecordset->adoEOF)
	{
		xm=(char*)(_bstr_t)m_pRecordset->GetCollect("xm");
		xb=(char*)(_bstr_t)m_pRecordset->GetCollect("xb");
		csrq=(char*)(_bstr_t)m_pRecordset->GetCollect("csrq");
		gzdw=(char*)(_bstr_t)m_pRecordset->GetCollect("gzdw");
		yddh=(char*)(_bstr_t)m_pRecordset->GetCollect("yddh");
		gddh=(char*)(_bstr_t)m_pRecordset->GetCollect("gddh");
		m_ConList.InsertItem(i,"");
		m_ConList.SetItemText(i,0,xm);
		m_ConList.SetItemText(i,1,xb);
		m_ConList.SetItemText(i,2,csrq);
		m_ConList.SetItemText(i,3,gzdw);
		m_ConList.SetItemText(i,4,yddh);
		m_ConList.SetItemText(i,5,gddh);
		i+=1;
		m_pRecordset->MoveNext();
	}
	m_pRecordset->Close();
	m_pConnection->Close();
	m_pRecordset=NULL;
	m_pConnection=NULL;
	::CoUninitialize();
}


BOOL C编辑框输入时列表框也显示Dlg::PreTranslateMessage(MSG* pMsg) // 对键盘鼠标消息的处理
{
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE) // 按下回车键
	{
		m_ConList.ShowWindow(SW_HIDE);
		IsShowing=false;
		pMsg->wParam=VK_CONTROL;  // 现在这个键值被处理了，我们就给它赋一个无用的值，防止它被再次处理
	}
	if (pMsg->message==WM_LBUTTONDOWN)  // 按下左键，并且不在列表范围内，列表消失
	{
		if (pMsg->hwnd!= m_ConList.m_hWnd)
		{m_ConList.ShowWindow(SW_HIDE);
		IsShowing=false;}
	}
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==13) // 按下确认键
	{	
		if(IsShowing)
			m_ConEdit.SetWindowText(xm);
		m_ConList.ShowWindow(SW_HIDE);
		IsShowing=false;
		i=0;
		pMsg->wParam=VK_CONTROL;
	}
	if(pMsg->hwnd==m_ConList.m_hWnd&& pMsg->message==WM_LBUTTONDBLCLK) // 左键双击(这里捕获的是在列表外的双击)
	{
		m_ConEdit.SetWindowText(xm);
		m_ConList.ShowWindow(SW_HIDE);
		IsShowing=false;
	}
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_DOWN) // ↓按钮
	{
		if(IsShowing) // 如果当前是显示状态，就要在姓名上移动
		{
			if(i==m_ConList.GetItemCount())
				i=0;
			m_ConList.SetHotItem(i);
			xm=m_ConList.GetItemText(i,0);
			i+=1;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}



void C编辑框输入时列表框也显示Dlg::AutoPostion()  // 定位列表，规定大小
{
	this->m_ConList.MoveWindow(15,36,210,100);
}


void C编辑框输入时列表框也显示Dlg::OnEnChangeEdit1() // 当Edit中的
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	CString edit;
	m_ConEdit.GetWindowText(edit);
	if (!edit.IsEmpty())
	{
		this->AutoPostion();
		m_ConList.DeleteAllItems();
		this->SetDataBase(edit);
		if (m_ConList.GetItemCount()>0) // 根据从数据库中读取值来填充列表，看列表是否为空，来判断是否显示列表
		{
			m_ConList.ShowWindow(SW_SHOW);
			IsShowing = TRUE;
		}
	}
	else
	{
		m_ConList.ShowWindow(SW_HIDE);
		IsShowing = FALSE;
	}
}


void C编辑框输入时列表框也显示Dlg::OnDblclkList1(NMHDR *pNMHDR, LRESULT *pResult) // 向CListCtrl的发送双击消息(NM_DBLCLK)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	int i=m_ConList.GetHotItem(); // 获取到点击位置
	CString text;
	xm=m_ConList.GetItemText(i,1); // 获取到点击位置的节点的值
	

	*pResult = 0;
}

