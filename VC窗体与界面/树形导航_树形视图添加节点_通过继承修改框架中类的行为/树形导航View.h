
// ���ε���View.h : C���ε���View ��Ľӿ�
//

#pragma once
#include "���ε���Doc.h"


class C���ε���View : public CTreeView
{
protected: // �������л�����
	C���ε���View();
	DECLARE_DYNCREATE(C���ε���View)

// ����
public:
	C���ε���Doc* GetDocument() const;
	CImageList ImgTree;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~C���ε���View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMClick(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult);
};

#ifndef _DEBUG  // ���ε���View.cpp �еĵ��԰汾
inline C���ε���Doc* C���ε���View::GetDocument() const
   { return reinterpret_cast<C���ε���Doc*>(m_pDocument); }
#endif

