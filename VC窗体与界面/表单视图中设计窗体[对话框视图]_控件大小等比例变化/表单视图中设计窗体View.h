
// 表单视图中设计窗体View.h : C表单视图中设计窗体View 类的接口
//

#pragma once

#include "resource.h"


class C表单视图中设计窗体View : public CFormView
{
protected: // 仅从序列化创建
	C表单视图中设计窗体View();
	DECLARE_DYNCREATE(C表单视图中设计窗体View)

public:
	enum{ IDD = IDD_MY_FORM };

// 特性
public:
	C表单视图中设计窗体Doc* GetDocument() const;
	//CRect m_rect;
	CList<CRect,CRect&> m_listRect;
	

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~C表单视图中设计窗体View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // 表单视图中设计窗体View.cpp 中的调试版本
inline C表单视图中设计窗体Doc* C表单视图中设计窗体View::GetDocument() const
   { return reinterpret_cast<C表单视图中设计窗体Doc*>(m_pDocument); }
#endif

