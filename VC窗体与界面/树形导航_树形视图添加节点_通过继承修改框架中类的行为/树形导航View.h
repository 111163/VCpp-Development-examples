
// 树形导航View.h : C树形导航View 类的接口
//

#pragma once
#include "树形导航Doc.h"


class C树形导航View : public CTreeView
{
protected: // 仅从序列化创建
	C树形导航View();
	DECLARE_DYNCREATE(C树形导航View)

// 特性
public:
	C树形导航Doc* GetDocument() const;
	CImageList ImgTree;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~C树形导航View();
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
	afx_msg void OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult);
};

#ifndef _DEBUG  // 树形导航View.cpp 中的调试版本
inline C树形导航Doc* C树形导航View::GetDocument() const
   { return reinterpret_cast<C树形导航Doc*>(m_pDocument); }
#endif

