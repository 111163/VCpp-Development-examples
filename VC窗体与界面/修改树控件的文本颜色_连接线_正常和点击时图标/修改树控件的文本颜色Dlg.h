
// 修改树控件的文本颜色Dlg.h : 头文件
//

#pragma once


// C修改树控件的文本颜色Dlg 对话框
class C修改树控件的文本颜色Dlg : public CDialogEx
{
// 构造
public:
	C修改树控件的文本颜色Dlg(CWnd* pParent = NULL);	// 标准构造函数
	CTreeCtrl m_TreeCtrl;
	CImageList m_ImageList;

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
};
