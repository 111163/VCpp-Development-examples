
// ���ұ༭�����Ƿ���ĳ���ַ���Dlg.h : ͷ�ļ�
//

#pragma once


// C���ұ༭�����Ƿ���ĳ���ַ���Dlg �Ի���
class C���ұ༭�����Ƿ���ĳ���ַ���Dlg : public CDialogEx
{
// ����
public:
	C���ұ༭�����Ƿ���ĳ���ַ���Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	CString m_strFind;
	CStringArray strArray;
	afx_msg void OnBnClickedButton1();
};
