
// ��ȡ�ַ����к���Dlg.h : ͷ�ļ�
//

#pragma once


// C��ȡ�ַ����к���Dlg �Ի���
class C��ȡ�ַ����к���Dlg : public CDialogEx
{
// ����
public:
	C��ȡ�ַ����к���Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	CString m_strInput;
	CString m_strOutput;
	afx_msg void OnBnClickedButton1();
};
