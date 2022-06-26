#pragma once
class CTimeString
{
public:
	CTimeString(void);
	~CTimeString(void);
public:
	static void TimeToString(time_t &tmDate, char *szTime, int n);		//时间转换为字符串
	static void StringToTime(char *szTime, time_t &tmDate);		//字符串转换为时间
};

