// LevelStatic.cpp : 实现文件
//

#include "stdafx.h"
#include "自绘静态文本.h"
#include "LevelStatic.h"


// CLevelStatic

IMPLEMENT_DYNAMIC(CLevelStatic, CStatic)

CLevelStatic::CLevelStatic()
{
	m_TextMargin = 2;
}

CLevelStatic::~CLevelStatic()
{
}


BEGIN_MESSAGE_MAP(CLevelStatic, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CLevelStatic 消息处理程序




void CLevelStatic::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CStatic::OnPaint()
	CRect   rectWnd; 
	CString cstrText; 
	UINT    uFormat;  
	GetWindowText(cstrText);                                 //获得静态文本控件的显示文本
	dc.SelectObject(GetFont());                               //选中当前控件字体
	CSize size = dc.GetTextExtent(cstrText);                    //计算文本的宽度和高度
	DWORD    dwStyle = GetStyle();                           //获取控件风格
	GetWindowRect (rectWnd);                        //获得窗口区域
	uFormat = DT_TOP;
	if ( dwStyle & SS_NOPREFIX )
		uFormat |= DT_NOPREFIX;
	//绘制文本左边条
	dc.Draw3dRect(0, rectWnd.Height()/2,(rectWnd.Width()-size.cx)/2-m_TextMargin
		, 2, ::GetSysColor(COLOR_3DSHADOW),::GetSysColor(COLOR_3DHIGHLIGHT) );
	dc.SetBkMode(TRANSPARENT);
	//绘制文本
	dc.DrawText(cstrText,CRect((rectWnd.Width()-size.cx)/2,0,(rectWnd.Width()-size.cx)/2
		+size.cx,size.cy),DT_LEFT|DT_SINGLELINE|DT_VCENTER );
	//绘制文本右边条
	dc.Draw3dRect((rectWnd.Width()-size.cx)/2+size.cx , rectWnd.Height()/2
		,(rectWnd.Width()-size.cx)/2-m_TextMargin, 2, ::GetSysColor(COLOR_3DSHADOW),
		::GetSysColor(COLOR_3DHIGHLIGHT) );  

}
