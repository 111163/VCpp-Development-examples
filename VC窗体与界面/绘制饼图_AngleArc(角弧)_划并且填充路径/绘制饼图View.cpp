
// ���Ʊ�ͼView.cpp : C���Ʊ�ͼView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "���Ʊ�ͼ.h"
#endif

#include "���Ʊ�ͼDoc.h"
#include "���Ʊ�ͼView.h"
#include "Input.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C���Ʊ�ͼView

IMPLEMENT_DYNCREATE(C���Ʊ�ͼView, CView)

BEGIN_MESSAGE_MAP(C���Ʊ�ͼView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C���Ʊ�ͼView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_INPUT, &C���Ʊ�ͼView::OnInput)
END_MESSAGE_MAP()

// C���Ʊ�ͼView ����/����

C���Ʊ�ͼView::C���Ʊ�ͼView()
{
	// TODO: �ڴ˴���ӹ������
	m_centerX = "";
	m_centerY = "";
	m_radius = "";
	m_startAngle = "";
	m_sweepAngle = "";
	m_Draw = FALSE;

}

C���Ʊ�ͼView::~C���Ʊ�ͼView()
{
}

BOOL C���Ʊ�ͼView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C���Ʊ�ͼView ����

void C���Ʊ�ͼView::OnDraw(CDC* pDC)
{
	C���Ʊ�ͼDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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
		pDC->AngleArc(x,y,iRadius,fStartAngle,fSweepAngle); //�ǻ�
		pDC->EndPath();
		pDC->StrokeAndFillPath(); // ���������·��
	}
}


// C���Ʊ�ͼView ��ӡ


void C���Ʊ�ͼView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C���Ʊ�ͼView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C���Ʊ�ͼView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C���Ʊ�ͼView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void C���Ʊ�ͼView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C���Ʊ�ͼView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C���Ʊ�ͼView ���

#ifdef _DEBUG
void C���Ʊ�ͼView::AssertValid() const
{
	CView::AssertValid();
}

void C���Ʊ�ͼView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C���Ʊ�ͼDoc* C���Ʊ�ͼView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C���Ʊ�ͼDoc)));
	return (C���Ʊ�ͼDoc*)m_pDocument;
}
#endif //_DEBUG


// C���Ʊ�ͼView ��Ϣ�������


void C���Ʊ�ͼView::OnInput()
{
	CInput diaShow;
	diaShow.DoModal();

	m_centerX = diaShow.m_centerX;
	m_centerY = diaShow.m_centerY;
	m_radius = diaShow.m_radius;
	m_startAngle = diaShow.m_startAngle;
	m_sweepAngle = diaShow.m_sweepAngle;

	m_Draw = TRUE;
	Invalidate(); // ����ˢ��
}
