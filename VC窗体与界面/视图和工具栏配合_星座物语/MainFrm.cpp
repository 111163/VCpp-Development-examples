
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "��������2.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
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
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	// TODO: �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	RECT rect,daterect;
	m_Static.Create("ѡ��������ڣ�",WS_CHILD|SS_CENTER,CRect(0,40,10,50),this,1234);
	m_wndToolBar.GetItemRect(0,&rect);
	m_Static.SetParent(&m_wndToolBar);
	m_Static.MoveWindow(rect.left,rect.top+5,rect.right-rect.left,rect.bottom-rect.top);
	m_Static.ShowWindow(SW_SHOW);
	m_Font.CreatePointFont(100,"����");
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

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


// CMainFrame ��Ϣ�������
