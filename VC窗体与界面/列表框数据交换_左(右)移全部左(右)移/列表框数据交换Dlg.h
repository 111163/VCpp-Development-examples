
// 列表框数据交换Dlg.h : 头文件
//

#pragma once


// C列表框数据交换Dlg 对话框
class C列表框数据交换Dlg : public CDialogEx
{
// 构造
public:
	C列表框数据交换Dlg(CWnd* pParent = NULL);	// 标准构造函数

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
	CButton m_ConBr;
	CButton m_ConBl;
	CButton m_ConBla;
	CButton m_ConBra;
	CListBox m_ConLl;
	CListBox m_ConLr;
	afx_msg void OnBnClickedRight();
	afx_msg void OnBnClickedLeft();
	afx_msg void OnBnClickedRightall();
	afx_msg void OnBnClickedLeftall();
};
