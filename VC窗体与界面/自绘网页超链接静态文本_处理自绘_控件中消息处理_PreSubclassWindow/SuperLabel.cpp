// SuperLabel.cpp : 实现文件
//

#include "stdafx.h"
#include "自绘网页超链接静态文本.h"
#include "SuperLabel.h"
#include "Resource.h"


// CSuperLabel

IMPLEMENT_DYNAMIC(CSuperLabel, CStatic)

CSuperLabel::CSuperLabel()
{

}

CSuperLabel::~CSuperLabel()
{
}


BEGIN_MESSAGE_MAP(CSuperLabel, CStatic)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// CSuperLabel 消息处理程序




void CSuperLabel::PreSubclassWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	GetWindowText(m_ConnectStr);
	CFont* pFont = GetFont();

	pFont->GetLogFont(&lfont);
	lfont.lfUnderline =TRUE;
	m_Font.CreateFontIndirect(&lfont);
	CStatic::PreSubclassWindow();
}


void CSuperLabel::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CStatic::OnPaint()
	CDC* pDC = GetDC();

	CString text;
	GetWindowText(text);

	if (m_ConnectStr.IsEmpty())
		m_ConnectStr = text;

	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(RGB(0,0,255));


	pDC->SelectObject(&m_Font);
	pDC->TextOut(0,0,text);

}


void CSuperLabel::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ShellExecute(m_hWnd,NULL,m_ConnectStr,NULL,NULL,SW_SHOW);		
	CStatic::OnLButtonDown(nFlags, point);
}


void CSuperLabel::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
	CStatic::OnMouseMove(nFlags, point);
}
