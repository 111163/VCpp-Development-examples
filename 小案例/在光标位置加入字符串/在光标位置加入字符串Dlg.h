
// �ڹ��λ�ü����ַ���Dlg.h : ͷ�ļ�
//

#pragma once


// C�ڹ��λ�ü����ַ���Dlg �Ի���
class C�ڹ��λ�ü����ַ���Dlg : public CDialogEx
{
// ����
public:
	C�ڹ��λ�ü����ַ���Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	CEdit m_celEdit;
	CString m_strAdd;
	CPoint pt;
	afx_msg void OnEnKillfocusEdit();
	afx_msg void OnBnClickedButton1();
};
