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
	a[0] = atoi(str) + 160;		//���㺺�ֵ�ǰ8λ�ֽ�
	str = string.Right(2);
	a[1] = atoi(str) + 160;		//���㺺�ֵĺ�8λ�ֽ�
	str = a;
	return str.Left(2);		//��ʾ����
}
CString CChange::GetAreaCode(CString string)
{
	char a,b;
	CString str;
	a = string.GetAt(0)-160;		//���ǰ8λ�ֽڲ�����160
	b = string.GetAt(1)-160;		//��ú�8λ�ֽڲ�����160
	str.Format("%d%d",a,b);			//��ʾ��λ��
	return str;
}
