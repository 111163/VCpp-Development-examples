
// 文件标准对话框Dlg.h : 头文件
//

#pragma once


// C文件标准对话框Dlg 对话框
class C文件标准对话框Dlg : public CDialogEx
{
// 构造
public:
	C文件标准对话框Dlg(CWnd* pParent = NULL);	// 标准构造函数

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
	CString m_strEdit;
	afx_msg void OnBnClickedButton1();
	CStatic m_ConSta;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CEdit m_ConEdit;
	CFont m_Font;
	afx_msg void OnBnClickedButton4();
	COLORREF m_Color;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButton5();
	CFindReplaceDialog* dlg;
	int nindex;					//存储查找字符串的起始位置
	int rindex;					//替换字符串的大小
	BOOL degree;				//判断是否为第一次替换的变量
	BOOL find;				//判断是否进行查找的变量
	afx_msg	long OnFindReplace(WPARAM wParam,LPARAM lParam);
	afx_msg void OnBnClickedButton6();
	CString str[6];			
	CFont font;				//字体
	int screenx,screeny;	//获取窗口每英寸像素数
	int printx,printy;		//获取打印机每英寸像素数
	double ratex,ratey;		//打印机与屏幕的像素比率
	void DrawText(CDC *pDC, BOOL isprinted);
	afx_msg void OnBnClickedButton7();
};
