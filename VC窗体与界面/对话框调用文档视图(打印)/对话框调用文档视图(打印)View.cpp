
// 对话框调用文档视图(打印)View.cpp : C对话框调用文档视图打印View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "对话框调用文档视图(打印).h"
#endif

#include "对话框调用文档视图(打印)Doc.h"
#include "对话框调用文档视图(打印)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern CString str1[9];

// C对话框调用文档视图打印View

IMPLEMENT_DYNCREATE(C对话框调用文档视图打印View, CView)

BEGIN_MESSAGE_MAP(C对话框调用文档视图打印View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C对话框调用文档视图打印View 构造/析构

C对话框调用文档视图打印View::C对话框调用文档视图打印View()
{
	// TODO: 在此处添加构造代码

}

C对话框调用文档视图打印View::~C对话框调用文档视图打印View()
{
}

BOOL C对话框调用文档视图打印View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C对话框调用文档视图打印View 绘制

void C对话框调用文档视图打印View::OnDraw(CDC* pDC)
{
	C对话框调用文档视图打印Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	font.CreatePointFont(140, "宋体", pDC);
	screenx = pDC->GetDeviceCaps(LOGPIXELSX);
	screeny = pDC->GetDeviceCaps(LOGPIXELSY);

	for (int i = 0; i<9; ++i)
	{
		pDC->SelectObject(&font);
		pDC->TextOut(80, 50+i*40, str1[i]);
	}
	font.DeleteObject();
}


// C对话框调用文档视图打印View 打印

BOOL C对话框调用文档视图打印View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C对话框调用文档视图打印View::OnBeginPrinting(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	printx = pDC->GetDeviceCaps(LOGPIXELSX);
	printy = pDC->GetDeviceCaps(LOGPIXELSY);
	ratex = (double)printx/screenx;
	ratey = (double)printy/screeny;
}

void C对话框调用文档视图打印View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C对话框调用文档视图打印View 诊断

#ifdef _DEBUG
void C对话框调用文档视图打印View::AssertValid() const
{
	CView::AssertValid();
}

void C对话框调用文档视图打印View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C对话框调用文档视图打印Doc* C对话框调用文档视图打印View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C对话框调用文档视图打印Doc)));
	return (C对话框调用文档视图打印Doc*)m_pDocument;
}
#endif //_DEBUG


// C对话框调用文档视图打印View 消息处理程序


void C对话框调用文档视图打印View::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	font.CreatePointFont(140,"宋体",pDC);
	for (int i = 0; i<9;++i)
	{
		pDC->SelectObject(&font);
		pDC->TextOut((int)(ratex*80), (int)(ratey*(50+i*40)),str1[i]);
	}
	font.DeleteObject();
	//CView::OnPrint(pDC, pInfo);
}
