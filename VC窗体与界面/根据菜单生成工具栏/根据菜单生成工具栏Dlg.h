
// 根据菜单生成工具栏Dlg.h : 头文件
//

#pragma once


// C根据菜单生成工具栏Dlg 对话框
class C根据菜单生成工具栏Dlg : public CDialogEx
{
// 构造
public:
	C根据菜单生成工具栏Dlg(CWnd* pParent = NULL);	// 标准构造函数
	CMenu m_Menu;
	CToolBarCtrl m_toolbar;
	CImageList m_imagelist;


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
	afx_msg void OnCom(UINT nID);
	DECLARE_MESSAGE_MAP()
};
