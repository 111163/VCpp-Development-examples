#pragma once


// CButtonAvi

class CButtonAvi : public CButton
{
	DECLARE_DYNAMIC(CButtonAvi)

public:
	CButtonAvi();
	virtual ~CButtonAvi();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	void DrawButton(CDC* pDC,UINT nState,CRect rect);
	void LoadAVI(UINT nID);
	CAnimateCtrl m_Animate;
	BOOL m_play;
	int m_id;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};


