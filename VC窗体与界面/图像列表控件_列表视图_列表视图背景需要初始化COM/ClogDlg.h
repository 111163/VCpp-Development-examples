#pragma once


// ClogDlg 对话框

class ClogDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ClogDlg)

public:
	ClogDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ClogDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
