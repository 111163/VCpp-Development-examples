#pragma once


// BeginIII �Ի���

class BeginIII : public CDialogEx
{
	DECLARE_DYNAMIC(BeginIII)

public:
	BeginIII(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~BeginIII();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
