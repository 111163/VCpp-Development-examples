
// ʵ���ʾ���Dlg.h : ͷ�ļ�
//

#pragma once


// Cʵ���ʾ���Dlg �Ի���
class Cʵ���ʾ���Dlg : public CDialogEx
{
// ����
public:
	Cʵ���ʾ���Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	afx_msg void OnBnClickedEx();
	afx_msg void OnBnClickedInput();
};
