
// �ĵ���ͼ�ṹʵ�ִ�ӡԤ��View.cpp : C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ĵ���ͼ�ṹʵ�ִ�ӡԤ��.h"
#endif

#include "�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc.h"
#include "�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View

IMPLEMENT_DYNCREATE(C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View, CView)

BEGIN_MESSAGE_MAP(C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View ����/����

C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View::C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View()
{
	// TODO: �ڴ˴���ӹ������

}

C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View::~C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View()
{
}

BOOL C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View ����

void C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View::OnDraw(CDC* pDC)
{
	C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc* pDoc = GetDocument();
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


// C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View ��ӡ

BOOL C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View::OnBeginPrinting(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	//��ô�ӡ���ֱ���
	printx =pDC->GetDeviceCaps(LOGPIXELSX);
	printy =pDC->GetDeviceCaps(LOGPIXELSY);    
	//�����ӡ������Ļ�ı���
	ratex = (double)printx /screenx;                  
	ratey = (double)printy /screeny;
}

void C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View ���

#ifdef _DEBUG
void C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View::AssertValid() const
{
	CView::AssertValid();
}

void C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc* C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc)));
	return (C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View ��Ϣ�������


void C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	CBitmap m_Bitmap;                                                                                            //����CBitmap����
	m_Bitmap.LoadBitmap(IDB_BITMAP1);                                                               //����λͼ��Դ
	CDC memDC;                                                                                                   //�豸������
	memDC.CreateCompatibleDC(pDC);                                                                    //�����ڴ��豸������
	memDC.SelectObject(&m_Bitmap);                                                                     //��λͼѡ���豸������
	BITMAP m_Bmp;                                                                                              //����BITMAP����
	m_Bitmap.GetBitmap(&m_Bmp);                                                                         //���λͼ��Ϣ
	int x = m_Bmp.bmWidth;                                                                                    //���λͼ�Ŀ��
	int y = m_Bmp.bmHeight;                                                                                   //���λͼ�ĸ߶�
	pDC->StretchBlt(0, 0, (int)(ratex*x), (int)(ratey*y), &memDC,0,0,x,y,SRCCOPY); //����λͼ����
	memDC.DeleteDC();  

	//CView::OnPrint(pDC, pInfo);
}
