// PreView.cpp : 实现文件
//

#include "stdafx.h"
#include "自定义打印预览工具栏.h"
#include "PreView.h"
#include "Resource.h"
#include "自定义打印预览工具栏View.h"

// CPreView

IMPLEMENT_DYNCREATE(CPreView, CPreviewView)

CPreView::CPreView()
{

}

CPreView::~CPreView()
{
}

BEGIN_MESSAGE_MAP(CPreView, CPreviewView)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CPreView 诊断

#ifdef _DEBUG
void CPreView::AssertValid() const
{
	CPreviewView::AssertValid();
}

#ifndef _WIN32_WCE
void CPreView::Dump(CDumpContext& dc) const
{
	CPreviewView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPreView 消息处理程序
void CPreView::OnPreviewClose()
{
	/*m_pToolBar->DestroyWindow();
	m_pToolBar = NULL;
	m_pPreviewInfo->m_nCurPage = m_nCurrentPage;
	m_pOrigView->OnEndPrintPreview(m_pPreviewDC, m_pPreviewInfo,CPoint(0, 0), this);*/
}

int CPreView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
 	if (CPreviewView::OnCreate(lpCreateStruct) == -1)
 		return -1;

	// TODO:  在此添加您专用的创建代码
	CCreateContext* pContext = (CCreateContext*)lpCreateStruct->lpCreateParams;

	m_print.SubclassDlgItem(AFX_ID_PREVIEW_PRINT,m_pToolBar);
	m_up.SubclassDlgItem(AFX_ID_PREVIEW_PREV,m_pToolBar);
	m_down.SubclassDlgItem(AFX_ID_PREVIEW_NEXT,m_pToolBar);
	m_exit.SubclassDlgItem(AFX_ID_PREVIEW_CLOSE,m_pToolBar);

	m_print.SetIcon(AfxGetApp()->LoadIcon(IDI_ICONP));
	m_up.SetIcon(AfxGetApp()->LoadIcon(IDI_ICONU));
	m_down.SetIcon(AfxGetApp()->LoadIcon(IDI_ICOND));
	m_exit.SetIcon(AfxGetApp()->LoadIcon(IDI_ICONE));

	m_pOrigView = (C自定义打印预览工具栏View*)pContext->m_pLastView;
	ASSERT(m_pOrigView != NULL);
	ASSERT_KINDOF(C自定义打印预览工具栏View, m_pOrigView);

	return 0;
}
