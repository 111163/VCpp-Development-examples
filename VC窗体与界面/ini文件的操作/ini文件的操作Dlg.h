
// ini�ļ��Ĳ���Dlg.h : ͷ�ļ�
//

#pragma once


// Cini�ļ��Ĳ���Dlg �Ի���
class Cini�ļ��Ĳ���Dlg : public CDialogEx
{
// ����
public:
	Cini�ļ��Ĳ���Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_INI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CEdit m_IP;
	CEdit m_Database;
	CEdit m_UID;
	CEdit m_PWD;
	CEdit m_ID;
	afx_msg void OnBnClickedButton2();
};
