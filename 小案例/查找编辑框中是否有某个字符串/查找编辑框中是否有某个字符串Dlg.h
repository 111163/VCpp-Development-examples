
// 查找编辑框中是否有某个字符串Dlg.h : 头文件
//

#pragma once


// C查找编辑框中是否有某个字符串Dlg 对话框
class C查找编辑框中是否有某个字符串Dlg : public CDialogEx
{
// 构造
public:
	C查找编辑框中是否有某个字符串Dlg(CWnd* pParent = NULL);	// 标准构造函数

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
	CString m_strInput;
	CString m_strFind;
	CStringArray strArray;
	afx_msg void OnBnClickedButton1();
};
