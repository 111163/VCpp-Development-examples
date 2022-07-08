
// 星座物语2View.h : C星座物语2View 类的接口
//

#pragma once


class C星座物语2View : public CView
{
protected: // 仅从序列化创建
	C星座物语2View();
	DECLARE_DYNCREATE(C星座物语2View)

// 特性
public:
	C星座物语2Doc* GetDocument() const;
	int m_Index;

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
	virtual ~C星座物语2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnButtonshow();
};

#ifndef _DEBUG  // 星座物语2View.cpp 中的调试版本
inline C星座物语2Doc* C星座物语2View::GetDocument() const
   { return reinterpret_cast<C星座物语2Doc*>(m_pDocument); }
#endif

