#pragma once


// BeginIII 对话框

class BeginIII : public CDialogEx
{
	DECLARE_DYNAMIC(BeginIII)

public:
	BeginIII(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~BeginIII();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
