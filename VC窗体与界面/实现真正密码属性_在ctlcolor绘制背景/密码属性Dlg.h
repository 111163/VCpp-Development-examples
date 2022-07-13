
// 密码属性Dlg.h : 头文件
//

#pragma once
#include "SaftEdit.h"


// C密码属性Dlg 对话框
class C密码属性Dlg : public CDialogEx
{
// 构造
public:
	C密码属性Dlg(CWnd* pParent = NULL);	// 标准构造函数

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
	CEdit m_ConUserNm;
	CSaftEdit m_ConPd;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};


/*
Edit控件是Windows的一个常用标准控件，
当把其Password属性设为True时,就会将输入的内容屏蔽为星号，从而达到保护的目的。虽然我们看来都是星号，
但程序中的Edit控件实际仍是用户输入的密码，应用程序可以获取该控件中的密码，
其他应用程序也可以通过某种技术手段来非法获取Edit控件中的内容。其中最简单的一个方法就是从外部程序向该
编辑控件发出一个取Edit控件内容的消息WM_GETTEXT或EM_GETLINE就能够轻松得到想要的内容。黑客程序正是利用Edit控件
的这个特性，当发现当前探测的窗口是Edit控件并且具有ES_PASSWORD属性时，则通过SendMessage向此窗口发送WM_GETTEXT或
EM_GETLINE消息，这样Edit框中的内容就一目了然了。 
*/

