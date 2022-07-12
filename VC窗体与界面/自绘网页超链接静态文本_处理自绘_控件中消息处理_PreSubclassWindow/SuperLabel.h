#pragma once


// CSuperLabel

class CSuperLabel : public CStatic
{
	DECLARE_DYNAMIC(CSuperLabel)

public:
	CSuperLabel();
	virtual ~CSuperLabel();
public:
	CFont     m_Font;
	CString   m_ConnectStr;
	LOGFONT   lfont;

protected:
	DECLARE_MESSAGE_MAP()
	virtual void PreSubclassWindow();
public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};


