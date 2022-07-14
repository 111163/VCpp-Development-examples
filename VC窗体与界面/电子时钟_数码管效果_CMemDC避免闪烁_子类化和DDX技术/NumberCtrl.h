#pragma once

// CNumberCtrl

class CNumberCtrl : public CStatic
{
	DECLARE_DYNAMIC(CNumberCtrl)

public:
	CNumberCtrl();
	virtual ~CNumberCtrl();
	CString m_csText;  // 文本
	int m_nNumberWidth;		//数字宽度
	int m_nNumberHeight;	//数字高度
	int m_nNumberLen;		//数字位数

public:
	void SubClassCtrl(UINT uID, CWnd* pParent);
	LPTSTR GetText();
	void SetText(LPCTSTR text);

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


