// MoneyEdit.cpp : 实现文件
//

#include "stdafx.h"
#include "金额转换.h"
#include "MoneyEdit.h"


// CMoneyEdit

IMPLEMENT_DYNAMIC(CMoneyEdit, CEdit)

CMoneyEdit::CMoneyEdit()
{

}

CMoneyEdit::~CMoneyEdit()
{
}


BEGIN_MESSAGE_MAP(CMoneyEdit, CEdit)
	ON_WM_CHAR()
END_MESSAGE_MAP()



// CMoneyEdit 消息处理程序




void CMoneyEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString str;
	GetWindowText(str);
	if (nChar == VK_BACK)
	{
		CEdit::OnChar(nChar, nRepCnt, nFlags);
		return;
	}
	//防止小数点后输入3位数字
	if ((str.GetLength() - str.Find('.', 0)== 3) && (str.Find('.', 0) != -1)) // 发现了小数点，并且后面是又输入的一位
		nChar = 0;														// 代表未输入
	//防止输入两个小数点
	if((nChar==46) && (!str.IsEmpty()) && (str.Find('.',0)!= -1)) // 输入保存的发现了小数点,并且保存的非空，新输入的是小数点
		nChar = 0;                                                // 无效输入
	//只允许输入数字\负号\小数点
	if(((nChar <45) || (nChar>46)) && ((nChar<48) || (nChar > 57)))  // 输入的不是大于小于数字，小数点，负号，就是无效输入
		nChar = 0;
	else
		CEdit::OnChar(nChar, nRepCnt, nFlags);
}
