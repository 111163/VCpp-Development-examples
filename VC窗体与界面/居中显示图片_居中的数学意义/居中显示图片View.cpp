
// 居中显示图片View.cpp : C居中显示图片View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "居中显示图片.h"
#endif

#include "居中显示图片Doc.h"
#include "居中显示图片View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C居中显示图片View

IMPLEMENT_DYNCREATE(C居中显示图片View, CView)

BEGIN_MESSAGE_MAP(C居中显示图片View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C居中显示图片View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SETCENTER, &C居中显示图片View::OnSetcenter)
END_MESSAGE_MAP()

// C居中显示图片View 构造/析构

C居中显示图片View::C居中显示图片View()
{
	// TODO: 在此处添加构造代码

}

C居中显示图片View::~C居中显示图片View()
{
}

BOOL C居中显示图片View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C居中显示图片View 绘制

void C居中显示图片View::OnDraw(CDC* pDC)
{
	C居中显示图片Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CDC memdc;
	HBITMAP hbmp=(HBITMAP)::LoadImage(AfxGetInstanceHandle(),"test.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTCOLOR|LR_DEFAULTSIZE);
	BITMAP bm;
	GetObject(hbmp,sizeof(bm),&bm);
	memdc.CreateCompatibleDC(pDC);
	memdc.SelectObject(hbmp);
	pDC->BitBlt(m_ptPitcureVec.x,m_ptPitcureVec.y,bm.bmWidth,bm.bmHeight,&memdc,0,0,SRCCOPY);
	memdc.DeleteDC();
}


// C居中显示图片View 打印


void C居中显示图片View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C居中显示图片View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C居中显示图片View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C居中显示图片View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void C居中显示图片View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C居中显示图片View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C居中显示图片View 诊断

#ifdef _DEBUG
void C居中显示图片View::AssertValid() const
{
	CView::AssertValid();
}

void C居中显示图片View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C居中显示图片Doc* C居中显示图片View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C居中显示图片Doc)));
	return (C居中显示图片Doc*)m_pDocument;
}
#endif //_DEBUG


// C居中显示图片View 消息处理程序
CSize C居中显示图片View::GetCenterSize(int iDlgWidth,int iDlgHeight,int iBmpWidth,int iBmpHeight)
{
	CSize cszResult;
	cszResult.cx=(iDlgWidth-iBmpWidth)/2;
	cszResult.cy=(iDlgHeight-iBmpHeight)/2;
	return cszResult;
}

void C居中显示图片View::OnSetcenter()
{
	HBITMAP hbmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),"test.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTCOLOR|LR_DEFAULTSIZE);
	BITMAP bm;
	GetObject(hbmp, sizeof(bm), &bm);
	CRect m_rect; 
	GetClientRect(m_rect);
	CSize cszTmp=GetCenterSize(m_rect.Width(),m_rect.Height(),bm.bmWidth,bm.bmHeight);
	m_ptPitcureVec.x=cszTmp.cx;
	m_ptPitcureVec.y=cszTmp.cy;
	Invalidate();
}
