
// ����ʷ��Ϣ�Ĳ˵�Dlg.h : ͷ�ļ�
//

#pragma once


// C����ʷ��Ϣ�Ĳ˵�Dlg �Ի���
class C����ʷ��Ϣ�Ĳ˵�Dlg : public CDialogEx
{
// ����
public:
	C����ʷ��Ϣ�Ĳ˵�Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	CMenu m_Menu;
	afx_msg void On32771();
	int num;
	afx_msg void OnOopen();
	afx_msg void OnCcl();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
