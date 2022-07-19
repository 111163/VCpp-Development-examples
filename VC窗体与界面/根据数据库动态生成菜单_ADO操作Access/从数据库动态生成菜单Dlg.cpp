
// 从数据库动态生成菜单Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "从数据库动态生成菜单.h"
#include "从数据库动态生成菜单Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern _ConnectionPtr m_pCon;
extern _RecordsetPtr m_pRecord;


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


// C从数据库动态生成菜单Dlg 对话框




C从数据库动态生成菜单Dlg::C从数据库动态生成菜单Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C从数据库动态生成菜单Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C从数据库动态生成菜单Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C从数据库动态生成菜单Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// C从数据库动态生成菜单Dlg 消息处理程序

BOOL C从数据库动态生成菜单Dlg::OnInitDialog()
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
	m_menu.CreateMenu();
	LoadMenuFromDatabase();

	//SetMenu(&m_Menu);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C从数据库动态生成菜单Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C从数据库动态生成菜单Dlg::OnPaint()
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
HCURSOR C从数据库动态生成菜单Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL C从数据库动态生成菜单Dlg::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetWindowRect(&rect);
	CBitmap m_Bitmap;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	memDC.SelectObject(&m_Bitmap);

	CBitmap* bmp = NULL;
	pDC->BitBlt(0,0,rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);
	if (bmp) memDC.SelectObject(bmp);
	return TRUE;
	//return CDialogEx::OnEraseBkgnd(pDC);
}


void C从数据库动态生成菜单Dlg::LoadMenuFromDatabase(void)
{
	CString sql;
	sql.Format( "select * from tb_menuinfo where 上级菜单 is NULL"); // 菜单的栏目是没有父级的
	m_pRecord = m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	CString c_menustr;
	while (! m_pRecord->ADOEOF)
	{
		c_menustr = m_pRecord->GetCollect("菜单名称").bstrVal;
		LoadSubMenu(&m_menu,c_menustr);	
		m_pRecord->MoveNext();
	}
	SetMenu(&m_menu);
}


void C从数据库动态生成菜单Dlg::LoadSubMenu(CMenu* m_menu, CString str)
{
	_ConnectionPtr m_con;
	_RecordsetPtr m_record;
	m_con.CreateInstance("ADODB.Connection");
	m_record.CreateInstance("ADODB.Recordset");
	m_con->ConnectionString = m_pCon->ConnectionString;
	m_con->Open("","","",-1);
	CString sql;
	sql.Format("select * from tb_menuinfo where 上级菜单 = '%s'",str);
	m_record = m_con->Execute((_bstr_t)sql,NULL,adCmdText);
	CMenu m_tempmenu;
	m_tempmenu.CreatePopupMenu();

	while (!m_record->ADOEOF)
	{
		CString c_menustr;
		c_menustr = m_record->GetCollect("菜单名称").bstrVal;
		m_tempmenu.AppendMenu(MF_STRING,-1,c_menustr);  // 菜单项
		if (IsHaveSubMenu(c_menustr))
			LoadSubMenu(&m_tempmenu,c_menustr);
		m_record->MoveNext();
	}

	m_menu->AppendMenu(MF_POPUP,(UINT)m_tempmenu.m_hMenu,str); // 弹出菜单加入到菜单
	m_tempmenu.Detach();

	if (m_record != NULL)
		m_record.Release();
	if (m_con!= NULL)
		m_con.Release();
}





BOOL C从数据库动态生成菜单Dlg::IsHaveSubMenu(CString str)
{
	_ConnectionPtr m_con;
	_RecordsetPtr m_record;
	m_con.CreateInstance("ADODB.Connection");
	m_record.CreateInstance("ADODB.Recordset");
	m_con->ConnectionString = m_pCon->ConnectionString;
	m_con->Open("","","",-1);
	CString sql;
	sql.Format("select * from tb_menuinfo where 上级菜单 = '%s'",str);
	m_record = m_con->Execute((_bstr_t)sql,NULL,adCmdText);
	if ((!m_record->BOF) && (! m_record->ADOEOF))
	{
		return TRUE;
	}
	return FALSE;
}
