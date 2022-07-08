
// 图标导航View.h : C图标导航View 类的接口
//

#pragma once
#include "图标导航Doc.h"


class C图标导航View : public CListView
{
protected: // 仅从序列化创建
	C图标导航View();
	DECLARE_DYNCREATE(C图标导航View)

// 特性
public:
	C图标导航Doc* GetDocument() const;
	CImageList m_ImageList;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~C图标导航View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMClick(NMHDR *pNMHDR, LRESULT *pResult);
};

#ifndef _DEBUG  // 图标导航View.cpp 中的调试版本
inline C图标导航Doc* C图标导航View::GetDocument() const
   { return reinterpret_cast<C图标导航Doc*>(m_pDocument); }
#endif

