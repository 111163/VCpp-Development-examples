#pragma once


// dlgNoModal �Ի���

class dlgNoModal : public CDialogEx
{
	DECLARE_DYNAMIC(dlgNoModal)

public:
	dlgNoModal(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~dlgNoModal();

// �Ի�������
	enum { IDD = IDD_NOMODAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strEdit;
	CEdit m_ConEdit;
	virtual BOOL OnInitDialog();
	virtual void PostNcDestroy();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual void OnOK();
	virtual void OnCancel();
};
