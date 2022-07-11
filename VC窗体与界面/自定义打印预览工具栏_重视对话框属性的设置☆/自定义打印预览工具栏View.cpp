
// 自定义打印预览工具栏View.cpp : C自定义打印预览工具栏View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "自定义打印预览工具栏.h"
#endif

#include "自定义打印预览工具栏Doc.h"
#include "自定义打印预览工具栏View.h"
#include "PreView.h"
//#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C自定义打印预览工具栏View

IMPLEMENT_DYNCREATE(C自定义打印预览工具栏View, CView)

BEGIN_MESSAGE_MAP(C自定义打印预览工具栏View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, OnFilePrintPreview)
END_MESSAGE_MAP()

// C自定义打印预览工具栏View 构造/析构

C自定义打印预览工具栏View::C自定义打印预览工具栏View()
{
	// TODO: 在此处添加构造代码

}

C自定义打印预览工具栏View::~C自定义打印预览工具栏View()
{
}

BOOL C自定义打印预览工具栏View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C自定义打印预览工具栏View 绘制

void C自定义打印预览工具栏View::OnDraw(CDC* /*pDC*/)
{
	C自定义打印预览工具栏Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C自定义打印预览工具栏View 打印

BOOL C自定义打印预览工具栏View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	//pInfo->SetMaxPage(3);
	return DoPreparePrinting(pInfo);
}

void C自定义打印预览工具栏View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C自定义打印预览工具栏View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C自定义打印预览工具栏View 诊断

#ifdef _DEBUG
void C自定义打印预览工具栏View::AssertValid() const
{
	CView::AssertValid();
}

void C自定义打印预览工具栏View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C自定义打印预览工具栏Doc* C自定义打印预览工具栏View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C自定义打印预览工具栏Doc)));
	return (C自定义打印预览工具栏Doc*)m_pDocument;
}
#endif //_DEBUG


// C自定义打印预览工具栏View 消息处理程序
void C自定义打印预览工具栏View::OnFilePrintPreview()
{
	CPrintPreviewState* pState = new CPrintPreviewState;
	if(!DoPrintPreview(IDD_TOOLBARDIALOG, this, RUNTIME_CLASS(CPreView), pState))//AFX_IDD_PREVIEW_TOOLBAR
	{
		TRACE0("Error: DoPrintPreview failed.\n");
		AfxMessageBox(AFX_IDP_COMMAND_FAILURE);
		delete pState;    
	}
}
