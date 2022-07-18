// ListBmp.cpp : 实现文件
//

#include "stdafx.h"
#include "为ListBox添加背景.h"
#include "ListBmp.h"


// CListBmp

IMPLEMENT_DYNAMIC(CListBmp, CListBox)

CListBmp::CListBmp()
{

}

CListBmp::~CListBmp()
{
}


BEGIN_MESSAGE_MAP(CListBmp, CListBox)
	ON_WM_PAINT()
	/*ON_WM_DRAWITEM_REFLECT()*/
	ON_WM_VSCROLL()
END_MESSAGE_MAP()



// CListBmp 消息处理程序




void CListBmp::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	CRect rect,clrRC;
	GetClientRect(&rect);
	CBitmap bitmap;
	CDC memdc;
	memdc.CreateCompatibleDC(&dc);
	bitmap.LoadBitmap(IDB_BITMAP1);
	memdc.SelectObject(&bitmap);
	dc.BitBlt(0,0,rect.Width(),rect.Height(),&memdc,0,0,SRCCOPY);
	bitmap.DeleteObject();
	ReleaseDC(&memdc);

	for(int i=0;i<rect.Height()/GetItemHeight(0);i++)
	{
		GetItemRect(i,clrRC);
		CString str;
		GetText(i+GetTopIndex(),str);
		dc.SetBkMode(TRANSPARENT);
		dc.TextOut(0,i*GetItemHeight(i),str);
	}

	// 不为绘图消息调用 CListBox::OnPaint()
}


void CListBmp::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: 在此处添加消息处理程序代码
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);
	int nIndex = lpDrawItemStruct->itemID;							//获取当前项目索引
	//判断项目状态
	int nState = lpDrawItemStruct->itemState;
	CRect rect,clrRC;
	GetClientRect(&rect);
	CBitmap bitmap;
	CDC memdc;
	memdc.CreateCompatibleDC(&dc);
	bitmap.LoadBitmap(IDB_BITMAP1);
	memdc.SelectObject(&bitmap);
	GetItemRect(nIndex,clrRC);
	m_pFont = GetFont();				//获得字体
	dc.SelectObject(m_pFont);
	if(nState & ODS_SELECTED)	//处于选中状态
	{	
		dc.SetTextColor(RGB(200,0,0));		//设置选中状态文本颜色
		dc.FillSolidRect(&clrRC, RGB(0,0,200));			//填充项目区域为高亮效果
	}
	else
	{
		int nCurSel = nIndex-GetTopIndex();					//设置当前索引基于可见项的位置
		dc.BitBlt(0,nCurSel*clrRC.Height(),clrRC.Width(),clrRC.Height()
			,&memdc,0,nCurSel*clrRC.Height(),SRCCOPY);
		dc.SetTextColor(RGB(0,0,0));		//设置文本颜色
	}
	if(nIndex != -1)
	{
		CString str;
		GetText(nIndex,str);
		dc.SetBkMode(TRANSPARENT);
		dc.TextOut(0,(nIndex-GetTopIndex())*clrRC.Height(),str);
	}
	m_pFont->DeleteObject();
	bitmap.DeleteObject();
	ReleaseDC(&memdc);
	dc.DeleteDC();
}



void CListBmp::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Invalidate();
	CListBox::OnVScroll(nSBCode, nPos, pScrollBar);
}
