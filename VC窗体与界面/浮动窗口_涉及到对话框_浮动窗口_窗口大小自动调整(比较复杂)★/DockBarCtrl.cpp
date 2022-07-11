// DockBarCtrl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��������.h"
#include "DockBarCtrl.h"


// CDockBarCtrl

IMPLEMENT_DYNAMIC(CDockBarCtrl, CControlBar)

CDockBarCtrl::CDockBarCtrl()
{
	m_pDlg = NULL;
	m_WndBrush.CreateSolidBrush(::GetSysColor(COLOR_BTNFACE));
	m_nBBandWidth = 3;
	m_nLBandWidth = 3;
	m_nRBandWidth = 6;
	m_nTBandWidth = 20;
	m_bTraking = FALSE;
	m_bInRect = FALSE;
	m_clTopLine = GetSysColor(COLOR_BTNHILIGHT);
	m_clBottomLine = GetSysColor(COLOR_BTNSHADOW);
	m_szFloat.cx = 230;
	m_szFloat.cy = 130;
}

CDockBarCtrl::~CDockBarCtrl()
{
}


BEGIN_MESSAGE_MAP(CDockBarCtrl, CControlBar)
	ON_WM_WINDOWPOSCHANGED()
	ON_WM_NCCALCSIZE()
	ON_WM_NCHITTEST()
	ON_WM_SETCURSOR()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_NCLBUTTONDOWN()
	ON_WM_NCPAINT()
	ON_WM_NCLBUTTONDBLCLK()
	ON_WM_NCLBUTTONUP()
END_MESSAGE_MAP()



// CDockBarCtrl ��Ϣ�������

CSize CDockBarCtrl::CalcDynamicLayout(int nLength, DWORD dwMode)
{

	CRect winRC;
	if (IsFloating())
	{
		//��ȡMiniDockFrameWnd����	
		CFrameWnd* pFrameWnd = GetDockingFrame();
		if (pFrameWnd != NULL)
		{
			//�޸Ĵ��ڷ���ڸ���ʱ����ͬʱ�������ڵĿ�Ⱥ͸߶�
			pFrameWnd->ModifyStyle(MFS_4THICKFRAME, 0);
			pFrameWnd->GetWindowRect(winRC);
		}
	}
	//����MiniDockFrameWnd���ڱ������ͱ߿�Ŀ�Ⱥ͸߶�
	int nBorderCX = GetSystemMetrics(SM_CYEDGE) + GetSystemMetrics(SM_CYBORDER);
	int nTitleCY  = GetSystemMetrics(SM_CYCAPTION);

	//����������ˮƽ��ֱͣ��������ͣ��������
	if (dwMode & (LM_HORZDOCK | LM_VERTDOCK))	
	{	
		//��ӵ���CalcFixedLayout����
		return CControlBar::CalcDynamicLayout(nLength, dwMode);
	}

	//�������ø����������Ŀ��
	if (dwMode & LM_COMMIT)
	{
		return m_szFloat;
	}
	if (dwMode & LM_MRUWIDTH)
	{
		return m_szFloat;
	}

	CPoint CursorPT;
	GetCursorPos(&CursorPT);

	//�ж��û��ڴ�����ĸ��Ƕ���ʼ������С,ʵ����m_pDockContext->m_nHitTest��ֵ
	//����CMiniDockFrameWnd��OnNcLButtonDown�����е���m_pDockContext��StartResize�������õ�
	if (IsFloating())
	{
		switch (m_pDockContext->m_nHitTest)
		{
		case HTTOPLEFT:		//��������Ͻ�
			{
				m_szFloat.cx = winRC.right - CursorPT.x - nBorderCX;
				m_szFloat.cy = winRC.bottom - nTitleCY + nBorderCX  - CursorPT.y;
				//����CMiniDockFrameWnd�����Ͻ�����Ϊ��ǰ�ƶ����������
				m_pDockContext->m_rectFrameDragHorz.top = CursorPT.y;	
				m_pDockContext->m_rectFrameDragHorz.left =CursorPT.x;
				return  m_szFloat; 
			}
		case HTTOPRIGHT:	//��������Ͻ�
			{			
				m_szFloat.cx = CursorPT.x - winRC.left;
				m_szFloat.cy = winRC.bottom - nTitleCY - CursorPT.y + nBorderCX ;
				m_pDockContext->m_rectFrameDragHorz.top = CursorPT.y;
				return m_szFloat;
			}
		case HTBOTTOMLEFT:	//��������½�
			{
				m_szFloat.cx =  winRC.right-CursorPT.x - nBorderCX*2;
				m_szFloat.cy = CursorPT.y-winRC.top - nTitleCY + nBorderCX*2;
				m_pDockContext->m_rectFrameDragHorz.left = CursorPT.x ;
				return m_szFloat;
			}
		case HTBOTTOMRIGHT: //��������½�
			{
				m_szFloat.cx = CursorPT.x - winRC.left;
				m_szFloat.cy = CursorPT.y - winRC.top - nTitleCY + nBorderCX*2;
				return m_szFloat;
			}
		}
	}
	//����ʱ������߿�ĸ߶�
	if (dwMode & LM_LENGTHY)
	{
		m_szFloat.cy = nLength;
		return CSize (m_szFloat.cx, nLength);
	}
	//����ʱ������߿�Ŀ��
	if (dwMode & LM_HORZ)
	{
		m_szFloat.cx = nLength;
		return CSize(nLength, m_szFloat.cy);
	}
}


CSize CDockBarCtrl::CalcFixedLayout(BOOL bStretch, BOOL bHorz)
{
	CRect winRC;
	int nDockWidth ;
	int nDockHeight ;
	if (bHorz)	//ˮƽͣ��
	{
		m_pDockSite->GetControlBar(AFX_IDW_DOCKBAR_TOP)->GetWindowRect(winRC);
		nDockWidth = bStretch? 32767 : winRC.Width() + 4;
		return CSize(nDockWidth, m_szFloat.cy);
	}
	else		//��ֱͣ��
	{
		m_pDockSite->GetControlBar(AFX_IDW_DOCKBAR_LEFT)->GetWindowRect(winRC);
		nDockHeight = bStretch? 32767 :winRC.Height() + 4;
		return CSize(m_szFloat.cx, nDockHeight);
	}
}


BOOL CDockBarCtrl::Create(CWnd* pParentWnd, CDialog* pDialog, UINT nID, UINT nDockBarID, DWORD dwStyle)
{
	ASSERT_VALID(pParentWnd);

	ASSERT(!((dwStyle& CBRS_SIZE_DYNAMIC)&&(dwStyle&CBRS_SIZE_FIXED )));

	m_dwStyle = dwStyle & CBRS_ALL;
	//ע�ᴰ����
	CString csClassName;
	csClassName = AfxRegisterWndClass(CS_DBLCLKS, LoadCursor(NULL, IDC_ARROW), m_WndBrush, 0);
	//����������
	BOOL bRet = CWnd::Create(csClassName, "��������", dwStyle, CRect(0, 0, 0, 0), pParentWnd, nDockBarID, NULL);

	m_pDlg = pDialog;
	m_pDlg->Create(nID, this);
	return TRUE;
}

//�����϶��ķָ���
void CDockBarCtrl::DrawDotLine(CRect LineRC)
{
	CDC *pDC = m_pDockSite->GetDCEx(NULL, DCX_WINDOW|DCX_CACHE|DCX_LOCKWINDOWUPDATE);

	CBrush brush (RGB(0, 0, 255));
	HBRUSH hOldBrush = NULL;
	hOldBrush = (HBRUSH)SelectObject(pDC->m_hDC, brush.m_hObject);
	if (m_dwStyle&(CBRS_ORIENT_HORZ))
		pDC->PatBlt(LineRC.left ,LineRC.top + 8, LineRC.Width(), LineRC.Height(), PATINVERT);
	else
		pDC->PatBlt(LineRC.left  +m_nLBandWidth, LineRC.top, LineRC.Width(), LineRC.Height(), PATINVERT);
	if (hOldBrush != NULL)
		SelectObject(pDC->m_hDC, hOldBrush);
	m_pDockSite->ReleaseDC(pDC);

}

void CDockBarCtrl::OnWindowPosChanged(WINDOWPOS FAR* lpwndpos) 
{
	CControlBar::OnWindowPosChanged(lpwndpos);
	m_nDockbarID = GetParent()->GetDlgCtrlID();	

	if (m_bInRect)
	{
		CRect rc;
		GetClientRect(rc);
		m_pDlg->MoveWindow(rc);
		return;
	}
	m_pDockSite->RecalcLayout();
	m_bInRect = TRUE;
	SetWindowPos(NULL, 0,0,0,0,
		SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);
	m_bInRect = FALSE;

}

//����ǿͻ�����Ĵ�С
void CDockBarCtrl::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS FAR* lpncsp) 
{
	switch (m_nDockbarID)
	{
	case AFX_IDW_DOCKBAR_TOP:	//������ͣ�����Ϸ�
		{
			//lpncsp->rgrc[0]��ʾ�ͻ����򣬿ؼ����µĲ���Ϊ�ǿͻ�����
			lpncsp->rgrc[0].left += m_nTBandWidth;	//������ߵķǿͻ�������Ϊm_nTBandWidth
			lpncsp->rgrc[0].right -= m_nBBandWidth;	//�����ұߵķǿͻ�������Ϊm_nBBandWidth
			lpncsp->rgrc[0].top +=  m_nLBandWidth;
			lpncsp->rgrc[0].bottom -= m_nRBandWidth;
			break;
		}
	case AFX_IDW_DOCKBAR_LEFT: //������ͣ������
		{
			lpncsp->rgrc[0].left += m_nLBandWidth;	
			lpncsp->rgrc[0].right -= m_nRBandWidth;	
			lpncsp->rgrc[0].top +=  m_nTBandWidth;
			lpncsp->rgrc[0].bottom -= m_nBBandWidth;		
			break;
		}
	case AFX_IDW_DOCKBAR_RIGHT: //������ͣ�����ҷ�
		{
			lpncsp->rgrc[0].left += m_nRBandWidth;	
			lpncsp->rgrc[0].right -= m_nLBandWidth;	
			lpncsp->rgrc[0].top +=  m_nTBandWidth;
			lpncsp->rgrc[0].bottom -= m_nBBandWidth;				
			break;
		}
	case AFX_IDW_DOCKBAR_BOTTOM: //������ͣ�����·�
		{
			lpncsp->rgrc[0].left += m_nTBandWidth;	
			lpncsp->rgrc[0].right -= m_nLBandWidth;		
			lpncsp->rgrc[0].top +=  m_nRBandWidth;
			lpncsp->rgrc[0].bottom -= m_nBBandWidth;		
			break;
		}
	}
}

LRESULT CDockBarCtrl::OnNcHitTest(CPoint point) 
{
	CRect winRC, titleRC;
	m_pDockSite->RecalcLayout();
	GetWindowRect(winRC);
	if (m_dwStyle & CBRS_ORIENT_VERT)	//��ֱ��ʾʱ�϶��߿������ 
	{
		titleRC.CopyRect(CRect(0, 0, winRC.Width() - m_MaxBtnRC.Width(), m_nTBandWidth));
		//��ֱ��ʾʱ����������
		if (m_nDockbarID==AFX_IDW_DOCKBAR_LEFT)		//�����ͣ��
		{
			m_DragRC.CopyRect(CRect(winRC.Width() - m_nLBandWidth,
				0, winRC.Width(), winRC.Height()));
		}
		else										//���ұ�ͣ��
		{
			m_DragRC.CopyRect(CRect(0, 0, m_nLBandWidth, winRC.Height()));
		}
		m_DragRC.InflateRect(2,0,2,0);
	}
	else											//ˮƽ��ʾʱ�����϶��߿������
	{
		//ˮƽ��ʾʱ�������������
		titleRC.CopyRect(CRect(0, 0, m_nTBandWidth, winRC.Width() - m_MaxBtnRC.Width()));
		if (m_nDockbarID == AFX_IDW_DOCKBAR_TOP )	//���Ϸ�ͣ��
		{
			m_DragRC.CopyRect(CRect(0, winRC.Height() - m_nLBandWidth, 
				winRC.Width(), winRC.Height()));
		}
		else										//���·�ͣ��
		{
			m_DragRC.CopyRect(CRect(0, 0, winRC.Width(), m_nLBandWidth));
		}
		m_DragRC.InflateRect(0, 2, 0, 2);
	}

	point.Offset(-winRC.left,-winRC.top);
	if (m_CloseBtnRC.PtInRect(point))			//�ж��Ƿ�λ�ڹرհ�ť����
		return HTSYSMENU;
	if (m_MaxBtnRC.PtInRect(point))				//�Ƿ�λ�ڻ�ԭ��ť����
		return HTMAXBUTTON;
	if (titleRC.PtInRect(point))				//�Ƿ�λ�ڱ���������
		return HTCAPTION ;
	if (m_DragRC.PtInRect(point))				//�Ƿ�λ���϶��߿�����
		return HTSIZE;
	return  CControlBar::OnNcHitTest(point);
}

void CDockBarCtrl::BeginTracking()
{
	SetCapture();	
	m_bTraking = TRUE;	
	RedrawWindow(NULL, NULL, RDW_ALLCHILDREN | RDW_UPDATENOW);	
	m_pDockSite->LockWindowUpdate();

	CRect winRC, siteRC;
	GetWindowRect(winRC);
	m_pDockSite->GetWindowRect(siteRC);

	m_nLeftInterval  = winRC.left - siteRC.left;
	m_nTopInterval = winRC.top - siteRC.top - 4;

	m_TrackingRC = m_DragRC;

	if (m_nDockbarID == AFX_IDW_DOCKBAR_LEFT)
	{
		m_TrackingRC.DeflateRect(0, 4, 0, 0);
		m_TrackingRC.OffsetRect(0, m_nTopInterval);
	}
	if (m_nDockbarID == AFX_IDW_DOCKBAR_RIGHT)
	{
		m_TrackingRC.DeflateRect(0, 4, 0, 0);
		m_TrackingRC.OffsetRect(0, m_nTopInterval);
	}
	if (m_nDockbarID == AFX_IDW_DOCKBAR_BOTTOM)
	{
		m_TrackingRC.DeflateRect(4, 0, 4, 0);
		m_TrackingRC.OffsetRect(m_nLeftInterval, 0);
	}
	if (m_nDockbarID == AFX_IDW_DOCKBAR_TOP)
	{
		m_TrackingRC.DeflateRect(4, 0, 4, 0);
		m_TrackingRC.OffsetRect(m_nLeftInterval, 0);
	}
	DrawDotLine(m_TrackingRC);
}

void CDockBarCtrl::EndTracking()
{
	ReleaseCapture();
	m_bTraking = FALSE;
	m_pDockSite->UnlockWindowUpdate();
	RedrawWindow(NULL, NULL, RDW_ALLCHILDREN | RDW_UPDATENOW);	

	CPoint cusorPT;
	GetCursorPos(&cusorPT);

	CRect winRC;
	m_pDockSite->GetWindowRect(winRC);
	if (m_nDockbarID == AFX_IDW_DOCKBAR_TOP)
	{
		m_szFloat.cy += cusorPT.y - m_OrginPT.y;
	}
	else if (m_nDockbarID == AFX_IDW_DOCKBAR_LEFT)
	{
		m_szFloat.cx += cusorPT.x - m_OrginPT.x;
	}
	else if (m_nDockbarID == AFX_IDW_DOCKBAR_RIGHT)
	{
		m_szFloat.cx += m_OrginPT.x - cusorPT.x;
	}
	else if  (m_nDockbarID == AFX_IDW_DOCKBAR_BOTTOM)
	{
		m_szFloat.cy += m_OrginPT.y - cusorPT.y;
	}
	DrawDotLine(m_TrackingRC);
	m_pDockSite->RecalcLayout();

}

BOOL CDockBarCtrl::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	if (nHitTest ==	HTSIZE)
	{
		if (m_dwStyle & CBRS_ORIENT_HORZ)
			SetCursor(LoadCursor(NULL, IDC_SIZENS));
		else
			SetCursor(LoadCursor(NULL, IDC_SIZEWE));
	}
	else
	{
		return CControlBar::OnSetCursor(pWnd, nHitTest, message);
	}
}

void CDockBarCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
	if (!m_bTraking)
	{
		CControlBar::OnMouseMove(nFlags, point);
	}
	else 
	{
		CRect winRC;
		GetWindowRect(winRC);
		CPoint centerPT;
		centerPT = m_TrackingRC.CenterPoint();
		if (m_dwStyle & CBRS_ORIENT_HORZ)
		{
			DrawDotLine(m_TrackingRC);	
			point.y += m_nTopInterval;
			m_TrackingRC.OffsetRect(0, point.y - centerPT.y);
			DrawDotLine(m_TrackingRC);
		}
		else
		{		
			DrawDotLine(m_TrackingRC);	
			if (m_nDockbarID == AFX_IDW_DOCKBAR_RIGHT)
				point.x += m_nLeftInterval + m_nLBandWidth;
			point.y += m_nTopInterval;
			m_TrackingRC.OffsetRect(point.x-centerPT.x,0);
			DrawDotLine(m_TrackingRC);
		}
	}
}

void CDockBarCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if (m_bTraking)
	{
		EndTracking();
	}
	else
	{
		CControlBar::OnLButtonUp(nFlags, point);	
	}
}

void CDockBarCtrl::OnNcLButtonDown(UINT nHitTest, CPoint point) 
{
	switch( nHitTest)
	{
	case HTSYSMENU:					//������¹رհ�ť,���ؿ�����
		m_pDockSite->ShowControlBar(this, FALSE, FALSE);
		break;
	case HTMAXBUTTON:
		m_pDockContext->ToggleDocking();
		break;
	case HTCAPTION :
		if (!IsFloating())
			m_pDockContext->StartDrag(point);
		break;
	case HTSIZE:
		{
			m_OrginPT = point;
			if (!IsFloating())
				BeginTracking();	//��ʼ�����������Ĵ�С
		}
		break;
	}
}

void CDockBarCtrl::DrawDoubleLine(CDC *pDC)
{
	if (IsFloating()) //������ڸ���״̬�˳�
		return;

	m_pDockSite->RecalcLayout();

	CRect clientRC,winRC;
	GetClientRect(clientRC);
	GetWindowRect(winRC);
	if( m_dwStyle & CBRS_ORIENT_HORZ )	//ˮƽ����ͣ��
	{
		int nTop, nBottom;
		if (m_nDockbarID == AFX_IDW_DOCKBAR_TOP)	//�Ϸ���ͣ��
		{
			nTop = m_nLBandWidth;
			nBottom = m_nLBandWidth + 14;
		}
		else										//�·���ͣ��
		{
			nTop = m_nRBandWidth;
			nBottom = m_nRBandWidth + 14;			
		}
		m_CloseBtnRC.CopyRect(CRect(4, nTop, 18, nBottom));
		//���ƹرհ�ť
		pDC->DrawFrameControl(m_CloseBtnRC ,DFC_CAPTION, DFCS_CAPTIONCLOSE);		

		m_MaxBtnRC.top = m_CloseBtnRC.bottom + 4;
		m_MaxBtnRC.bottom = m_MaxBtnRC.top + m_CloseBtnRC.Height();
		m_MaxBtnRC.left = m_CloseBtnRC.left;
		m_MaxBtnRC.right = m_CloseBtnRC.right;
		//������󻯰�ť
		pDC->DrawFrameControl(m_MaxBtnRC, DFC_CAPTION, DFCS_CAPTIONMAX);

		//��������
		CRect lineRC;
		lineRC.top= m_MaxBtnRC.bottom + 2;
		lineRC.bottom = winRC.Height() - m_nLBandWidth;
		lineRC.left= m_MaxBtnRC.left + 2;
		lineRC.right = m_MaxBtnRC.left + 5;
		pDC->Draw3dRect(lineRC, m_clTopLine, m_clBottomLine);

		lineRC.left = lineRC.right + 2;
		lineRC.right = lineRC.left + 3;  
		pDC->Draw3dRect(lineRC, m_clTopLine, m_clBottomLine);
	}
	else								//��ֱ����ͣ��
	{
		int nRightPos = clientRC.Width() + m_nLBandWidth;
		int nLeftPos = nRightPos - 16;
		m_CloseBtnRC.CopyRect(CRect(nLeftPos, 4, nRightPos, 18)); //ȷ���رհ�ť����
		//���ƹرհ�ť
		pDC->DrawFrameControl(m_CloseBtnRC, DFC_CAPTION, DFCS_CAPTIONCLOSE);

		m_MaxBtnRC.top = m_CloseBtnRC.top;
		m_MaxBtnRC.bottom = m_CloseBtnRC.bottom;
		m_MaxBtnRC.left = m_CloseBtnRC.left - m_CloseBtnRC.Width() - 4; //4��������ť�ļ��
		m_MaxBtnRC.right = m_MaxBtnRC.left + m_CloseBtnRC.Width();
		//������󻯰�ť
		pDC->DrawFrameControl(m_MaxBtnRC, DFC_CAPTION, DFCS_CAPTIONMAX);
		//��������
		CRect lineRC;//������������
		lineRC.top = m_CloseBtnRC.top + 3;
		lineRC.left = m_nLBandWidth + 2;
		lineRC.right = m_MaxBtnRC.left - 2;
		lineRC.bottom = lineRC.top + 3;

		pDC->Draw3dRect(lineRC, m_clTopLine, m_clBottomLine);
		lineRC.DeflateRect(0, 4, 0, -4);
		pDC->Draw3dRect(lineRC, m_clTopLine, m_clBottomLine);
	}
}

void CDockBarCtrl::OnNcPaint() 
{
	EraseNonClient();	
	CDC* pDC = GetWindowDC();
	DrawDoubleLine(pDC);		
}

void CDockBarCtrl::OnUpdateCmdUI(CFrameWnd* pTarget, BOOL bDisableIfNoHndler)
{	
	CWnd::UpdateDialogControls(pTarget, bDisableIfNoHndler);
}

void CDockBarCtrl::OnNcLButtonDblClk(UINT nHitTest, CPoint point) 
{
	if ((m_pDockBar != NULL) && (nHitTest == HTCAPTION))
	{
		m_pDockContext->ToggleDocking();
	}
	else
		CWnd::OnNcLButtonDblClk(nHitTest, point);	
}

void CDockBarCtrl::OnNcLButtonUp(UINT nHitTest, CPoint point) 
{
	if (m_bTraking)
	{
		EndTracking();
	}
	else
	{
		CControlBar::OnNcLButtonUp(nHitTest, point);
	}
}

void CDockBarCtrl::ShowControlbar(BOOL bShow)
{	
	m_pDockSite->ShowControlBar(this, bShow, FALSE);
}


