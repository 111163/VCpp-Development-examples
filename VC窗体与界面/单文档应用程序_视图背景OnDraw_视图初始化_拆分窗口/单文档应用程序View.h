
// ���ĵ�Ӧ�ó���View.h : C���ĵ�Ӧ�ó���View ��Ľӿ�
//

#pragma once

#include "���ĵ�Ӧ�ó���Doc.h"
#include <afxhtml.h>


class C���ĵ�Ӧ�ó���View : public CView
{
protected: // �������л�����
	C���ĵ�Ӧ�ó���View();
	DECLARE_DYNCREATE(C���ĵ�Ӧ�ó���View)

// ����
public:
	C���ĵ�Ӧ�ó���Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C���ĵ�Ӧ�ó���View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ���ĵ�Ӧ�ó���View.cpp �еĵ��԰汾
inline C���ĵ�Ӧ�ó���Doc* C���ĵ�Ӧ�ó���View::GetDocument() const
   { return reinterpret_cast<C���ĵ�Ӧ�ó���Doc*>(m_pDocument); }
#endif

