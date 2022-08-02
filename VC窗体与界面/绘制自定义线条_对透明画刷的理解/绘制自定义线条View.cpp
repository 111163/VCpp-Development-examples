
// �����Զ�������View.cpp : C�����Զ�������View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�����Զ�������.h"
#endif

#include "�����Զ�������Doc.h"
#include "�����Զ�������View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�����Զ�������View

IMPLEMENT_DYNCREATE(C�����Զ�������View, CView)

BEGIN_MESSAGE_MAP(C�����Զ�������View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C�����Զ�������View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C�����Զ�������View ����/����

C�����Զ�������View::C�����Զ�������View()
{
	// TODO: �ڴ˴���ӹ������

}

C�����Զ�������View::~C�����Զ�������View()
{
}

BOOL C�����Զ�������View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�����Զ�������View ����

void C�����Զ�������View::OnDraw(CDC* pDC)
{
	C�����Զ�������Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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
	strResult = "�Զ�����ʽ1";
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
	wstyle2[2]=5;   // ż������ʱ��ͻ������Ȥ������ ��Ϊ ʵ �� һֱ�ǽ���ĳ��֣�����Ҳ�ǽ����ų���
	CRect rcStyle2(10,40,100,60);
	strResult="�Զ�����ʽ2";
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
	strResult="�Զ�����ʽ3";
	pen.CreatePen(PS_USERSTYLE,1,&lb,4,wstyle3);
	pDC->SelectObject(pen);
	pDC->DrawText(strResult,&rcStyle3,DT_RIGHT);
	pDC->MoveTo(110,80);
	pDC->LineTo(210,80);
	

	CRect rcCli;
	GetClientRect(rcCli);
	int right1 = rcCli.right/2;
	int bottom1 = rcCli.bottom/2;

	/* ͸����ˢ
	static HBRUSH m_brush;  //��ˢ���
	m_brush = (HBRUSH)GetStockObject(NULL_BRUSH);
	//���ջ�ˢѡ���豸������  
	SelectObject(hdc, m_brush);
	*/


	CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));  // ͸����ˢ
	pDC->SelectObject(pBrush); // ѡ��

	pDC->Ellipse(5, 5, 300, 300);
	pDC->SelectObject(pOldPen);
	pen.DeleteObject();

}


// C�����Զ�������View ��ӡ


void C�����Զ�������View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C�����Զ�������View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�����Զ�������View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�����Զ�������View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void C�����Զ�������View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C�����Զ�������View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C�����Զ�������View ���

#ifdef _DEBUG
void C�����Զ�������View::AssertValid() const
{
	CView::AssertValid();
}

void C�����Զ�������View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�����Զ�������Doc* C�����Զ�������View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�����Զ�������Doc)));
	return (C�����Զ�������Doc*)m_pDocument;
}
#endif //_DEBUG


// C�����Զ�������View ��Ϣ�������
