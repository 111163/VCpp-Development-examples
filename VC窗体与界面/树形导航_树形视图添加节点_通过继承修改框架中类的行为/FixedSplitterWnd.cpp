#include "StdAfx.h"
#include "FixedSplitterWnd.h"


CFixedSplitterWnd::CFixedSplitterWnd(void)
{
}


CFixedSplitterWnd::~CFixedSplitterWnd(void)
{
}
BEGIN_MESSAGE_MAP(CFixedSplitterWnd, CSplitterWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


void CFixedSplitterWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//CSplitterWnd::OnLButtonDown(nFlags, point);
	CWnd::OnLButtonDown(nFlags, point);
}


void CFixedSplitterWnd::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//CSplitterWnd::OnMouseMove(nFlags, point);
	CWnd::OnMouseMove(nFlags, point);
}
