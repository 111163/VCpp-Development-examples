// ListBmp.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ΪListBox��ӱ���.h"
#include "ListBmp.h"


// CListBmp

IMPLEMENT_DYNAMIC(CListBmp, CListBox)

CListBmp::CListBmp()
{

}

CListBmp::~CListBmp()
{
}


BEGIN_MESSAGE_MAP(CListBmp, CListBox)
	ON_WM_PAINT()
	/*ON_WM_DRAWITEM_REFLECT()*/
	ON_WM_VSCROLL()
END_MESSAGE_MAP()



// CListBmp ��Ϣ�������




void CListBmp::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	CRect rect,clrRC;
	GetClientRect(&rect);
	CBitmap bitmap;
	CDC memdc;
	memdc.CreateCompatibleDC(&dc);
	bitmap.LoadBitmap(IDB_BITMAP1);
	memdc.SelectObject(&bitmap);
	dc.BitBlt(0,0,rect.Width(),rect.Height(),&memdc,0,0,SRCCOPY);
	bitmap.DeleteObject();
	ReleaseDC(&memdc);

	for(int i=0;i<rect.Height()/GetItemHeight(0);i++)
	{
		GetItemRect(i,clrRC);
		CString str;
		GetText(i+GetTopIndex(),str);
		dc.SetBkMode(TRANSPARENT);
		dc.TextOut(0,i*GetItemHeight(i),str);
	}

	// ��Ϊ��ͼ��Ϣ���� CListBox::OnPaint()
}


void CListBmp::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: �ڴ˴������Ϣ����������
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);
	int nIndex = lpDrawItemStruct->itemID;							//��ȡ��ǰ��Ŀ����
	//�ж���Ŀ״̬
	int nState = lpDrawItemStruct->itemState;
	CRect rect,clrRC;
	GetClientRect(&rect);
	CBitmap bitmap;
	CDC memdc;
	memdc.CreateCompatibleDC(&dc);
	bitmap.LoadBitmap(IDB_BITMAP1);
	memdc.SelectObject(&bitmap);
	GetItemRect(nIndex,clrRC);
	m_pFont = GetFont();				//�������
	dc.SelectObject(m_pFont);
	if(nState & ODS_SELECTED)	//����ѡ��״̬
	{	
		dc.SetTextColor(RGB(200,0,0));		//����ѡ��״̬�ı���ɫ
		dc.FillSolidRect(&clrRC, RGB(0,0,200));			//�����Ŀ����Ϊ����Ч��
	}
	else
	{
		int nCurSel = nIndex-GetTopIndex();					//���õ�ǰ�������ڿɼ����λ��
		dc.BitBlt(0,nCurSel*clrRC.Height(),clrRC.Width(),clrRC.Height()
			,&memdc,0,nCurSel*clrRC.Height(),SRCCOPY);
		dc.SetTextColor(RGB(0,0,0));		//�����ı���ɫ
	}
	if(nIndex != -1)
	{
		CString str;
		GetText(nIndex,str);
		dc.SetBkMode(TRANSPARENT);
		dc.TextOut(0,(nIndex-GetTopIndex())*clrRC.Height(),str);
	}
	m_pFont->DeleteObject();
	bitmap.DeleteObject();
	ReleaseDC(&memdc);
	dc.DeleteDC();
}



void CListBmp::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Invalidate();
	CListBox::OnVScroll(nSBCode, nPos, pScrollBar);
}
