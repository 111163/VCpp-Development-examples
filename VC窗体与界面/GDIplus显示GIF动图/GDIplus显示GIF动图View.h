
// GDIplus��ʾGIF��ͼView.h : CGDIplus��ʾGIF��ͼView ��Ľӿ�
//

#pragma once
#include <GdiPlus.h>
using namespace Gdiplus;
#pragma comment (lib, "gdiplus.lib")


class CGDIplus��ʾGIF��ͼView : public CView
{
protected: // �������л�����
	CGDIplus��ʾGIF��ͼView();
	DECLARE_DYNCREATE(CGDIplus��ʾGIF��ͼView)
	GdiplusStartupInput m_Gdiplus;	//����GDI+��ʼ������
	ULONG_PTR m_pGdiToken;			//����GID+��ʶ
	Bitmap *m_pBmp;			//����λͼ����������Image��
	UINT m_Count;			//��¼ά��
	UINT m_FrameCount;		//֡��
	PropertyItem* pItem ;	//����ͼ������
	int fcount;				//����һ����ʱ���ͱ���
	UINT delay;				//��һ֡����ʱ
// ����
public:
	CGDIplus��ʾGIF��ͼDoc* GetDocument() const;

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
	virtual ~CGDIplus��ʾGIF��ͼView();
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
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // GDIplus��ʾGIF��ͼView.cpp �еĵ��԰汾
inline CGDIplus��ʾGIF��ͼDoc* CGDIplus��ʾGIF��ͼView::GetDocument() const
   { return reinterpret_cast<CGDIplus��ʾGIF��ͼDoc*>(m_pDocument); }
#endif

