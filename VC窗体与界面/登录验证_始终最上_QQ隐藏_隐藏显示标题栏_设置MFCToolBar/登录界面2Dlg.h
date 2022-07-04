
// 登录界面2Dlg.h : 头文件
//

#pragma once
#include "LOGIN.h"


// C登录界面2Dlg 对话框
class C登录界面2Dlg : public CDialogEx
{
// 构造
public:
	C登录界面2Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY2_DIALOG };

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

public:
	LOGIN dlgLog;
	DECLARE_MESSAGE_MAP()
	CButton m_conSetTop;
	afx_msg void OnBnClickedSet();
	int m_topFlg;
	BOOL m_titleFlg;
	afx_msg void OnBnClickedTitle();
	CButton m_conTitle;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CMFCToolBar m_toolB;
	afx_msg void OnBnClickedBUTTON32771();
//	virtual HRESULT accDoDefaultAction(VARIANT varChild);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
