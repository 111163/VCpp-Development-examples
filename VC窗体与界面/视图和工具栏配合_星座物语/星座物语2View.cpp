
// ��������2View.cpp : C��������2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��������2.h"
#endif

#include "��������2Doc.h"
#include "��������2View.h" 
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��������2View

IMPLEMENT_DYNCREATE(C��������2View, CView)

BEGIN_MESSAGE_MAP(C��������2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_BUTTONSHOW, &C��������2View::OnButtonshow)
END_MESSAGE_MAP()

// C��������2View ����/����

C��������2View::C��������2View()
{
	// TODO: �ڴ˴���ӹ������
	m_Index = 0;

}

C��������2View::~C��������2View()
{
}

BOOL C��������2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��������2View ����

void C��������2View::OnDraw(CDC* pDC)
{
	C��������2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CDC memDC;										//����һ���豸������
	memDC.CreateCompatibleDC(pDC);					//�������ݵ��豸������
	CBitmap bmp;										//����λͼ����
	bmp.LoadBitmap(IDB_BKBMP+m_Index);						//����λͼ
	memDC.SelectObject(&bmp);							//ѡ��λͼ����
	BITMAP BitInfo;									//����λͼ�ṹ
	bmp.GetBitmap(&BitInfo);								//��ȡλͼ��Ϣ
	int x = BitInfo.bmWidth;								//��ȡλͼ���
	int y = BitInfo.bmHeight;								//��ȡλͼ�߶�
	pDC->BitBlt(0, 0, x, y, &memDC, 0, 0, SRCCOPY);	//����λͼ

}


// C��������2View ��ӡ

BOOL C��������2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��������2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��������2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��������2View ���

#ifdef _DEBUG
void C��������2View::AssertValid() const
{
	CView::AssertValid();
}

void C��������2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��������2Doc* C��������2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��������2Doc)));
	return (C��������2Doc*)m_pDocument;
}
#endif //_DEBUG


// C��������2View ��Ϣ�������


void C��������2View::OnButtonshow()
{
	CMainFrame* pWnd = (CMainFrame*)AfxGetMainWnd();
	CTime time;
	pWnd->m_Date.GetTime(time);
	switch(time.GetMonth())
	{
	case 1:
		if(time.GetDay() < 20)		//Ħ����
			m_Index = 10;
		else						//ˮƿ��
			m_Index = 11;
		break;
	case 2:
		if(time.GetDay() < 19)		//ˮƿ��
			m_Index = 11;
		else						//˫����
			m_Index = 12;
		break;
	case 3:
		if(time.GetDay() < 21)		//˫����
			m_Index = 12;
		else						//������
			m_Index = 1;
		break;
	case 4:
		if(time.GetDay() < 21)		//������
			m_Index = 1;
		else						//��ţ��
			m_Index = 2;
		break;
	case 5:
		if(time.GetDay() < 21)		//��ţ��
			m_Index = 2;
		else						//˫����
			m_Index = 3;
		break;
	case 6:
		if(time.GetDay() < 22)		//˫����
			m_Index = 3;
		else						//��з��
			m_Index = 4;
		break;
	case 7:
		if(time.GetDay() < 23)		//��з��
			m_Index = 4;
		else						//ʨ����
			m_Index = 5;
		break;
	case 8:
		if(time.GetDay() < 23)		//ʨ����
			m_Index = 5;
		else						//��Ů��
			m_Index = 6;
		break;
	case 9:
		if(time.GetDay() < 23)		//��Ů��
			m_Index = 6;
		else						//�����
			m_Index = 7;
		break;
	case 10:
		if(time.GetDay() < 23)		//�����
			m_Index = 7;
		else						//��Ы��
			m_Index = 8;
		break;
	case 11:
		if(time.GetDay() < 22)		//��Ы��
			m_Index = 8;
		else						//������
			m_Index = 9;
		break;
	case 12:
		if(time.GetDay() < 22)		//������
			m_Index = 9;
		else						//Ħ����
			m_Index = 10;
		break;
	}
	Invalidate();
}
