
// �Զ����ӡԤ��������View.h : C�Զ����ӡԤ��������View ��Ľӿ�
//

#pragma once
#include "�Զ����ӡԤ��������Doc.h"


class C�Զ����ӡԤ��������View : public CView
{
protected: // �������л�����
	C�Զ����ӡԤ��������View();
	DECLARE_DYNCREATE(C�Զ����ӡԤ��������View)

// ����
public:
	C�Զ����ӡԤ��������Doc* GetDocument() const;

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
	virtual ~C�Զ����ӡԤ��������View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	afx_msg	void OnFilePrintPreview();
// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // �Զ����ӡԤ��������View.cpp �еĵ��԰汾
inline C�Զ����ӡԤ��������Doc* C�Զ����ӡԤ��������View::GetDocument() const
   { return reinterpret_cast<C�Զ����ӡԤ��������Doc*>(m_pDocument); }
#endif

