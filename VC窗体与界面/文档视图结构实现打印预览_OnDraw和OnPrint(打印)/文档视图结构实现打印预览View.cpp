
// 文档视图结构实现打印预览View.cpp : C文档视图结构实现打印预览View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "文档视图结构实现打印预览.h"
#endif

#include "文档视图结构实现打印预览Doc.h"
#include "文档视图结构实现打印预览View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C文档视图结构实现打印预览View

IMPLEMENT_DYNCREATE(C文档视图结构实现打印预览View, CView)

BEGIN_MESSAGE_MAP(C文档视图结构实现打印预览View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C文档视图结构实现打印预览View 构造/析构

C文档视图结构实现打印预览View::C文档视图结构实现打印预览View()
{
	// TODO: 在此处添加构造代码

}

C文档视图结构实现打印预览View::~C文档视图结构实现打印预览View()
{
}

BOOL C文档视图结构实现打印预览View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C文档视图结构实现打印预览View 绘制

void C文档视图结构实现打印预览View::OnDraw(CDC* pDC)
{
	C文档视图结构实现打印预览Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	screenx =pDC->GetDeviceCaps(LOGPIXELSX);
	screeny =pDC->GetDeviceCaps(LOGPIXELSY);

	CBitmap m_Bitmap;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);

	CDC memDc;
	memDc.CreateCompatibleDC(pDC);
	memDc.SelectObject(m_Bitmap);

	BITMAP m_Bmp;
	m_Bitmap.GetBitmap(&m_Bmp);

	int x = m_Bmp.bmWidth;
	int y = m_Bmp.bmHeight;

	CRect rect;
	GetClientRect(rect);

	pDC->BitBlt(0,0,x,y,&memDc, 0,0, SRCCOPY);
	memDc.DeleteDC();
}


// C文档视图结构实现打印预览View 打印

BOOL C文档视图结构实现打印预览View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C文档视图结构实现打印预览View::OnBeginPrinting(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	//获得打印机分辨率
	printx =pDC->GetDeviceCaps(LOGPIXELSX);
	printy =pDC->GetDeviceCaps(LOGPIXELSY);    
	//计算打印机与屏幕的比率
	ratex = (double)printx /screenx;                  
	ratey = (double)printy /screeny;
}

void C文档视图结构实现打印预览View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C文档视图结构实现打印预览View 诊断

#ifdef _DEBUG
void C文档视图结构实现打印预览View::AssertValid() const
{
	CView::AssertValid();
}

void C文档视图结构实现打印预览View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C文档视图结构实现打印预览Doc* C文档视图结构实现打印预览View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C文档视图结构实现打印预览Doc)));
	return (C文档视图结构实现打印预览Doc*)m_pDocument;
}
#endif //_DEBUG


// C文档视图结构实现打印预览View 消息处理程序


void C文档视图结构实现打印预览View::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	CBitmap m_Bitmap;                                                                                            //声明CBitmap对象
	m_Bitmap.LoadBitmap(IDB_BITMAP1);                                                               //加载位图资源
	CDC memDC;                                                                                                   //设备上下文
	memDC.CreateCompatibleDC(pDC);                                                                    //创建内存设备上下文
	memDC.SelectObject(&m_Bitmap);                                                                     //将位图选人设备上下文
	BITMAP m_Bmp;                                                                                              //声明BITMAP对象
	m_Bitmap.GetBitmap(&m_Bmp);                                                                         //获得位图信息
	int x = m_Bmp.bmWidth;                                                                                    //获得位图的宽度
	int y = m_Bmp.bmHeight;                                                                                   //获得位图的高度
	pDC->StretchBlt(0, 0, (int)(ratex*x), (int)(ratey*y), &memDC,0,0,x,y,SRCCOPY); //绘制位图背景
	memDC.DeleteDC();  

	//CView::OnPrint(pDC, pInfo);
}
