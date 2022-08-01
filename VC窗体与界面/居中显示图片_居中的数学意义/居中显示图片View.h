
// 居中显示图片View.h : C居中显示图片View 类的接口
//

#pragma once


class C居中显示图片View : public CView
{
protected: // 仅从序列化创建
	C居中显示图片View();
	DECLARE_DYNCREATE(C居中显示图片View)

// 特性
public:
	C居中显示图片Doc* GetDocument() const;
	CSize GetCenterSize(int iDlgWidth,int iDlgHeight,int iBmpWidth,int iBmpHeight);
	CPoint m_ptPitcureVec;

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
	virtual ~C居中显示图片View();
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
	afx_msg void OnSetcenter();
};

#ifndef _DEBUG  // 居中显示图片View.cpp 中的调试版本
inline C居中显示图片Doc* C居中显示图片View::GetDocument() const
   { return reinterpret_cast<C居中显示图片Doc*>(m_pDocument); }
#endif

