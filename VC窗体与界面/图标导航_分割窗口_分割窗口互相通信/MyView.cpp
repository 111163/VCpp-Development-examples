// MyView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ͼ�굼��.h"
#include "MyView.h"


// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

CMyView::CMyView()
{
	m_Index = 0;
}

CMyView::~CMyView()
{
}

BEGIN_MESSAGE_MAP(CMyView, CView)
END_MESSAGE_MAP()


// CMyView ��ͼ

void CMyView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	
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


// CMyView ���

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyView ��Ϣ�������
