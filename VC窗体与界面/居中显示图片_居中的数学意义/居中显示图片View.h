
// ������ʾͼƬView.h : C������ʾͼƬView ��Ľӿ�
//

#pragma once


class C������ʾͼƬView : public CView
{
protected: // �������л�����
	C������ʾͼƬView();
	DECLARE_DYNCREATE(C������ʾͼƬView)

// ����
public:
	C������ʾͼƬDoc* GetDocument() const;
	CSize GetCenterSize(int iDlgWidth,int iDlgHeight,int iBmpWidth,int iBmpHeight);
	CPoint m_ptPitcureVec;

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
	virtual ~C������ʾͼƬView();
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
	afx_msg void OnSetcenter();
};

#ifndef _DEBUG  // ������ʾͼƬView.cpp �еĵ��԰汾
inline C������ʾͼƬDoc* C������ʾͼƬView::GetDocument() const
   { return reinterpret_cast<C������ʾͼƬDoc*>(m_pDocument); }
#endif

