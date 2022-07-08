
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "星座物语2.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	RECT rect,daterect;
	m_Static.Create("选择出生日期：",WS_CHILD|SS_CENTER,CRect(0,40,10,50),this,1234);
	m_wndToolBar.GetItemRect(0,&rect);
	m_Static.SetParent(&m_wndToolBar);
	m_Static.MoveWindow(rect.left,rect.top+5,rect.right-rect.left,rect.bottom-rect.top);
	m_Static.ShowWindow(SW_SHOW);
	m_Font.CreatePointFont(100,"宋体");
	m_Static.SetFont(&m_Font);

	m_Date.Create(WS_CHILD|WS_BORDER,CRect(0,40,10,50),this,1235);
	m_wndToolBar.GetItemRect(1,&daterect);
	m_Date.SetParent(&m_wndToolBar);
	m_Date.MoveWindow(&daterect);
	m_Date.ShowWindow(SW_SHOW);
	m_Date.SetFocus();



	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序
