// ButtonAvi.cpp : 实现文件
//

#include "stdafx.h"
#include "带动画的按钮.h"
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


void CButtonAvi::LoadAVI(UINT nID) // 用它来获取视频资源
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
	// 画按钮的左边和上边
	pen1.CreatePen(PS_SOLID, 3, UpCol); //风格 线宽 颜色
	pDC->SelectObject(&pen1);           // 构造笔对象
	pDC->MoveTo(0, rect.Height()-1);    // 到达位置
	pDC->LineTo(0,0);					// 划线
	pDC->LineTo(rect.Width()-1, 0);     // 连着划线
	// 画按钮的右边和下边
	pen2.CreatePen(PS_SOLID, 2, UpCol); // 风格 线宽 颜色
	pDC->SelectObject(&pen2);
	pDC->MoveTo(rect.Width()-1,0);
	pDC->LineTo(rect.Width()-1,rect.Height()-1);
	pDC->LineTo(0,rect.Height()-1);

	pen1.DeleteObject();               // 删除构造的笔对象
	pen2.DeleteObject();
}
// CButtonAvi 消息处理程序




void CButtonAvi::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CRect rect;
	GetClientRect(rect);
	if (!::IsWindow(m_Animate))// 该函数确定给定的窗口句柄是否标识一个已存在的窗口。
	{
		m_Animate.Create(WS_CHILD|WS_VISIBLE, rect, this, 0);
		m_Animate.Open(m_id);
		m_Animate.GetClientRect(rect);
		VERIFY(SetWindowPos(NULL, 0, 0, rect.Width()+2, rect.Height()+2, SWP_NOMOVE)); // SetWindowPos调整Z序
		m_Animate.MoveWindow(rect);
	}
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	UINT State = lpDrawItemStruct->itemState;
	DrawButton(pDC, State, rect);
}


void CButtonAvi::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
			// 该函数在属于当前线程的指定窗口里设置鼠标捕获。一旦窗口捕获了鼠标，所有鼠标输入都针对该窗口，无论光标是否在窗口的边界内。同一时刻只能有一个窗口捕获鼠标。
			// 如果鼠标光标在另一个线程创建的窗口上，只有当鼠标键按下时系统才将鼠标输入指向指定的窗口。
		}
		else
		{
			m_play = FALSE;
			ReleaseCapture();
			// 函数功能是该函数从当前线程中的窗口释放鼠标捕获，并恢复通常的鼠标输入处理。
		}
	}
	//CButton::OnMouseMove(nFlags, point);
}
