
// 编辑框输入时列表框也显示Dlg.h : 头文件
//

#pragma once


// C编辑框输入时列表框也显示Dlg 对话框
class C编辑框输入时列表框也显示Dlg : public CDialogEx
{
// 构造
public:
	C编辑框输入时列表框也显示Dlg(CWnd* pParent = NULL);	// 标准构造函数
	_ConnectionPtr m_pConnection; // 连接对象指针
	_RecordsetPtr  m_pRecordset;  // 命令对象指针
	CString xm,xb,csrq,gzdw,yddh,gddh ;
	bool IsShowing;

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
	CListCtrl m_ConList;
	CEdit m_ConEdit;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnEnChangeEdit1();
	void AutoPostion();
	void SetDataBase(CString sql);
	afx_msg void OnDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
};
