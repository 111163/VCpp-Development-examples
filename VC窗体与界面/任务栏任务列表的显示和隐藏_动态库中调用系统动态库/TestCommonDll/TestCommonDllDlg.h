
// TestCommonDllDlg.h : ͷ�ļ�
//

#pragma once


// CTestCommonDllDlg �Ի���
class CTestCommonDllDlg : public CDialogEx
{
// ����
public:
	CTestCommonDllDlg(CWnd* pParent = NULL);	// ��׼���캯��
	HWND nHwnd;

// �Ի�������
	enum { IDD = IDD_TESTCOMMONDLL_DIALOG };

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
	afx_msg void OnBnClickedButton1();
};
