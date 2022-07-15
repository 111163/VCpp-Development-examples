// ButtonAvi.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�������İ�ť.h"
#include "ButtonAvi.h"


// CButtonAvi

IMPLEMENT_DYNAMIC(CButtonAvi, CButton)

CButtonAvi::CButtonAvi()
{
	m_play = FALSE;
}

CButtonAvi::~CButtonAvi()
{
}


BEGIN_MESSAGE_MAP(CButtonAvi, CButton)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


void CButtonAvi::LoadAVI(UINT nID) // ��������ȡ��Ƶ��Դ
{
	m_id = nID;
}


void CButtonAvi::DrawButton(CDC* pDC,UINT nState,CRect rect)
{
	COLORREF UpCol, DownCol;
	if ((nState & ODS_SELECTED) == ODS_SELECTED)
	{
		UpCol = RGB(0,0,0);
		DownCol = RGB(0,0,0);
		m_play = FALSE;
	}
	else if ((nState & ODS_SELECTED) == !ODS_SELECTED)
	{
		UpCol = RGB(255,255,255);
		DownCol = RGB(128,128,128);
	}
	CPen pen1, pen2;
	// ����ť����ߺ��ϱ�
	pen1.CreatePen(PS_SOLID, 3, UpCol); //��� �߿� ��ɫ
	pDC->SelectObject(&pen1);           // ����ʶ���
	pDC->MoveTo(0, rect.Height()-1);    // ����λ��
	pDC->LineTo(0,0);					// ����
	pDC->LineTo(rect.Width()-1, 0);     // ���Ż���
	// ����ť���ұߺ��±�
	pen2.CreatePen(PS_SOLID, 2, UpCol); // ��� �߿� ��ɫ
	pDC->SelectObject(&pen2);
	pDC->MoveTo(rect.Width()-1,0);
	pDC->LineTo(rect.Width()-1,rect.Height()-1);
	pDC->LineTo(0,rect.Height()-1);

	pen1.DeleteObject();               // ɾ������ıʶ���
	pen2.DeleteObject();
}
// CButtonAvi ��Ϣ�������




void CButtonAvi::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CRect rect;
	GetClientRect(rect);
	if (!::IsWindow(m_Animate))// �ú���ȷ�������Ĵ��ھ���Ƿ��ʶһ���Ѵ��ڵĴ��ڡ�
	{
		m_Animate.Create(WS_CHILD|WS_VISIBLE, rect, this, 0);
		m_Animate.Open(m_id);
		m_Animate.GetClientRect(rect);
		VERIFY(SetWindowPos(NULL, 0, 0, rect.Width()+2, rect.Height()+2, SWP_NOMOVE)); // SetWindowPos����Z��
		m_Animate.MoveWindow(rect);
	}
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	UINT State = lpDrawItemStruct->itemState;
	DrawButton(pDC, State, rect);
}


void CButtonAvi::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ClientToScreen(&point);
	CRect rect;
	GetWindowRect(rect);
	if (rect.PtInRect(point))
	{
		if (::IsWindow(m_Animate) && !m_play)
		{
			m_Animate.Play(0, -1, 1);
			m_play = TRUE;
			SetCapture();
			// �ú��������ڵ�ǰ�̵߳�ָ��������������겶��һ�����ڲ�������꣬����������붼��Ըô��ڣ����۹���Ƿ��ڴ��ڵı߽��ڡ�ͬһʱ��ֻ����һ�����ڲ�����ꡣ
			// ������������һ���̴߳����Ĵ����ϣ�ֻ�е���������ʱϵͳ�Ž��������ָ��ָ���Ĵ��ڡ�
		}
		else
		{
			m_play = FALSE;
			ReleaseCapture();
			// ���������Ǹú����ӵ�ǰ�߳��еĴ����ͷ���겶�񣬲��ָ�ͨ����������봦��
		}
	}
	//CButton::OnMouseMove(nFlags, point);
}
