#pragma once

// CNumberCtrl

class CNumberCtrl : public CStatic
{
	DECLARE_DYNAMIC(CNumberCtrl)

public:
	CNumberCtrl();
	virtual ~CNumberCtrl();
	CString m_csText;  // �ı�
	int m_nNumberWidth;		//���ֿ��
	int m_nNumberHeight;	//���ָ߶�
	int m_nNumberLen;		//����λ��

public:
	void SubClassCtrl(UINT uID, CWnd* pParent);
	LPTSTR GetText();
	void SetText(LPCTSTR text);

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


