#pragma once


// CDockBarCtrl

class CDockBarCtrl : public CControlBar
{
	DECLARE_DYNAMIC(CDockBarCtrl)
public:
	CSize m_szFloat;			//控制条浮动时的大小
	CDialog* m_pDlg;
	CBrush m_WndBrush;
	int m_nDockbarID;			//记录停靠时的CDockBar控件ID

	int m_nLBandWidth;			//控制条停靠时左边框的宽度
	int m_nRBandWidth;			//控制条停靠时右边框的宽度
	int m_nTBandWidth;			//控制条停靠时上边框的宽度
	int m_nBBandWidth;			//控制条停靠时下边框的宽度

	BOOL m_bTraking;
	CRect m_DragRC;				//记录拖动的边框区域
	CRect m_CloseBtnRC;			//关闭按钮区域
	CRect m_MaxBtnRC;			//还原按钮区域
	CRect m_TrackingRC;			//鼠标拖动时的区域

	int m_nTopInterval;			//控制条相对父窗口的位置
	int m_nLeftInterval;
	CPoint m_OrginPT;			//记录源鼠标坐标
	COLORREF m_clTopLine;		//非客户区域线条的颜色
	COLORREF m_clBottomLine;
	BOOL	m_bInRect;

	BOOL Create(CWnd* pWnd, CDialog* pDlg, UINT nID, UINT nDockBarID, 
		DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_LEFT);	

public:
	CDockBarCtrl();

	void ShowControlbar(BOOL bShow = TRUE);
	void DrawDoubleLine(CDC* pDC);
	void EndTracking();
	void BeginTracking();
	void DrawDotLine(CRect LineRC);

	// 通过重写这两个方法 计算，设置停靠时父窗口的大小
	virtual CSize CalcFixedLayout(BOOL bStretch, BOOL bHorz);
	virtual CSize  CalcDynamicLayout(int nLength, DWORD dwMode);
	virtual ~CDockBarCtrl();
	virtual void OnUpdateCmdUI(CFrameWnd* pTarget, BOOL bDisableIfNoHndler);

protected:
	afx_msg void OnWindowPosChanged(WINDOWPOS FAR* lpwndpos);
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS FAR* lpncsp);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	afx_msg void OnNcPaint();
	afx_msg void OnNcLButtonDblClk(UINT nHitTest, CPoint point);
	afx_msg void OnNcLButtonUp(UINT nHitTest, CPoint point);

	DECLARE_MESSAGE_MAP()
};


