#pragma once


// dlgNoModal 对话框

class dlgNoModal : public CDialogEx
{
	DECLARE_DYNAMIC(dlgNoModal)

public:
	dlgNoModal(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~dlgNoModal();

// 对话框数据
	enum { IDD = IDD_NOMODAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strEdit;
	CEdit m_ConEdit;
	virtual BOOL OnInitDialog();
	virtual void PostNcDestroy();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual void OnOK();
	virtual void OnCancel();
};
