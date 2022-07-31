
// 显示JPEG图像View.h : C显示JPEG图像View 类的接口
//

#pragma once


class C显示JPEG图像View : public CView
{
protected: // 仅从序列化创建
	C显示JPEG图像View();
	DECLARE_DYNCREATE(C显示JPEG图像View)

// 特性
public:
	C显示JPEG图像Doc* GetDocument() const;
	IStream *m_pStream;                //定义流对象
	IPicture *m_pPicture;              //定义接口对象
	OLE_XSIZE_HIMETRIC m_JPGWidth;     //图像宽度
	OLE_YSIZE_HIMETRIC m_JPGHeight;    //图像高度
	HGLOBAL hMem;                      //堆句柄
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
	virtual ~C显示JPEG图像View();
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

#ifndef _DEBUG  // 显示JPEG图像View.cpp 中的调试版本
inline C显示JPEG图像Doc* C显示JPEG图像View::GetDocument() const
   { return reinterpret_cast<C显示JPEG图像Doc*>(m_pDocument); }
#endif

