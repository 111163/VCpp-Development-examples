
// MainFrm.h : CMainFrame 类的接口
//

#pragma once
#include "DockBarCtrl.h"
#include "LeftPanel.h"

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:
	CDockBarCtrl m_DockBar;
	CLeftPanel m_Panel;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnFloatwnd();
	afx_msg void OnUpdateFloatwnd(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()

};


