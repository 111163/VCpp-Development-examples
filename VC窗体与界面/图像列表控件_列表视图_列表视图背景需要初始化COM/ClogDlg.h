#pragma once


// ClogDlg �Ի���

class ClogDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ClogDlg)

public:
	ClogDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ClogDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CImageList m_ImageList;
	CListCtrl m_Icon;
	CEdit m_Edit;
	afx_msg void OnBnClickedButton1();
	int n;
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
};
