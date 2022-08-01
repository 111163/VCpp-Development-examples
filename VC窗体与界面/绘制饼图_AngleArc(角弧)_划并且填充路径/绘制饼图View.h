
// 绘制饼图View.h : C绘制饼图View 类的接口
//

#pragma once


class C绘制饼图View : public CView
{
protected: // 仅从序列化创建
	C绘制饼图View();
	DECLARE_DYNCREATE(C绘制饼图View)

// 特性
public:
	C绘制饼图Doc* GetDocument() const;
	CString m_centerX;
	CString m_centerY;
	CString m_radius;
	CString m_startAngle;
	CString m_sweepAngle;
	BOOL m_Draw;

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
	virtual ~C绘制饼图View();
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
	afx_msg void OnInput();
};

#ifndef _DEBUG  // 绘制饼图View.cpp 中的调试版本
inline C绘制饼图Doc* C绘制饼图View::GetDocument() const
   { return reinterpret_cast<C绘制饼图Doc*>(m_pDocument); }
#endif

