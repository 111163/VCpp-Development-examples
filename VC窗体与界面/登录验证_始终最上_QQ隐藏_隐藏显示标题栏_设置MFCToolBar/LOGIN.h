#pragma once


// LOGIN 对话框

class LOGIN : public CDialogEx
{
	DECLARE_DYNAMIC(LOGIN)

public:
	LOGIN(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~LOGIN();

// 对话框数据
	enum { IDD = IDD_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedClose1();
	afx_msg void OnBnClickedLogin();
	CString m_strPassWd;
	CString m_strUserName;
	int num;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
