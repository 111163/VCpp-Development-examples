
// 单文档应用程序View.h : C单文档应用程序View 类的接口
//

#pragma once

#include "单文档应用程序Doc.h"
#include <afxhtml.h>


class C单文档应用程序View : public CView
{
protected: // 仅从序列化创建
	C单文档应用程序View();
	DECLARE_DYNCREATE(C单文档应用程序View)

// 特性
public:
	C单文档应用程序Doc* GetDocument() const;

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
	virtual ~C单文档应用程序View();
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
};

#ifndef _DEBUG  // 单文档应用程序View.cpp 中的调试版本
inline C单文档应用程序Doc* C单文档应用程序View::GetDocument() const
   { return reinterpret_cast<C单文档应用程序Doc*>(m_pDocument); }
#endif

