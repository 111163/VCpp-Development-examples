
// ͼ�굼��View.h : Cͼ�굼��View ��Ľӿ�
//

#pragma once
#include "ͼ�굼��Doc.h"


class Cͼ�굼��View : public CListView
{
protected: // �������л�����
	Cͼ�굼��View();
	DECLARE_DYNCREATE(Cͼ�굼��View)

// ����
public:
	Cͼ�굼��Doc* GetDocument() const;
	CImageList m_ImageList;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~Cͼ�굼��View();
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
};

#ifndef _DEBUG  // ͼ�굼��View.cpp �еĵ��԰汾
inline Cͼ�굼��Doc* Cͼ�굼��View::GetDocument() const
   { return reinterpret_cast<Cͼ�굼��Doc*>(m_pDocument); }
#endif

