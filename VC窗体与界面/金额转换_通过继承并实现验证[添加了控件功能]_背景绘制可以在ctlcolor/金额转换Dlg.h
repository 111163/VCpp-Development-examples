
// ���ת��Dlg.h : ͷ�ļ�
//

#pragma once
#include "MoneyEdit.h"


// C���ת��Dlg �Ի���
class C���ת��Dlg : public CDialogEx
{
// ����
public:
	C���ת��Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	void ChangeMoney(CString str,int num);
	CString Capitalization(CString str);

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
	CMoneyEdit m_ConInp;
//	CEdit m_StrEdit2;
	CString m_StrEdit2;
};
