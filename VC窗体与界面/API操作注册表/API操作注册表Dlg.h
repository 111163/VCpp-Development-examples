
// API操作注册表Dlg.h : 头文件
//

#pragma once


// CAPI操作注册表Dlg 对话框
class CAPI操作注册表Dlg : public CDialogEx
{
// 构造
public:
	CAPI操作注册表Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_API_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
