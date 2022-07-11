
// 浮动窗口View.cpp : C浮动窗口View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "浮动窗口.h"
#endif

#include "浮动窗口Doc.h"
#include "浮动窗口View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C浮动窗口View

IMPLEMENT_DYNCREATE(C浮动窗口View, CView)

BEGIN_MESSAGE_MAP(C浮动窗口View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C浮动窗口View 构造/析构

C浮动窗口View::C浮动窗口View()
{
	// TODO: 在此处添加构造代码

}

C浮动窗口View::~C浮动窗口View()
{
}

BOOL C浮动窗口View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C浮动窗口View 绘制

void C浮动窗口View::OnDraw(CDC* /*pDC*/)
{
	C浮动窗口Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C浮动窗口View 打印

BOOL C浮动窗口View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C浮动窗口View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C浮动窗口View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C浮动窗口View 诊断

#ifdef _DEBUG
void C浮动窗口View::AssertValid() const
{
	CView::AssertValid();
}

void C浮动窗口View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C浮动窗口Doc* C浮动窗口View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C浮动窗口Doc)));
	return (C浮动窗口Doc*)m_pDocument;
}
#endif //_DEBUG


// C浮动窗口View 消息处理程序
