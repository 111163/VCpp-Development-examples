#pragma once


// dlgModal �Ի���

class dlgModal : public CDialogEx
{
	DECLARE_DYNAMIC(dlgModal)

public:
	dlgModal(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~dlgModal();

// �Ի�������
	enum { IDD = IDD_MODAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strEdit;
	virtual BOOL OnInitDialog();
	CEdit m_ConEdit;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
