
// ��ʾJPEGͼ��View.cpp : C��ʾJPEGͼ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ʾJPEGͼ��.h"
#endif

#include "��ʾJPEGͼ��Doc.h"
#include "��ʾJPEGͼ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ʾJPEGͼ��View

IMPLEMENT_DYNCREATE(C��ʾJPEGͼ��View, CView)

BEGIN_MESSAGE_MAP(C��ʾJPEGͼ��View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C��ʾJPEGͼ��View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C��ʾJPEGͼ��View ����/����

C��ʾJPEGͼ��View::C��ʾJPEGͼ��View()
{
	// TODO: �ڴ˴���ӹ������
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
	m_pPicture->get_Width(&m_JPGWidth);             //��ȡͼ����
}

C��ʾJPEGͼ��View::~C��ʾJPEGͼ��View()
{
}

BOOL C��ʾJPEGͼ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��ʾJPEGͼ��View ����

void C��ʾJPEGͼ��View::OnDraw(CDC* pDC)
{
	C��ʾJPEGͼ��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	//����JPEGͼ��

	m_pPicture->Render(pDC->m_hDC,0,0,(int)(m_JPGWidth/26.45),(int)(m_JPGHeight/26.45)
		,0,m_JPGHeight,m_JPGWidth,-m_JPGHeight,NULL);      

}


// C��ʾJPEGͼ��View ��ӡ


void C��ʾJPEGͼ��View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C��ʾJPEGͼ��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��ʾJPEGͼ��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��ʾJPEGͼ��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void C��ʾJPEGͼ��View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C��ʾJPEGͼ��View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C��ʾJPEGͼ��View ���

#ifdef _DEBUG
void C��ʾJPEGͼ��View::AssertValid() const
{
	CView::AssertValid();
}

void C��ʾJPEGͼ��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��ʾJPEGͼ��Doc* C��ʾJPEGͼ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ʾJPEGͼ��Doc)));
	return (C��ʾJPEGͼ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ʾJPEGͼ��View ��Ϣ�������
