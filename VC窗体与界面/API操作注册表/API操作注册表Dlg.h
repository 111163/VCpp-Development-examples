
// API����ע���Dlg.h : ͷ�ļ�
//

#pragma once


// CAPI����ע���Dlg �Ի���
class CAPI����ע���Dlg : public CDialogEx
{
// ����
public:
	CAPI����ע���Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_API_DIALOG };

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
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedRead();
	CEdit m_KeyName;
	CEdit m_ItemValue;
	CEdit m_ItemName;
};
