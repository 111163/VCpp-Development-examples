
// ListBox�Ĳ���Dlg.h : ͷ�ļ�
//

#pragma once


// CListBox�Ĳ���Dlg �Ի���
class CListBox�Ĳ���Dlg : public CDialogEx
{
// ����
public:
	CListBox�Ĳ���Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LISTBOX_DIALOG };

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
	CListBox m_conList;
	afx_msg void OnBnClickedButton1();
};
