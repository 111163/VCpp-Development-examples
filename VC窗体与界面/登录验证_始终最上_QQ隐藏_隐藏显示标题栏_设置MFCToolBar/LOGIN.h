#pragma once


// LOGIN �Ի���

class LOGIN : public CDialogEx
{
	DECLARE_DYNAMIC(LOGIN)

public:
	LOGIN(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~LOGIN();

// �Ի�������
	enum { IDD = IDD_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedClose1();
	afx_msg void OnBnClickedLogin();
	CString m_strPassWd;
	CString m_strUserName;
	int num;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
