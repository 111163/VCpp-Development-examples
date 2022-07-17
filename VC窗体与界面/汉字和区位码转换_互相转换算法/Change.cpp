#include "StdAfx.h"
#include "Change.h"


CChange::CChange(void)
{
}


CChange::~CChange(void)
{
}


CString CChange::GetChar(CString string)
{
	char a[2];
	CString str;
	str = string.Left(2);
	a[0] = atoi(str) + 160;		//计算汉字的前8位字节
	str = string.Right(2);
	a[1] = atoi(str) + 160;		//计算汉字的后8位字节
	str = a;
	return str.Left(2);		//显示汉字
}
CString CChange::GetAreaCode(CString string)
{
	char a,b;
	CString str;
	a = string.GetAt(0)-160;		//获得前8位字节并加上160
	b = string.GetAt(1)-160;		//获得后8位字节并加上160
	str.Format("%d%d",a,b);			//显示区位码
	return str;
}
