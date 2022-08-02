#pragma once

#ifndef _AFXEXT
#define IDD_DIALOG1 9000
#else
#include "resource.h"
#endif

#ifdef calculations_EXPORTS
#define CALCULATIONS_API __declspec(dllexport)
#else
#define CALCULATIONS_API __declspec(dllimport)
#endif

// CMyDlg 对话框

class CALCULATIONS_API CMyDlg : public CDialogEx    //AFX_EXT_CLASS宏代替上面的宏判断(宏判断交给了编译器来处理)
{
	DECLARE_DYNAMIC(CMyDlg)

public:
	CMyDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyDlg();

	// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
