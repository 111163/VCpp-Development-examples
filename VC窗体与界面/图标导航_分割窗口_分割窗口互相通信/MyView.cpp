// MyView.cpp : 实现文件
//

#include "stdafx.h"
#include "图标导航.h"
#include "MyView.h"


// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

CMyView::CMyView()
{
	m_Index = 0;
}

CMyView::~CMyView()
{
}

BEGIN_MESSAGE_MAP(CMyView, CView)
END_MESSAGE_MAP()


// CMyView 绘图

void CMyView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	
	CDC memDC;										//定义一个设备上下文
	memDC.CreateCompatibleDC(pDC);					//创建兼容的设备上下文
	CBitmap bmp;										//定义位图对象
	bmp.LoadBitmap(IDB_BKBMP+m_Index);						//加载位图
	memDC.SelectObject(&bmp);							//选中位图对象
	BITMAP BitInfo;									//定义位图结构
	bmp.GetBitmap(&BitInfo);								//获取位图信息
	int x = BitInfo.bmWidth;								//获取位图宽度
	int y = BitInfo.bmHeight;								//获取位图高度
	pDC->BitBlt(0, 0, x, y, &memDC, 0, 0, SRCCOPY);	//绘制位图

}


// CMyView 诊断

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyView 消息处理程序
