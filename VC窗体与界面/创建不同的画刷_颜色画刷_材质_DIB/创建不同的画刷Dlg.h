
// ������ͬ�Ļ�ˢDlg.h : ͷ�ļ�
//

#pragma once


// C������ͬ�Ļ�ˢDlg �Ի���
class C������ͬ�Ļ�ˢDlg : public CDialogEx
{
// ����
public:
	C������ͬ�Ļ�ˢDlg(CWnd* pParent = NULL);	// ��׼���캯��
	long* m_pbmpheader;
	long* m_pbmpdata;
	BITMAPINFO *m_pbmpinfo,m_bmp;

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
};
