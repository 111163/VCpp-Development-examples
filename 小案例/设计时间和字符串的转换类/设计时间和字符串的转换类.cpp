// ���ʱ����ַ�����ת����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "TimeString.h"


int _tmain(int argc, _TCHAR* argv[])
{
	time_t te;
	char pstr[80] = "2022-06-26 22:16:27";
	CTimeString::StringToTime(pstr, te); // �Ƚ��ַ���ת��Ϊʱ��
	CTimeString::TimeToString(te, pstr, 80); // �ڽ�ʱ��ת��Ϊ�ַ���
	getchar();
	return 0;
}

