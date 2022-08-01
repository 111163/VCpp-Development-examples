
// GDIplus显示GIF动图View.h : CGDIplus显示GIF动图View 类的接口
//

#pragma once
#include <GdiPlus.h>
using namespace Gdiplus;
#pragma comment (lib, "gdiplus.lib")


class CGDIplus显示GIF动图View : public CView
{
protected: // 仅从序列化创建
	CGDIplus显示GIF动图View();
	DECLARE_DYNCREATE(CGDIplus显示GIF动图View)
	GdiplusStartupInput m_Gdiplus;	//定义GDI+初始化变量
	ULONG_PTR m_pGdiToken;			//定义GID+标识
	Bitmap *m_pBmp;			//定义位图对象，派生于Image类
	UINT m_Count;			//记录维数
	UINT m_FrameCount;		//帧数
	PropertyItem* pItem ;	//定义图像属性
	int fcount;				//定义一个临时整型变量
	UINT delay;				//第一帧的延时
// 特性
public:
	CGDIplus显示GIF动图Doc* GetDocument() const;

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
	virtual ~CGDIplus显示GIF动图View();
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
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // GDIplus显示GIF动图View.cpp 中的调试版本
inline CGDIplus显示GIF动图Doc* CGDIplus显示GIF动图View::GetDocument() const
   { return reinterpret_cast<CGDIplus显示GIF动图Doc*>(m_pDocument); }
#endif

