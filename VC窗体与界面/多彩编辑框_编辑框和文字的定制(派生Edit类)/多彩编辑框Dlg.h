
// ��ʱ༭��Dlg.h : ͷ�ļ�
//

#pragma once
#include "ColorEdit.h"


// C��ʱ༭��Dlg �Ի���
class C��ʱ༭��Dlg : public CDialogEx
{
// ����
public:
	C��ʱ༭��Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	CColorEdit m_Edit1;
	CColorEdit m_Edit2;
	CColorEdit m_Edit3;
};
