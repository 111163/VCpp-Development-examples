
// ģ̬���ģ̬Dlg.h : ͷ�ļ�
//

#pragma once


// Cģ̬���ģ̬Dlg �Ի���
class Cģ̬���ģ̬Dlg : public CDialogEx
{
// ����
public:
	Cģ̬���ģ̬Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	// ��ģ̬�Ի��򵽵��ǵ���˵���Ǹ���ť���ص�
	afx_msg LRESULT OnClickEdOk(WPARAM wParam, LPARAM lParam);
};
