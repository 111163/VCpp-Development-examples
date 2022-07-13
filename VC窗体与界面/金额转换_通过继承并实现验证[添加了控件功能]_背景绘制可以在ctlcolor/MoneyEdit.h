#pragma once


// CMoneyEdit

class CMoneyEdit : public CEdit
{
	DECLARE_DYNAMIC(CMoneyEdit)

public:
	CMoneyEdit();
	virtual ~CMoneyEdit();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};


