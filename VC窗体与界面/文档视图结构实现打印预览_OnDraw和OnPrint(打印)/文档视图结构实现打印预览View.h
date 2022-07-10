
// 文档视图结构实现打印预览View.h : C文档视图结构实现打印预览View 类的接口
//

#pragma once


class C文档视图结构实现打印预览View : public CView
{
protected: // 仅从序列化创建
	C文档视图结构实现打印预览View();
	DECLARE_DYNCREATE(C文档视图结构实现打印预览View)

// 特性
public:
	C文档视图结构实现打印预览Doc* GetDocument() const;
	int screenx,screeny; //获取窗口每英寸像素数
	int printx,printy; //获取打印机每英寸像素数
	double ratex,ratey; //打印机与屏幕的像素比率

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
	virtual ~C文档视图结构实现打印预览View();
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

#ifndef _DEBUG  // 文档视图结构实现打印预览View.cpp 中的调试版本
inline C文档视图结构实现打印预览Doc* C文档视图结构实现打印预览View::GetDocument() const
   { return reinterpret_cast<C文档视图结构实现打印预览Doc*>(m_pDocument); }
#endif

