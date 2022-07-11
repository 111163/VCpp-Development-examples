#pragma once
#include "自定义打印预览工具栏View.h"


// CPreView 视图
class C自定义打印预览工具栏View;
class CPreView : public CPreviewView
{
	DECLARE_DYNCREATE(CPreView)

protected:
	CPreView();           // 动态创建所使用的受保护的构造函数
	virtual ~CPreView();

public:
	C自定义打印预览工具栏View* m_pPrintView;
	C自定义打印预览工具栏View* m_pOrigView;
	CPrintPreviewState* m_pPreviewState;
	CButton m_print,m_up,m_down,m_exit;
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPreviewClose();
};


