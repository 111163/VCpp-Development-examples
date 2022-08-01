
// 绘制饼图View.cpp : C绘制饼图View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "绘制饼图.h"
#endif

#include "绘制饼图Doc.h"
#include "绘制饼图View.h"
#include "Input.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C绘制饼图View

IMPLEMENT_DYNCREATE(C绘制饼图View, CView)

BEGIN_MESSAGE_MAP(C绘制饼图View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C绘制饼图View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_INPUT, &C绘制饼图View::OnInput)
END_MESSAGE_MAP()

// C绘制饼图View 构造/析构

C绘制饼图View::C绘制饼图View()
{
	// TODO: 在此处添加构造代码
	m_centerX = "";
	m_centerY = "";
	m_radius = "";
	m_startAngle = "";
	m_sweepAngle = "";
	m_Draw = FALSE;

}

C绘制饼图View::~C绘制饼图View()
{
}

BOOL C绘制饼图View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C绘制饼图View 绘制

void C绘制饼图View::OnDraw(CDC* pDC)
{
	C绘制饼图Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (m_Draw)
	{
		int x, y, iRadius;
		x = atoi(m_centerX);
		y = atoi(m_centerY);
		iRadius = atoi(m_radius);
		float fStartAngle,fSweepAngle;
		fStartAngle = atof(m_startAngle);
		fSweepAngle = atof(m_sweepAngle);
		pDC->BeginPath();
		pDC->SelectObject(GetStockObject(GRAY_BRUSH));
		pDC->MoveTo(x,y);
		pDC->AngleArc(x,y,iRadius,fStartAngle,fSweepAngle); //角弧
		pDC->EndPath();
		pDC->StrokeAndFillPath(); // 画并且填充路径
	}
}


// C绘制饼图View 打印


void C绘制饼图View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C绘制饼图View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C绘制饼图View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C绘制饼图View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void C绘制饼图View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C绘制饼图View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C绘制饼图View 诊断

#ifdef _DEBUG
void C绘制饼图View::AssertValid() const
{
	CView::AssertValid();
}

void C绘制饼图View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C绘制饼图Doc* C绘制饼图View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C绘制饼图Doc)));
	return (C绘制饼图Doc*)m_pDocument;
}
#endif //_DEBUG


// C绘制饼图View 消息处理程序


void C绘制饼图View::OnInput()
{
	CInput diaShow;
	diaShow.DoModal();

	m_centerX = diaShow.m_centerX;
	m_centerY = diaShow.m_centerY;
	m_radius = diaShow.m_radius;
	m_startAngle = diaShow.m_startAngle;
	m_sweepAngle = diaShow.m_sweepAngle;

	m_Draw = TRUE;
	Invalidate(); // 立刻刷新
}
