
// 金额转换Dlg.h : 头文件
//

#pragma once
#include "MoneyEdit.h"


// C金额转换Dlg 对话框
class C金额转换Dlg : public CDialogEx
{
// 构造
public:
	C金额转换Dlg(CWnd* pParent = NULL);	// 标准构造函数
	void ChangeMoney(CString str,int num);
	CString Capitalization(CString str);

// 对话框数据
	enum { IDD = IDD_MY_DIALOG };

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
	afx_msg void OnBnClickedButton1();
	CMoneyEdit m_ConInp;
//	CEdit m_StrEdit2;
	CString m_StrEdit2;
};
