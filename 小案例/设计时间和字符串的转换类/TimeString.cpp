#include "StdAfx.h"
#include "TimeString.h"
using namespace std;


CTimeString::CTimeString(void)
{
}


CTimeString::~CTimeString(void)
{
}

	//struct tm {
	//	int tm_sec; /* 秒 – 取值区间为[0,59] */
	//	int tm_min; /* 分 - 取值区间为[0,59] */
	//	int tm_hour; /* 时 - 取值区间为[0,23] */
	//	int tm_mday; /* 一个月中的日期 - 取值区间为[1,31] */
	//	int tm_mon; /* 月份（从一月开始，0代表一月） - 取值区间为[0,11] */
	//	int tm_year; /* 年份，其值等于实际年份减去1900 */
	//	int tm_wday; /* 星期 – 取值区间为[0,6]，其中0代表星期天，1代表星期一，以此类推 */
	//	int tm_yday; /* 从每年的1月1日开始的天数 – 取值区间为[0,365]，其中0代表1月1日，1代表1月2日，以此类推 */
	//	int tm_isdst; /* 夏令时标识符，实行夏令时的时候，tm_isdst为正。不实行夏令时的进候，tm_isdst为0；不了解情况时，tm_isdst()为负。*/
	//};


//函数原型: time_t time(time_t *timer)
//
//参数说明: timer=NULL时得到当前日历时间（从1970-01-01 00:00:00到现在的秒数），timer=时间数值时，用于设置日历时间，
//time_t是一个unsigned long类型。如果 timer不为空，则返回值也存储在变量 timer中。


//函数原型: struct tm *localtime(const time_t *timer)
//
//函数功能: 使用 timer 的值来填充 tm 结构。timer 的值被分解为 tm 结构，并用本地时区表示。
//函数返回: 以tm结构表达的时间
//////////////////////////////////////注意这里是一个结构，这个结构不是系统通用的，是转换的一个结果//////////////////////////////////////////
//////////////////////////////////////如果从字符串到系统时间的话，要注意将结构变为系统时间(秒数)//////////////////////////////////////////


////下面这个函数就是从tm这个结构变换到time_t这个系统时间的,注意夏令时/////
//函数原型：time_t mktime(struct tm *timeptr)
//
//函数功能：把 timeptr 所指向的结构转换为一个依据本地时区的 time_t 值
//函数返回：该函数返回一个 time_t 值，该值对应于以参数传递的日历时间。如果发生错误，则返回 -1 值。
//mktime 函数将指向 tm 对象的指针作为其参数，并将自纪元以来的时间作为类型 time_t 的值返回。值 time->tm_wday 和 time->tm_yday 被忽略。
//如果time->tm_isdst 的值为负数，它会导致 mktime 尝试确定夏令时是否有效。
//使用完mktime后tm_wday，tm_year和tm结构中的其他值都会别自动校正



void CTimeString::TimeToString(time_t &tmDate, char *szTime, int n)		//时间转换为字符串
{
	//strcpy(szTime, ctime(&tmDate)); 如果使用它的效果就是 asctime(localtime(&tmDate))

	struct tm *pNewTime;
	pNewTime = localtime(&tmDate);
	
	// strcpy(szTime, asctime(pNewTime)); 这个直接就可以获得到Sun Sep 16 01:03:52 1973\n\0这样的串


	/*	sprintf(szTime, "%d-%d-%d %d:%d:%d", 1900 + pNewTime->tm_year,1 + pNewTime->tm_mon, pNewTime->tm_mday,
	pNewTime->tm_hour, pNewTime->tm_min, pNewTime->tm_sec);*/ //为什么要写这条呢？为了自己定制符合格式的输出，如果自己定制就要处理tm_year + 1900, tm_mon + 1


	strftime(szTime, n, "%Y-%m-%d %H:%M:%S", pNewTime); // 这是正确的使用库来完成功能，而且省去了+1900和+1的操作


	// 如果想要知道某个块运行时间可以用 clock_t start = clock();{块}; clock_t end = clock(); clock_t total = (end - start)/ CLOCKS_PER_SEC;

	// 如果想要知道两个两个日期的差值(秒为单位) double difftime(time_t time1, time_t time0); 注意这里是time_t     如果说知道的是tm类型的要先用mktime返回值的到time_t类型的值

   // 使用mktime(struct tm *timeptr)的时候如果timeptr是现实中的数据的话要进行timeptr->tm_year -= 1900; timeptr->tm_mon -= 1;才能传到mktime函数中	
   // 同时使用了mktime函数后会修正tm_mday,tm_yday的值，这样就得到正确的星期和一年中的第几天，但注意这两都是从0开始计数的

	// 如果你获取到了本地时间time_t,但是想知道世界协调时间的话，应该用gmtime(const time_t *timer),返回值是tm结构

	// C 库函数 size_t strftime(char *str, size_t maxsize, const char *format, const struct tm *timeptr) 根据 format 中定义的格式化规则，格式化结构 timeptr 表示的时间，并把它存储在 str 中。
	
	cout << szTime << endl;
}
void CTimeString::StringToTime(char *szTime, time_t &tmDate)		//字符串转换为时间
{
	int nDateList[6] = {0}, j = 0, k = 0;
	char *strP = szTime;
	// 从字符串获取到各个项是最复杂的一个过程了
	for (int i = 0; i < strlen(szTime); i++)
	{
		if (isdigit(szTime[i]))
		{
			nDateList[j] = atoi(strP);
			while(isdigit(strP[0]) && strP[0]) 
			{
				strP++;
				i++;
			}
			i--;
		}	
		else
		{
			while((!isdigit(szTime[i])) && i < strlen(szTime))
			{
				i++;
				strP++;
			}
			i--;
			j++;
		}
	}
	struct tm newTime;
	newTime.tm_year = nDateList[0]-1900;
	newTime.tm_mon = nDateList[1]-1;
	newTime.tm_mday = nDateList[2];
	newTime.tm_hour = nDateList[3];
	newTime.tm_min = nDateList[4];
	newTime.tm_sec = nDateList[5];
	newTime.tm_isdst  = -1;
	tmDate = mktime(&newTime);
}
