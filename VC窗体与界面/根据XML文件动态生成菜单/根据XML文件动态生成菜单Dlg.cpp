
// 根据XML文件动态生成菜单Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "根据XML文件动态生成菜单.h"
#include "根据XML文件动态生成菜单Dlg.h"

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


// C根据XML文件动态生成菜单Dlg 对话框




C根据XML文件动态生成菜单Dlg::C根据XML文件动态生成菜单Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C根据XML文件动态生成菜单Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C根据XML文件动态生成菜单Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C根据XML文件动态生成菜单Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// C根据XML文件动态生成菜单Dlg 消息处理程序

BOOL C根据XML文件动态生成菜单Dlg::OnInitDialog()
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
	m_pXMLDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30)); 
	CString strFilePath=".\\menu.xml";
	BSTR szFileName=strFilePath.AllocSysString();
	m_pXMLDoc->load(szFileName);
	m_cMenu.CreateMenu();
	CreateMenuFromFile();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C根据XML文件动态生成菜单Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C根据XML文件动态生成菜单Dlg::OnPaint()
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
HCURSOR C根据XML文件动态生成菜单Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


 void C根据XML文件动态生成菜单Dlg::LoadSubMenu(CMenu* m_menu,CString str)
 {
 	CMenu m_tempmenu;
 	m_tempmenu.CreatePopupMenu();		
 	MSXML2::IXMLDOMElementPtr childNode;
 	MSXML2::IXMLDOMNodeListPtr nodelist=NULL;
 	nodelist = m_pCurNode->GetchildNodes();
 	long nodecount;
 	nodelist->get_length(&nodecount);
 	VARIANT varVal; 
 	CString csText = "";
 	//CString ss;ss.Format("%d",nodecount);MessageBox(ss);
 
 	for(int i=0;i<nodecount;i++)
 	{
 		m_pCurNode=nodelist->nextNode();
 		varVal = m_pCurNode->getAttribute("text");
 		csText= (char*)(_bstr_t)varVal;
 		m_tempmenu.AppendMenu(MF_STRING,-1,csText);
 		//if(m_pCurNode->hasChildNodes())
 		//LoadSubMenu(&m_cMenu,csText);
 		m_pCurNode->GetnextSibling(); // 放在这里没有必要
 	}	
 	m_cMenu.AppendMenu(MF_POPUP,(UINT)m_tempmenu.m_hMenu,str);
 	m_tempmenu.Detach();
 }
 void C根据XML文件动态生成菜单Dlg::CreateMenuFromFile()
 {
 	MSXML2::IXMLDOMElementPtr childNode;
 	childNode = m_pXMLDoc->selectSingleNode("MYMENU");
 	MSXML2::IXMLDOMNodeListPtr nodelist=NULL;
 	nodelist = childNode->GetchildNodes();
 	long nodecount;
 	nodelist->get_length(&nodecount);
 
 	VARIANT varVal; 
 	CString csText = "";
	for(int i=0;i<nodecount;i++)
	{
		m_pCurNode=nodelist->nextNode();
		varVal = m_pCurNode->getAttribute("text");
		csText= (char*)(_bstr_t)varVal;
		LoadSubMenu(&m_cMenu,csText);
		m_pCurNode->GetnextSibling(); // 放在这里没有必要
	}
 	SetMenu(&m_cMenu);
 }

BOOL C根据XML文件动态生成菜单Dlg::IsHaveSubMenu(CString strSubMenu)
{

	return false;
}


