
// 显示JPEG图像View.cpp : C显示JPEG图像View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "显示JPEG图像.h"
#endif

#include "显示JPEG图像Doc.h"
#include "显示JPEG图像View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C显示JPEG图像View

IMPLEMENT_DYNCREATE(C显示JPEG图像View, CView)

BEGIN_MESSAGE_MAP(C显示JPEG图像View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C显示JPEG图像View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C显示JPEG图像View 构造/析构

C显示JPEG图像View::C显示JPEG图像View()
{
	// TODO: 在此处添加构造代码
	CFile file;
	file.Open("OGC.gif",CFile::modeReadWrite); // angell.jpg
	DWORD len = file.GetLength();
	hMem = GlobalAlloc(GMEM_MOVEABLE,len);
	LPVOID pData = NULL; 
	pData = GlobalLock(hMem);
	file.Read(pData,len);
	file.Close();
	GlobalUnlock(hMem);
	CreateStreamOnHGlobal(hMem,TRUE,&m_pStream);
	OleLoadPicture(m_pStream,len,TRUE,IID_IPicture,(LPVOID*)&m_pPicture);
	m_pPicture->get_Height(&m_JPGHeight);
	m_pPicture->get_Width(&m_JPGWidth);             //获取图像宽度
}

C显示JPEG图像View::~C显示JPEG图像View()
{
}

BOOL C显示JPEG图像View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C显示JPEG图像View 绘制

void C显示JPEG图像View::OnDraw(CDC* pDC)
{
	C显示JPEG图像Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//绘制JPEG图像

	m_pPicture->Render(pDC->m_hDC,0,0,(int)(m_JPGWidth/26.45),(int)(m_JPGHeight/26.45)
		,0,m_JPGHeight,m_JPGWidth,-m_JPGHeight,NULL);      

}


// C显示JPEG图像View 打印


void C显示JPEG图像View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C显示JPEG图像View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C显示JPEG图像View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C显示JPEG图像View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void C显示JPEG图像View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C显示JPEG图像View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C显示JPEG图像View 诊断

#ifdef _DEBUG
void C显示JPEG图像View::AssertValid() const
{
	CView::AssertValid();
}

void C显示JPEG图像View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C显示JPEG图像Doc* C显示JPEG图像View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C显示JPEG图像Doc)));
	return (C显示JPEG图像Doc*)m_pDocument;
}
#endif //_DEBUG


// C显示JPEG图像View 消息处理程序
