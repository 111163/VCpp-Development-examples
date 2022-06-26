// 设计时间和字符串的转换类.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "TimeString.h"


int _tmain(int argc, _TCHAR* argv[])
{
	time_t te;
	char pstr[80] = "2022-06-26 22:16:27";
	CTimeString::StringToTime(pstr, te); // 先将字符串转换为时间
	CTimeString::TimeToString(te, pstr, 80); // 在将时间转换为字符串
	getchar();
	return 0;
}

