
// �ؼ���Ի���ȱ����仯Dlg.h : ͷ�ļ�
//

#pragma once


// C�ؼ���Ի���ȱ����仯Dlg �Ի���
class C�ؼ���Ի���ȱ����仯Dlg : public CDialogEx
{
// ����
public:
	C�ؼ���Ի���ȱ����仯Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	CEdit m_Edit;
	double ratex,ratey;
	CRect m_CtrlRect;
	BOOL m_IsChange;
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
