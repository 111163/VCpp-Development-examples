
// 单文档应用程序View.cpp : C单文档应用程序View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "单文档应用程序.h"
#endif

#include "单文档应用程序Doc.h"
#include "单文档应用程序View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C单文档应用程序View

IMPLEMENT_DYNCREATE(C单文档应用程序View, CView)

BEGIN_MESSAGE_MAP(C单文档应用程序View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C单文档应用程序View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C单文档应用程序View 构造/析构

C单文档应用程序View::C单文档应用程序View()
{
	// TODO: 在此处添加构造代码

}

C单文档应用程序View::~C单文档应用程序View()
{
}

BOOL C单文档应用程序View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C单文档应用程序View 绘制

void C单文档应用程序View::OnDraw(CDC* pDC)  // 绘制视图背景
{
	C单文档应用程序Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CBitmap m_Bitmap;                                                                       //声明CBitmap对象
	m_Bitmap.LoadBitmap(IDB_BITMAP1);                                                        //加载位图资源
	CDC memDC;                                                                              //设备上下文
	memDC.CreateCompatibleDC(pDC);                                                      //创建内存设备上下文
	memDC.SelectObject(&m_Bitmap);                                                              //将位图选人设备上下文
	BITMAP m_Bmp;                                                                         //声明BITMAP对象
	m_Bitmap.GetBitmap(&m_Bmp);                                                    //获得位图信息
	int x = m_Bmp.bmWidth;                                                                      //获得位图的宽度
	int y = m_Bmp.bmHeight;                                                                     //获得位图的高度
	CRect rect;                                                                            //声明区域对象
	GetClientRect(rect);                                                                       //获得编辑框客户区域
	pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&memDC,0,0,x,y,SRCCOPY); //绘制位图背景
	memDC.DeleteDC(); 

}


// C单文档应用程序View 打印


void C单文档应用程序View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C单文档应用程序View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C单文档应用程序View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C单文档应用程序View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void C单文档应用程序View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C单文档应用程序View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C单文档应用程序View 诊断

#ifdef _DEBUG
void C单文档应用程序View::AssertValid() const
{
	CView::AssertValid();
}

void C单文档应用程序View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C单文档应用程序Doc* C单文档应用程序View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C单文档应用程序Doc)));
	return (C单文档应用程序Doc*)m_pDocument;
}
#endif //_DEBUG


// C单文档应用程序View 消息处理程序
