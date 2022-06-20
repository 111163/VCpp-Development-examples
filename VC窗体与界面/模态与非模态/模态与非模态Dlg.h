
// 模态与非模态Dlg.h : 头文件
//

#pragma once


// C模态与非模态Dlg 对话框
class C模态与非模态Dlg : public CDialogEx
{
// 构造
public:
	C模态与非模态Dlg(CWnd* pParent = NULL);	// 标准构造函数

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
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	// 非模态对话框到底是点击了点击那个按钮返回的
	afx_msg LRESULT OnClickEdOk(WPARAM wParam, LPARAM lParam);
};
