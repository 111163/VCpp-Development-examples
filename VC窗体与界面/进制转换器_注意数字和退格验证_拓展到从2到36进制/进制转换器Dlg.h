
// ����ת����Dlg.h : ͷ�ļ�
//

#pragma once
#include "MyEdit.h"


// C����ת����Dlg �Ի���
class C����ת����Dlg : public CDialogEx
{
// ����
public:
	C����ת����Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	CMyEdit m_m1;  //�������Ƕ�Edit������֤�������Ҵ�set��������ĳ�����ǽ��ռ����ƵĿ�
	CMyEdit m_m2;  // ��Ȼ�����������һ���Ի��������жԻ���ԭ����ǽ���һ���Ի����໯��Ȼ���Ϊ�����һ������
	CMyEdit m_m3;  // Ȼ�����ʵ���ʱ������
	CMyEdit m_m4;
	afx_msg void OnButtonClick(UINT nID);
};
