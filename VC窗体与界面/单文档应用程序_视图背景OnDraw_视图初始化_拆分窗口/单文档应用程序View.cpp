
// ���ĵ�Ӧ�ó���View.cpp : C���ĵ�Ӧ�ó���View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "���ĵ�Ӧ�ó���.h"
#endif

#include "���ĵ�Ӧ�ó���Doc.h"
#include "���ĵ�Ӧ�ó���View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C���ĵ�Ӧ�ó���View

IMPLEMENT_DYNCREATE(C���ĵ�Ӧ�ó���View, CView)

BEGIN_MESSAGE_MAP(C���ĵ�Ӧ�ó���View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C���ĵ�Ӧ�ó���View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C���ĵ�Ӧ�ó���View ����/����

C���ĵ�Ӧ�ó���View::C���ĵ�Ӧ�ó���View()
{
	// TODO: �ڴ˴���ӹ������

}

C���ĵ�Ӧ�ó���View::~C���ĵ�Ӧ�ó���View()
{
}

BOOL C���ĵ�Ӧ�ó���View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C���ĵ�Ӧ�ó���View ����

void C���ĵ�Ӧ�ó���View::OnDraw(CDC* pDC)  // ������ͼ����
{
	C���ĵ�Ӧ�ó���Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CBitmap m_Bitmap;                                                                       //����CBitmap����
	m_Bitmap.LoadBitmap(IDB_BITMAP1);                                                        //����λͼ��Դ
	CDC memDC;                                                                              //�豸������
	memDC.CreateCompatibleDC(pDC);                                                      //�����ڴ��豸������
	memDC.SelectObject(&m_Bitmap);                                                              //��λͼѡ���豸������
	BITMAP m_Bmp;                                                                         //����BITMAP����
	m_Bitmap.GetBitmap(&m_Bmp);                                                    //���λͼ��Ϣ
	int x = m_Bmp.bmWidth;                                                                      //���λͼ�Ŀ��
	int y = m_Bmp.bmHeight;                                                                     //���λͼ�ĸ߶�
	CRect rect;                                                                            //�����������
	GetClientRect(rect);                                                                       //��ñ༭��ͻ�����
	pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&memDC,0,0,x,y,SRCCOPY); //����λͼ����
	memDC.DeleteDC(); 

}


// C���ĵ�Ӧ�ó���View ��ӡ


void C���ĵ�Ӧ�ó���View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C���ĵ�Ӧ�ó���View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C���ĵ�Ӧ�ó���View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C���ĵ�Ӧ�ó���View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void C���ĵ�Ӧ�ó���View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C���ĵ�Ӧ�ó���View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C���ĵ�Ӧ�ó���View ���

#ifdef _DEBUG
void C���ĵ�Ӧ�ó���View::AssertValid() const
{
	CView::AssertValid();
}

void C���ĵ�Ӧ�ó���View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C���ĵ�Ӧ�ó���Doc* C���ĵ�Ӧ�ó���View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C���ĵ�Ӧ�ó���Doc)));
	return (C���ĵ�Ӧ�ó���Doc*)m_pDocument;
}
#endif //_DEBUG


// C���ĵ�Ӧ�ó���View ��Ϣ�������
