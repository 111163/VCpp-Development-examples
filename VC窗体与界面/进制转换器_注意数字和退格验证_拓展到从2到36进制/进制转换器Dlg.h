
// 进制转换器Dlg.h : 头文件
//

#pragma once
#include "MyEdit.h"


// C进制转换器Dlg 对话框
class C进制转换器Dlg : public CDialogEx
{
// 构造
public:
	C进制转换器Dlg(CWnd* pParent = NULL);	// 标准构造函数

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
	CMyEdit m_m1;  //这里我们对Edit做了验证器，并且从set函数设置某个框是接收几进制的框
	CMyEdit m_m2;  // 当然如果我们想在一个对话框中另有对话框，原理就是将另一个对话框类化，然后成为本类的一个子类
	CMyEdit m_m3;  // 然后在适当的时机操作
	CMyEdit m_m4;
	afx_msg void OnButtonClick(UINT nID);
};
