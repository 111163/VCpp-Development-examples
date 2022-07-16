// MyBotton.cpp : 实现文件
//

#include "stdafx.h"
#include "进制转换器.h"
#include "MyEdit.h"


// CMyEdit

IMPLEMENT_DYNAMIC(CMyEdit, CEdit)

CMyEdit::CMyEdit()
{

}

CMyEdit::~CMyEdit()
{
}


BEGIN_MESSAGE_MAP(CMyEdit, CEdit)
	ON_WM_CHAR()
END_MESSAGE_MAP()


void  CMyEdit::SetChange(int a)
{
	m_Change = a;
}
// CMyEdit 消息处理程序




void CMyEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) // 36进制是0-9 + a-z
{
	if(nChar == 8)                                                         //退格键 
	{
		CEdit::OnChar(nChar, nRepCnt, nFlags);
		return;
	}
	if(m_Change == 10)
	{
		if(nChar<48 || nChar>57)                                   //允许输入数字
			nChar = 0;
		else
			CEdit::OnChar(nChar, nRepCnt, nFlags);
	}
	else if(m_Change == 2)
	{
		if(nChar<48 || nChar>49)                                   //允许输入数字
			nChar = 0;
		else
			CEdit::OnChar(nChar, nRepCnt, nFlags);
	}
	else if(m_Change == 8)
	{
		if(nChar<48 || nChar>55)                                   //允许输入数字
			nChar = 0;
		else
			CEdit::OnChar(nChar, nRepCnt, nFlags);
	}
	else if(m_Change == 16)
	{
		if((nChar>47 && nChar<58) || (nChar>64 && nChar<71) 
			|| (nChar>96 && nChar<103))                       //允许输入数字
			CEdit::OnChar(nChar, nRepCnt, nFlags);
		else
			nChar = 0;
	}
}
