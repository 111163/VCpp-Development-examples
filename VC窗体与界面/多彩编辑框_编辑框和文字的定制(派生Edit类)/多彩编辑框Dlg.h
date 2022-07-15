
// 多彩编辑框Dlg.h : 头文件
//

#pragma once
#include "ColorEdit.h"


// C多彩编辑框Dlg 对话框
class C多彩编辑框Dlg : public CDialogEx
{
// 构造
public:
	C多彩编辑框Dlg(CWnd* pParent = NULL);	// 标准构造函数

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
	CColorEdit m_Edit1;
	CColorEdit m_Edit2;
	CColorEdit m_Edit3;
};
