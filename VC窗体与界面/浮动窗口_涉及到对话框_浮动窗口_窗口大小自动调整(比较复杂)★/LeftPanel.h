#pragma once
#include "Resource.h"

// CLeftPanel 对话框

class CLeftPanel : public CDialog
{
	DECLARE_DYNAMIC(CLeftPanel)

public:
	CLeftPanel(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLeftPanel();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
