#pragma once
#include "�Զ����ӡԤ��������View.h"


// CPreView ��ͼ
class C�Զ����ӡԤ��������View;
class CPreView : public CPreviewView
{
	DECLARE_DYNCREATE(CPreView)

protected:
	CPreView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CPreView();

public:
	C�Զ����ӡԤ��������View* m_pPrintView;
	C�Զ����ӡԤ��������View* m_pOrigView;
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


