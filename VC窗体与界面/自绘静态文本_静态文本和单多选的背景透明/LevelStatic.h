#pragma once


// CLevelStatic

class CLevelStatic : public CStatic
{
	DECLARE_DYNAMIC(CLevelStatic)

public:
	CLevelStatic();
	virtual ~CLevelStatic();
	UINT m_TextMargin;  //нд╠╬╠ъ╬Ю

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


