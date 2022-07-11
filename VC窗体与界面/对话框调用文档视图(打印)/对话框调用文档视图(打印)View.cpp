
// �Ի�������ĵ���ͼ(��ӡ)View.cpp : C�Ի�������ĵ���ͼ��ӡView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�Ի�������ĵ���ͼ(��ӡ).h"
#endif

#include "�Ի�������ĵ���ͼ(��ӡ)Doc.h"
#include "�Ի�������ĵ���ͼ(��ӡ)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern CString str1[9];

// C�Ի�������ĵ���ͼ��ӡView

IMPLEMENT_DYNCREATE(C�Ի�������ĵ���ͼ��ӡView, CView)

BEGIN_MESSAGE_MAP(C�Ի�������ĵ���ͼ��ӡView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C�Ի�������ĵ���ͼ��ӡView ����/����

C�Ի�������ĵ���ͼ��ӡView::C�Ի�������ĵ���ͼ��ӡView()
{
	// TODO: �ڴ˴���ӹ������

}

C�Ի�������ĵ���ͼ��ӡView::~C�Ի�������ĵ���ͼ��ӡView()
{
}

BOOL C�Ի�������ĵ���ͼ��ӡView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�Ի�������ĵ���ͼ��ӡView ����

void C�Ի�������ĵ���ͼ��ӡView::OnDraw(CDC* pDC)
{
	C�Ի�������ĵ���ͼ��ӡDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	font.CreatePointFont(140, "����", pDC);
	screenx = pDC->GetDeviceCaps(LOGPIXELSX);
	screeny = pDC->GetDeviceCaps(LOGPIXELSY);

	for (int i = 0; i<9; ++i)
	{
		pDC->SelectObject(&font);
		pDC->TextOut(80, 50+i*40, str1[i]);
	}
	font.DeleteObject();
}


// C�Ի�������ĵ���ͼ��ӡView ��ӡ

BOOL C�Ի�������ĵ���ͼ��ӡView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�Ի�������ĵ���ͼ��ӡView::OnBeginPrinting(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	printx = pDC->GetDeviceCaps(LOGPIXELSX);
	printy = pDC->GetDeviceCaps(LOGPIXELSY);
	ratex = (double)printx/screenx;
	ratey = (double)printy/screeny;
}

void C�Ի�������ĵ���ͼ��ӡView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�Ի�������ĵ���ͼ��ӡView ���

#ifdef _DEBUG
void C�Ի�������ĵ���ͼ��ӡView::AssertValid() const
{
	CView::AssertValid();
}

void C�Ի�������ĵ���ͼ��ӡView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�Ի�������ĵ���ͼ��ӡDoc* C�Ի�������ĵ���ͼ��ӡView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�Ի�������ĵ���ͼ��ӡDoc)));
	return (C�Ի�������ĵ���ͼ��ӡDoc*)m_pDocument;
}
#endif //_DEBUG


// C�Ի�������ĵ���ͼ��ӡView ��Ϣ�������


void C�Ի�������ĵ���ͼ��ӡView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	font.CreatePointFont(140,"����",pDC);
	for (int i = 0; i<9;++i)
	{
		pDC->SelectObject(&font);
		pDC->TextOut((int)(ratex*80), (int)(ratey*(50+i*40)),str1[i]);
	}
	font.DeleteObject();
	//CView::OnPrint(pDC, pInfo);
}
