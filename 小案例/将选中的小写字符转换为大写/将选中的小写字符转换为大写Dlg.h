
// ��ѡ�е�Сд�ַ�ת��Ϊ��дDlg.h : ͷ�ļ�
//

#pragma once


// C��ѡ�е�Сд�ַ�ת��Ϊ��дDlg �Ի���
class C��ѡ�е�Сд�ַ�ת��Ϊ��дDlg : public CDialogEx
{
// ����
public:
	C��ѡ�е�Сд�ַ�ת��Ϊ��дDlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	CString m_strEdit;
	CEdit m_conEdit;
	afx_msg void OnBnClickedButton1();
};
