#pragma once


// dlgModal 对话框

class dlgModal : public CDialogEx
{
	DECLARE_DYNAMIC(dlgModal)

public:
	dlgModal(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~dlgModal();

// 对话框数据
	enum { IDD = IDD_MODAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strEdit;
	virtual BOOL OnInitDialog();
	CEdit m_ConEdit;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
