
// 根据ini文件动态生成菜单Dlg.h : 头文件
//

#pragma once


// C根据ini文件动态生成菜单Dlg 对话框
class C根据ini文件动态生成菜单Dlg : public CDialogEx
{
// 构造
public:
	C根据ini文件动态生成菜单Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_INI_DIALOG };

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
	CMenu m_cMenu;
	void CreateMenuFromFile(void);
	void LoadSubMenu(CMenu* m_menu,CString str);
	BOOL IsHaveSubMenu(CString strSubMenu);
};
