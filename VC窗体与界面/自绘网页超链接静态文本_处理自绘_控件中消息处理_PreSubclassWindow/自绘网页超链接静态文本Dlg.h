
// �Ի���ҳ�����Ӿ�̬�ı�Dlg.h : ͷ�ļ�
//

#pragma once
#include "SuperLabel.h"


// C�Ի���ҳ�����Ӿ�̬�ı�Dlg �Ի���
class C�Ի���ҳ�����Ӿ�̬�ı�Dlg : public CDialogEx
{
// ����
public:
	C�Ի���ҳ�����Ӿ�̬�ı�Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	CSuperLabel m_ConStaticText;
};
