
// ����ͼ����ƴ���View.h : C����ͼ����ƴ���View ��Ľӿ�
//

#pragma once

#include "resource.h"


class C����ͼ����ƴ���View : public CFormView
{
protected: // �������л�����
	C����ͼ����ƴ���View();
	DECLARE_DYNCREATE(C����ͼ����ƴ���View)

public:
	enum{ IDD = IDD_MY_FORM };

// ����
public:
	C����ͼ����ƴ���Doc* GetDocument() const;
	//CRect m_rect;
	CList<CRect,CRect&> m_listRect;
	

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~C����ͼ����ƴ���View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // ����ͼ����ƴ���View.cpp �еĵ��԰汾
inline C����ͼ����ƴ���Doc* C����ͼ����ƴ���View::GetDocument() const
   { return reinterpret_cast<C����ͼ����ƴ���Doc*>(m_pDocument); }
#endif

