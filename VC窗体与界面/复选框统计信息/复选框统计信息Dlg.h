
// 复选框统计信息Dlg.h : 头文件
//

#pragma once


// C复选框统计信息Dlg 对话框
class C复选框统计信息Dlg : public CDialogEx
{
// 构造
public:
	C复选框统计信息Dlg(CWnd* pParent = NULL);	// 标准构造函数

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
	CButton m_ConChi;
	CButton m_ConEng;
	CButton m_ConF;
	CButton m_ConG;
	CButton m_ConHua;
	CButton m_ConJnp;
	CButton m_ConMat;
	CButton m_ConPhy;
	afx_msg void OnBnClickedButton1();
};
