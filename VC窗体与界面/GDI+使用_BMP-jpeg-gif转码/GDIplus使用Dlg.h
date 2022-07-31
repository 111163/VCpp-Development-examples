
// GDIplus使用Dlg.h : 头文件
//

#pragma once

#include <GdiPlus.h>
using namespace Gdiplus;
#pragma comment (lib, "Gdiplus.lib")

// CGDIplus使用Dlg 对话框
class CGDIplus使用Dlg : public CDialogEx
{
// 构造
public:
	CGDIplus使用Dlg(CWnd* pParent = NULL);	// 标准构造函数

	GdiplusStartupInput m_Gdiplus;          //定义初始变量
	ULONG_PTR m_pGdiToken;                     //定义GDI符号
	CString m_FileName;                          //记录文件名称


// 对话框数据
	enum { IDD = IDD_GDIPLUS_DIALOG };

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
	virtual void OnCancel();
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedQuit();
	afx_msg void OnBnClickedConvert();
	CEdit m_ImageName;
	int m_nCheck;
	afx_msg void OnBnClickedBmp();
	afx_msg void OnBnClickedJpeg();
	afx_msg void OnBnClickedGif();
};
