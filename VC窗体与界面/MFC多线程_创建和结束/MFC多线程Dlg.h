
// MFC���߳�Dlg.h : ͷ�ļ�
//

#pragma once
#include "UserThread.h"


// CMFC���߳�Dlg �Ի���
class CMFC���߳�Dlg : public CDialogEx
{
// ����
public:
	CMFC���߳�Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	CWinThread* m_pThread;

// �Ի�������
	enum { IDD = IDD_MFC_DIALOG };

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
	virtual void OnCancel();
};
