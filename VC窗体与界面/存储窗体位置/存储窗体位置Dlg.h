
// 存储窗体位置Dlg.h : 头文件
//

#pragma once

typedef struct _Configinfo
{
	int height;
	int width;
	int left;
	int top;
}ConfigInfo;

// C存储窗体位置Dlg 对话框
class C存储窗体位置Dlg : public CDialogEx
{
// 构造
public:
	C存储窗体位置Dlg(CWnd* pParent = NULL);	// 标准构造函数

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
	CEdit m_ConCaption;
protected:
	CString m_strConfigPath;
public:
	afx_msg void OnDestroy();
};
