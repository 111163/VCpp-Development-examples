
// 绘制自定义线条View.cpp : C绘制自定义线条View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "绘制自定义线条.h"
#endif

#include "绘制自定义线条Doc.h"
#include "绘制自定义线条View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C绘制自定义线条View

IMPLEMENT_DYNCREATE(C绘制自定义线条View, CView)

BEGIN_MESSAGE_MAP(C绘制自定义线条View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C绘制自定义线条View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C绘制自定义线条View 构造/析构

C绘制自定义线条View::C绘制自定义线条View()
{
	// TODO: 在此处添加构造代码

}

C绘制自定义线条View::~C绘制自定义线条View()
{
}

BOOL C绘制自定义线条View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C绘制自定义线条View 绘制

void C绘制自定义线条View::OnDraw(CDC* pDC)
{
	C绘制自定义线条Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CPen pen, *pOldPen;
	CString strResult;
	LOGBRUSH lb;
	DWORD wstyle[2];
	lb.lbStyle = BS_SOLID;
	lb.lbColor = RGB(0,0,255);
	lb.lbHatch = HS_BDIAGONAL;
	wstyle[0] = 1;
	wstyle[1] = 2;
	CRect rcStylel(10, 10, 100, 30);
	strResult = "自定义样式1";
	pen.CreatePen(PS_USERSTYLE, 1, &lb, 2, wstyle);
	pOldPen = pDC->SelectObject(&pen);
	pDC->DrawText(strResult, &rcStylel, DT_RIGHT);
	pDC->MoveTo(110, 20);
	pDC->LineTo(210, 20);
	pen.DeleteObject();

	DWORD wstyle2[3];
	lb.lbStyle = BS_SOLID; 
	lb.lbColor = RGB(0,0,255);     
	lb.lbHatch = HS_BDIAGONAL;
	wstyle2[0]=1;
	wstyle2[1]=2;
	wstyle2[2]=5;   // 偶数个的时候就会出现有趣的现象 因为 实 虚 一直是交替的出现，长度也是交替着出现
	CRect rcStyle2(10,40,100,60);
	strResult="自定义样式2";
	pen.CreatePen(PS_USERSTYLE,1,&lb,3,wstyle2);
	pDC->SelectObject(pen);
	pDC->DrawText(strResult,&rcStyle2,DT_RIGHT);
	pDC->MoveTo(110,50);
	pDC->LineTo(210,50);
	pen.DeleteObject();

	DWORD wstyle3[4];
	lb.lbStyle = BS_SOLID; 
	lb.lbColor = RGB(0,0,255);     
	lb.lbHatch = HS_BDIAGONAL;
	wstyle3[0]=5;
	wstyle3[1]=1;
	wstyle3[2]=1;
	wstyle3[3]=5;
	CRect rcStyle3(10,70,100,90);
	strResult="自定义样式3";
	pen.CreatePen(PS_USERSTYLE,1,&lb,4,wstyle3);
	pDC->SelectObject(pen);
	pDC->DrawText(strResult,&rcStyle3,DT_RIGHT);
	pDC->MoveTo(110,80);
	pDC->LineTo(210,80);
	

	CRect rcCli;
	GetClientRect(rcCli);
	int right1 = rcCli.right/2;
	int bottom1 = rcCli.bottom/2;

	/* 透明画刷
	static HBRUSH m_brush;  //画刷句柄
	m_brush = (HBRUSH)GetStockObject(NULL_BRUSH);
	//将空画刷选入设备描述表  
	SelectObject(hdc, m_brush);
	*/


	CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));  // 透明画刷
	pDC->SelectObject(pBrush); // 选入

	pDC->Ellipse(5, 5, 300, 300);
	pDC->SelectObject(pOldPen);
	pen.DeleteObject();

}


// C绘制自定义线条View 打印


void C绘制自定义线条View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C绘制自定义线条View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C绘制自定义线条View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C绘制自定义线条View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void C绘制自定义线条View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C绘制自定义线条View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C绘制自定义线条View 诊断

#ifdef _DEBUG
void C绘制自定义线条View::AssertValid() const
{
	CView::AssertValid();
}

void C绘制自定义线条View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C绘制自定义线条Doc* C绘制自定义线条View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C绘制自定义线条Doc)));
	return (C绘制自定义线条Doc*)m_pDocument;
}
#endif //_DEBUG


// C绘制自定义线条View 消息处理程序
