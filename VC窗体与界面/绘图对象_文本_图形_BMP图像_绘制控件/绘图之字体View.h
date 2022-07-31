
// 绘图之字体View.h : C绘图之字体View 类的接口
//

#pragma once


class C绘图之字体View : public CView
{
protected: // 仅从序列化创建
	C绘图之字体View();
	DECLARE_DYNCREATE(C绘图之字体View)
	/*HANDLE m_hBmp;*/
	char* m_pBmpData;

// 特性
public:
	C绘图之字体Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C绘图之字体View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	void OutputStream(char *pStream);
};

#ifndef _DEBUG  // 绘图之字体View.cpp 中的调试版本
inline C绘图之字体Doc* C绘图之字体View::GetDocument() const
   { return reinterpret_cast<C绘图之字体Doc*>(m_pDocument); }
#endif

