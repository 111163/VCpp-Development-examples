
// �Զ�����Դ�Ĳ���Dlg.h : ͷ�ļ�
//

#pragma once


// C�Զ�����Դ�Ĳ���Dlg �Ի���
class C�Զ�����Դ�Ĳ���Dlg : public CDialogEx
{
// ����
public:
	C�Զ�����Դ�Ĳ���Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	void loadCustomResource(void);
	CString m_memo;
};
