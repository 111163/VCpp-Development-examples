
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once
#include "DockBarCtrl.h"
#include "LeftPanel.h"

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:
	CDockBarCtrl m_DockBar;
	CLeftPanel m_Panel;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnFloatwnd();
	afx_msg void OnUpdateFloatwnd(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()

};


