
// Ӣ���ַ�������ĸ��дDlg.h : ͷ�ļ�
//

#pragma once


// CӢ���ַ�������ĸ��дDlg �Ի���
class CӢ���ַ�������ĸ��дDlg : public CDialogEx
{
// ����
public:
	CӢ���ַ�������ĸ��дDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

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
	afx_msg void OnBnClickedExit();
	CString m_strSou;
	CString m_strDes;
	afx_msg void OnBnClickedFm();
};
