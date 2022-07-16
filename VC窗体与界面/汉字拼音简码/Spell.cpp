#include "StdAfx.h"
#include "Spell.h"


CSpell::CSpell(void)
{
}


CSpell::~CSpell(void)
{
}

CString CSpell::SetString(CString str)
{
	char ch1 = str.GetAt(0)-160;	//获得汉字前8位字节
	char ch2 = str.GetAt(1)-160;	//获得汉字后8位字节
	CString s1,s2;
	s1.Format("%d",ch1+160);
	s2.Format("%d",ch2+160);
	int num1 = atoi(s1);
	int num2 = atoi(s2);
	int code = (num1<<8) + num2;	//前8位字节向左移动8位加上后8位字节
	//定义汉字拼音表
	int areacode[] = {45217,45253,45761,46318,46826,47010,47297,
		47614,48119,48119,49062,49324,49896,50371,50614,50622,
		50906,51387,51446,52218,52698,52698,52698,52980,53689,54481};
	//在汉字拼音表中查找
	for(int i=0;i<26;i++)
	{
		int max = 55290;
		if(i != 25) max = areacode[i+1];
		{
			if(areacode[i]<=code && code<max)
			{
				CString ss;
				ss.Format("%c",(65+i));	//格式化字符
				return ss;				//返回拼音简码
			}
		}
	}
	return 0;
}
CString CSpell::GetSpell(CString str)
{
	CString m_Spell = "";
	int len = str.GetLength();
	int num = 0;
	for (int i = 0; i<len; ++i)
	{
		char ch;
		ch = str.GetAt(i);
		if (ch<0 || ch>255)
		{
			num++;
			m_Spell += SetString(str.Mid(i,2));
			i++;
		}
		else
		{
			m_Spell += str.Mid(i,1);
		}
	}
	return m_Spell;
}
