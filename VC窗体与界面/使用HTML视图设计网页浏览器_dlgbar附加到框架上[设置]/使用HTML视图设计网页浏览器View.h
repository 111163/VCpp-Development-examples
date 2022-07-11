
// 使用HTML视图设计网页浏览器View.h : C使用HTML视图设计网页浏览器View 类的接口
//

#pragma once


class C使用HTML视图设计网页浏览器View : public CHtmlView
{
protected: // 仅从序列化创建
	C使用HTML视图设计网页浏览器View();
	DECLARE_DYNCREATE(C使用HTML视图设计网页浏览器View)

// 特性
public:
	C使用HTML视图设计网页浏览器Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	CString m_StrPath;
	virtual ~C使用HTML视图设计网页浏览器View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtback();
	afx_msg void OnBnClickedBtforward();
	afx_msg void OnBnClickedBtstop();
	afx_msg void OnBnClickedBtrefresh();
	afx_msg void OnBnClickedBtgoto();
	afx_msg void OnEnChangeEdaddress();
};

#ifndef _DEBUG  // 使用HTML视图设计网页浏览器View.cpp 中的调试版本
inline C使用HTML视图设计网页浏览器Doc* C使用HTML视图设计网页浏览器View::GetDocument() const
   { return reinterpret_cast<C使用HTML视图设计网页浏览器Doc*>(m_pDocument); }
#endif

