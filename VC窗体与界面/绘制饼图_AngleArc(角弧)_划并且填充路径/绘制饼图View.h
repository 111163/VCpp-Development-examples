
// ���Ʊ�ͼView.h : C���Ʊ�ͼView ��Ľӿ�
//

#pragma once


class C���Ʊ�ͼView : public CView
{
protected: // �������л�����
	C���Ʊ�ͼView();
	DECLARE_DYNCREATE(C���Ʊ�ͼView)

// ����
public:
	C���Ʊ�ͼDoc* GetDocument() const;
	CString m_centerX;
	CString m_centerY;
	CString m_radius;
	CString m_startAngle;
	CString m_sweepAngle;
	BOOL m_Draw;

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
	virtual ~C���Ʊ�ͼView();
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
	afx_msg void OnInput();
};

#ifndef _DEBUG  // ���Ʊ�ͼView.cpp �еĵ��԰汾
inline C���Ʊ�ͼDoc* C���Ʊ�ͼView::GetDocument() const
   { return reinterpret_cast<C���Ʊ�ͼDoc*>(m_pDocument); }
#endif

