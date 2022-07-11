
// 自定义打印预览工具栏View.h : C自定义打印预览工具栏View 类的接口
//

#pragma once
#include "自定义打印预览工具栏Doc.h"


class C自定义打印预览工具栏View : public CView
{
protected: // 仅从序列化创建
	C自定义打印预览工具栏View();
	DECLARE_DYNCREATE(C自定义打印预览工具栏View)

// 特性
public:
	C自定义打印预览工具栏Doc* GetDocument() const;

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
	virtual ~C自定义打印预览工具栏View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	afx_msg	void OnFilePrintPreview();
// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 自定义打印预览工具栏View.cpp 中的调试版本
inline C自定义打印预览工具栏Doc* C自定义打印预览工具栏View::GetDocument() const
   { return reinterpret_cast<C自定义打印预览工具栏Doc*>(m_pDocument); }
#endif

