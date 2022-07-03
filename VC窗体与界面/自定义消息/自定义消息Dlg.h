
// 自定义消息Dlg.h : 头文件
//

#pragma once
#define NEWMESSAGE WM_USER + 100

// C自定义消息Dlg 对话框
class C自定义消息Dlg : public CDialogEx
{
// 构造
public:
	C自定义消息Dlg(CWnd* pParent = NULL);	// 标准构造函数

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
	afx_msg LRESULT OnNewmessage(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
