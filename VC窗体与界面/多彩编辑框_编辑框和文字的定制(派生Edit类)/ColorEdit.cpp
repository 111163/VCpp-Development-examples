// ColorEdit.cpp : 实现文件
//

#include "stdafx.h"
#include "多彩编辑框.h"
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

// CColorEdit 消息处理程序




HBRUSH CColorEdit::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果不应调用父级的处理程序，则返回非 null 画笔
	CRect rect;
	GetClientRect(&rect);
	rect.InflateRect(1,1,1,1); // 指定扩大单位数
	CBrush brush(m_FrameColor);
	pDC->FrameRect(rect, &brush);


	
	CBrush m_Brush;
	m_Brush.CreateStockObject(WHITE_BRUSH);
	pDC->SetTextColor(m_TextColor);

	return m_Brush;

	//return NULL;
}
