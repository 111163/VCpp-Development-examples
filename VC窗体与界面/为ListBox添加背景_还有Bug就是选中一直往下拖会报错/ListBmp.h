#pragma once


// CListBmp

class CListBmp : public CListBox
{
	DECLARE_DYNAMIC(CListBmp)

public:
	CListBmp();
	virtual ~CListBmp();
	CFont *	m_pFont;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};


