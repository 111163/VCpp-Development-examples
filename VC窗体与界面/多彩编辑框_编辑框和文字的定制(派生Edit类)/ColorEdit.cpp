// ColorEdit.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ʱ༭��.h"
#include "ColorEdit.h"


// CColorEdit

IMPLEMENT_DYNAMIC(CColorEdit, CEdit)

CColorEdit::CColorEdit()
{

}

CColorEdit::~CColorEdit()
{
}


BEGIN_MESSAGE_MAP(CColorEdit, CEdit)
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()


void CColorEdit::SetFrameColor(COLORREF color)
{
	m_FrameColor = color;
}

void CColorEdit::SetTextColor(COLORREF color)
{
	m_TextColor = color;
}

// CColorEdit ��Ϣ�������




HBRUSH CColorEdit::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  �����Ӧ���ø����Ĵ�������򷵻ط� null ����
	CRect rect;
	GetClientRect(&rect);
	rect.InflateRect(1,1,1,1); // ָ������λ��
	CBrush brush(m_FrameColor);
	pDC->FrameRect(rect, &brush);


	
	CBrush m_Brush;
	m_Brush.CreateStockObject(WHITE_BRUSH);
	pDC->SetTextColor(m_TextColor);

	return m_Brush;

	//return NULL;
}
