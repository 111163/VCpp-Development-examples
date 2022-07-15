#pragma once


// CColorEdit

class CColorEdit : public CEdit
{
	DECLARE_DYNAMIC(CColorEdit)

public:
	CColorEdit();
	virtual ~CColorEdit();
	COLORREF m_FrameColor;
	COLORREF m_TextColor;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	void SetFrameColor(COLORREF color);
	void SetTextColor(COLORREF color);
};


