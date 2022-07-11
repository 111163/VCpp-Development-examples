#pragma once


// CDockBarCtrl

class CDockBarCtrl : public CControlBar
{
	DECLARE_DYNAMIC(CDockBarCtrl)
public:
	CSize m_szFloat;			//����������ʱ�Ĵ�С
	CDialog* m_pDlg;
	CBrush m_WndBrush;
	int m_nDockbarID;			//��¼ͣ��ʱ��CDockBar�ؼ�ID

	int m_nLBandWidth;			//������ͣ��ʱ��߿�Ŀ��
	int m_nRBandWidth;			//������ͣ��ʱ�ұ߿�Ŀ��
	int m_nTBandWidth;			//������ͣ��ʱ�ϱ߿�Ŀ��
	int m_nBBandWidth;			//������ͣ��ʱ�±߿�Ŀ��

	BOOL m_bTraking;
	CRect m_DragRC;				//��¼�϶��ı߿�����
	CRect m_CloseBtnRC;			//�رհ�ť����
	CRect m_MaxBtnRC;			//��ԭ��ť����
	CRect m_TrackingRC;			//����϶�ʱ������

	int m_nTopInterval;			//��������Ը����ڵ�λ��
	int m_nLeftInterval;
	CPoint m_OrginPT;			//��¼Դ�������
	COLORREF m_clTopLine;		//�ǿͻ�������������ɫ
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

	// ͨ����д���������� ���㣬����ͣ��ʱ�����ڵĴ�С
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


