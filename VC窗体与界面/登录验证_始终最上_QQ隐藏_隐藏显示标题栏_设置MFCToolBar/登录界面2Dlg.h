
// ��¼����2Dlg.h : ͷ�ļ�
//

#pragma once
#include "LOGIN.h"


// C��¼����2Dlg �Ի���
class C��¼����2Dlg : public CDialogEx
{
// ����
public:
	C��¼����2Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY2_DIALOG };

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

public:
	LOGIN dlgLog;
	DECLARE_MESSAGE_MAP()
	CButton m_conSetTop;
	afx_msg void OnBnClickedSet();
	int m_topFlg;
	BOOL m_titleFlg;
	afx_msg void OnBnClickedTitle();
	CButton m_conTitle;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CMFCToolBar m_toolB;
	afx_msg void OnBnClickedBUTTON32771();
//	virtual HRESULT accDoDefaultAction(VARIANT varChild);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
