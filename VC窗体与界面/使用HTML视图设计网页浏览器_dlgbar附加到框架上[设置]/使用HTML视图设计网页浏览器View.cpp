
// 使用HTML视图设计网页浏览器View.cpp : C使用HTML视图设计网页浏览器View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "使用HTML视图设计网页浏览器.h"
#endif

#include "使用HTML视图设计网页浏览器Doc.h"
#include "使用HTML视图设计网页浏览器View.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C使用HTML视图设计网页浏览器View

IMPLEMENT_DYNCREATE(C使用HTML视图设计网页浏览器View, CHtmlView)

BEGIN_MESSAGE_MAP(C使用HTML视图设计网页浏览器View, CHtmlView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_BN_CLICKED(IDC_BTBACK, &C使用HTML视图设计网页浏览器View::OnBnClickedBtback)
	ON_BN_CLICKED(IDC_BTFORWARD, &C使用HTML视图设计网页浏览器View::OnBnClickedBtforward)
	ON_BN_CLICKED(IDC_BTSTOP, &C使用HTML视图设计网页浏览器View::OnBnClickedBtstop)
	ON_BN_CLICKED(IDC_BTREFRESH, &C使用HTML视图设计网页浏览器View::OnBnClickedBtrefresh)
	ON_BN_CLICKED(IDC_BTGOTO, &C使用HTML视图设计网页浏览器View::OnBnClickedBtgoto)
	ON_EN_CHANGE(IDC_EDADDRESS, &C使用HTML视图设计网页浏览器View::OnEnChangeEdaddress)
END_MESSAGE_MAP()

// C使用HTML视图设计网页浏览器View 构造/析构

C使用HTML视图设计网页浏览器View::C使用HTML视图设计网页浏览器View()
{
	// TODO: 在此处添加构造代码

}

C使用HTML视图设计网页浏览器View::~C使用HTML视图设计网页浏览器View()
{
}

BOOL C使用HTML视图设计网页浏览器View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CHtmlView::PreCreateWindow(cs);
}

void C使用HTML视图设计网页浏览器View::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("https://gitee.com/may_you_marry_in_red_admin/dashboard/projects"),NULL,NULL);
}


// C使用HTML视图设计网页浏览器View 打印



// C使用HTML视图设计网页浏览器View 诊断

#ifdef _DEBUG
void C使用HTML视图设计网页浏览器View::AssertValid() const
{
	CHtmlView::AssertValid();
}

void C使用HTML视图设计网页浏览器View::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

C使用HTML视图设计网页浏览器Doc* C使用HTML视图设计网页浏览器View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C使用HTML视图设计网页浏览器Doc)));
	return (C使用HTML视图设计网页浏览器Doc*)m_pDocument;
}
#endif //_DEBUG


// C使用HTML视图设计网页浏览器View 消息处理程序


void C使用HTML视图设计网页浏览器View::OnBnClickedBtback()
{
	GoBack();
}


void C使用HTML视图设计网页浏览器View::OnBnClickedBtforward()
{
	GoForward();
}


void C使用HTML视图设计网页浏览器View::OnBnClickedBtstop()
{
	Stop();
}


void C使用HTML视图设计网页浏览器View::OnBnClickedBtrefresh()
{
	Refresh();
}


void C使用HTML视图设计网页浏览器View::OnBnClickedBtgoto()
{
	Navigate2(m_StrPath, NULL, NULL);
	Invalidate(FALSE);
}


void C使用HTML视图设计网页浏览器View::OnEnChangeEdaddress()
{
	CMainFrame *pw = (CMainFrame*)AfxGetMainWnd();
	CDialogBar *pd = &(pw->m_wndDlgBar);
	pd->GetDlgItemText(IDC_EDADDRESS, m_StrPath);
}
