#pragma once
class CTimeString
{
public:
	CTimeString(void);
	~CTimeString(void);
public:
	static void TimeToString(time_t &tmDate, char *szTime, int n);		//ʱ��ת��Ϊ�ַ���
	static void StringToTime(char *szTime, time_t &tmDate);		//�ַ���ת��Ϊʱ��
};

