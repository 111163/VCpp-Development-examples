
// 浮动窗口View.h : C浮动窗口View 类的接口
//

#pragma once


class C浮动窗口View : public CView
{
protected: // 仅从序列化创建
	C浮动窗口View();
	DECLARE_DYNCREATE(C浮动窗口View)

// 特性
public:
	C浮动窗口Doc* GetDocument() const;

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
	virtual ~C浮动窗口View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 浮动窗口View.cpp 中的调试版本
inline C浮动窗口Doc* C浮动窗口View::GetDocument() const
   { return reinterpret_cast<C浮动窗口Doc*>(m_pDocument); }
#endif

