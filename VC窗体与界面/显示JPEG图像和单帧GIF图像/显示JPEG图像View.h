
// ��ʾJPEGͼ��View.h : C��ʾJPEGͼ��View ��Ľӿ�
//

#pragma once


class C��ʾJPEGͼ��View : public CView
{
protected: // �������л�����
	C��ʾJPEGͼ��View();
	DECLARE_DYNCREATE(C��ʾJPEGͼ��View)

// ����
public:
	C��ʾJPEGͼ��Doc* GetDocument() const;
	IStream *m_pStream;                //����������
	IPicture *m_pPicture;              //����ӿڶ���
	OLE_XSIZE_HIMETRIC m_JPGWidth;     //ͼ����
	OLE_YSIZE_HIMETRIC m_JPGHeight;    //ͼ��߶�
	HGLOBAL hMem;                      //�Ѿ��
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
	virtual ~C��ʾJPEGͼ��View();
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

#ifndef _DEBUG  // ��ʾJPEGͼ��View.cpp �еĵ��԰汾
inline C��ʾJPEGͼ��Doc* C��ʾJPEGͼ��View::GetDocument() const
   { return reinterpret_cast<C��ʾJPEGͼ��Doc*>(m_pDocument); }
#endif

