#pragma once


// CInput �Ի���

class CInput : public CDialogEx
{
	DECLARE_DYNAMIC(CInput)

public:
	CInput(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInput();
	CString m_centerX;
	CString m_centerY;
	CString m_radius;
	CString m_startAngle;
	CString m_sweepAngle;

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnSet();
};
