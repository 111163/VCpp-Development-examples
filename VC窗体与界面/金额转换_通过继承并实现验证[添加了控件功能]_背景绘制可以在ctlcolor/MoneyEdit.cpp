// MoneyEdit.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "���ת��.h"
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



// CMoneyEdit ��Ϣ�������




void CMoneyEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString str;
	GetWindowText(str);
	if (nChar == VK_BACK)
	{
		CEdit::OnChar(nChar, nRepCnt, nFlags);
		return;
	}
	//��ֹС���������3λ����
	if ((str.GetLength() - str.Find('.', 0)== 3) && (str.Find('.', 0) != -1)) // ������С���㣬���Һ������������һλ
		nChar = 0;														// ����δ����
	//��ֹ��������С����
	if((nChar==46) && (!str.IsEmpty()) && (str.Find('.',0)!= -1)) // ���뱣��ķ�����С����,���ұ���ķǿգ����������С����
		nChar = 0;                                                // ��Ч����
	//ֻ������������\����\С����
	if(((nChar <45) || (nChar>46)) && ((nChar<48) || (nChar > 57)))  // ����Ĳ��Ǵ���С�����֣�С���㣬���ţ�������Ч����
		nChar = 0;
	else
		CEdit::OnChar(nChar, nRepCnt, nFlags);
}
