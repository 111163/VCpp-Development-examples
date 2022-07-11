
// 对话框调用文档视图(打印)View.h : C对话框调用文档视图打印View 类的接口
//

#pragma once


class C对话框调用文档视图打印View : public CView
{
protected: // 仅从序列化创建
	C对话框调用文档视图打印View();
	DECLARE_DYNCREATE(C对话框调用文档视图打印View)

// 特性
public:
	C对话框调用文档视图打印Doc* GetDocument() const;

	CFont font; // 字体
	int screenx, screeny; // 获取窗口每英寸像素数
	int printx, printy; // 获取打印机每英寸像素数
	double ratex, ratey; // 打印机与屏幕的像素比率

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
	virtual ~C对话框调用文档视图打印View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
};

#ifndef _DEBUG  // 对话框调用文档视图(打印)View.cpp 中的调试版本
inline C对话框调用文档视图打印Doc* C对话框调用文档视图打印View::GetDocument() const
   { return reinterpret_cast<C对话框调用文档视图打印Doc*>(m_pDocument); }
#endif

