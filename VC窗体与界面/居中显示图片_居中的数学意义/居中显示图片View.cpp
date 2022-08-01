
// ������ʾͼƬView.cpp : C������ʾͼƬView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ʾͼƬ.h"
#endif

#include "������ʾͼƬDoc.h"
#include "������ʾͼƬView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ʾͼƬView

IMPLEMENT_DYNCREATE(C������ʾͼƬView, CView)

BEGIN_MESSAGE_MAP(C������ʾͼƬView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C������ʾͼƬView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SETCENTER, &C������ʾͼƬView::OnSetcenter)
END_MESSAGE_MAP()

// C������ʾͼƬView ����/����

C������ʾͼƬView::C������ʾͼƬView()
{
	// TODO: �ڴ˴���ӹ������

}

C������ʾͼƬView::~C������ʾͼƬView()
{
}

BOOL C������ʾͼƬView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������ʾͼƬView ����

void C������ʾͼƬView::OnDraw(CDC* pDC)
{
	C������ʾͼƬDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CDC memdc;
	HBITMAP hbmp=(HBITMAP)::LoadImage(AfxGetInstanceHandle(),"test.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTCOLOR|LR_DEFAULTSIZE);
	BITMAP bm;
	GetObject(hbmp,sizeof(bm),&bm);
	memdc.CreateCompatibleDC(pDC);
	memdc.SelectObject(hbmp);
	pDC->BitBlt(m_ptPitcureVec.x,m_ptPitcureVec.y,bm.bmWidth,bm.bmHeight,&memdc,0,0,SRCCOPY);
	memdc.DeleteDC();
}


// C������ʾͼƬView ��ӡ


void C������ʾͼƬView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C������ʾͼƬView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C������ʾͼƬView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C������ʾͼƬView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void C������ʾͼƬView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C������ʾͼƬView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C������ʾͼƬView ���

#ifdef _DEBUG
void C������ʾͼƬView::AssertValid() const
{
	CView::AssertValid();
}

void C������ʾͼƬView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������ʾͼƬDoc* C������ʾͼƬView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ʾͼƬDoc)));
	return (C������ʾͼƬDoc*)m_pDocument;
}
#endif //_DEBUG


// C������ʾͼƬView ��Ϣ�������
CSize C������ʾͼƬView::GetCenterSize(int iDlgWidth,int iDlgHeight,int iBmpWidth,int iBmpHeight)
{
	CSize cszResult;
	cszResult.cx=(iDlgWidth-iBmpWidth)/2;
	cszResult.cy=(iDlgHeight-iBmpHeight)/2;
	return cszResult;
}

void C������ʾͼƬView::OnSetcenter()
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
