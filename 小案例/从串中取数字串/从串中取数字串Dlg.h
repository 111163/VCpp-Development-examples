
// �Ӵ���ȡ���ִ�Dlg.h : ͷ�ļ�
//

#pragma once


// C�Ӵ���ȡ���ִ�Dlg �Ի���
class C�Ӵ���ȡ���ִ�Dlg : public CDialogEx
{
// ����
public:
	C�Ӵ���ȡ���ִ�Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	afx_msg void OnBnClickedButton1();
	CString m_strEdit;
	CString m_strNum;
};
