
// 从数据库动态生成菜单Dlg.h : 头文件
//

#pragma once


// C从数据库动态生成菜单Dlg 对话框
class C从数据库动态生成菜单Dlg : public CDialogEx
{
// 构造
public:
	C从数据库动态生成菜单Dlg(CWnd* pParent = NULL);	// 标准构造函数

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
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	CMenu m_menu;
	void LoadMenuFromDatabase(void);
	void LoadSubMenu(CMenu* m_menu, CString str);
	BOOL IsHaveSubMenu(CString str);
};
