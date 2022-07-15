
// QQ登录式用户选择列表Dlg.h : 头文件
//

#pragma once


// CQQ登录式用户选择列表Dlg 对话框
class CQQ登录式用户选择列表Dlg : public CDialogEx
{
// 构造
public:
	CQQ登录式用户选择列表Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_QQ_DIALOG };

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
	CEdit m_ConPw; // 这里留做后续做验证器
	CButton m_ConLog;  // 这里可以加载一个图片，也可以后续自绘这个和下一个按钮
	CButton m_ConCel;
	CImageList m_ImageList;  // 图案列表和姓名等数据后期可以做成从数据库中读取
	CComboBoxEx m_ConUserNme; // 这里注意是Ex
	// 包括按钮或使用按钮处理验证信息(从数据库中读取比对)这些后面都可以加上
};
