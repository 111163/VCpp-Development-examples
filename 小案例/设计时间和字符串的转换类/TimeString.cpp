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
	//	int tm_sec; /* �� �C ȡֵ����Ϊ[0,59] */
	//	int tm_min; /* �� - ȡֵ����Ϊ[0,59] */
	//	int tm_hour; /* ʱ - ȡֵ����Ϊ[0,23] */
	//	int tm_mday; /* һ�����е����� - ȡֵ����Ϊ[1,31] */
	//	int tm_mon; /* �·ݣ���һ�¿�ʼ��0����һ�£� - ȡֵ����Ϊ[0,11] */
	//	int tm_year; /* ��ݣ���ֵ����ʵ����ݼ�ȥ1900 */
	//	int tm_wday; /* ���� �C ȡֵ����Ϊ[0,6]������0���������죬1��������һ���Դ����� */
	//	int tm_yday; /* ��ÿ���1��1�տ�ʼ������ �C ȡֵ����Ϊ[0,365]������0����1��1�գ�1����1��2�գ��Դ����� */
	//	int tm_isdst; /* ����ʱ��ʶ����ʵ������ʱ��ʱ��tm_isdstΪ������ʵ������ʱ�Ľ���tm_isdstΪ0�����˽����ʱ��tm_isdst()Ϊ����*/
	//};


//����ԭ��: time_t time(time_t *timer)
//
//����˵��: timer=NULLʱ�õ���ǰ����ʱ�䣨��1970-01-01 00:00:00�����ڵ���������timer=ʱ����ֵʱ��������������ʱ�䣬
//time_t��һ��unsigned long���͡���� timer��Ϊ�գ��򷵻�ֵҲ�洢�ڱ��� timer�С�


//����ԭ��: struct tm *localtime(const time_t *timer)
//
//��������: ʹ�� timer ��ֵ����� tm �ṹ��timer ��ֵ���ֽ�Ϊ tm �ṹ�����ñ���ʱ����ʾ��
//��������: ��tm�ṹ����ʱ��
//////////////////////////////////////ע��������һ���ṹ������ṹ����ϵͳͨ�õģ���ת����һ�����//////////////////////////////////////////
//////////////////////////////////////������ַ�����ϵͳʱ��Ļ���Ҫע�⽫�ṹ��Ϊϵͳʱ��(����)//////////////////////////////////////////


////��������������Ǵ�tm����ṹ�任��time_t���ϵͳʱ���,ע������ʱ/////
//����ԭ�ͣ�time_t mktime(struct tm *timeptr)
//
//�������ܣ��� timeptr ��ָ��Ľṹת��Ϊһ�����ݱ���ʱ���� time_t ֵ
//�������أ��ú�������һ�� time_t ֵ����ֵ��Ӧ���Բ������ݵ�����ʱ�䡣������������򷵻� -1 ֵ��
//mktime ������ָ�� tm �����ָ����Ϊ������������Լ�Ԫ������ʱ����Ϊ���� time_t ��ֵ���ء�ֵ time->tm_wday �� time->tm_yday �����ԡ�
//���time->tm_isdst ��ֵΪ���������ᵼ�� mktime ����ȷ������ʱ�Ƿ���Ч��
//ʹ����mktime��tm_wday��tm_year��tm�ṹ�е�����ֵ������Զ�У��



void CTimeString::TimeToString(time_t &tmDate, char *szTime, int n)		//ʱ��ת��Ϊ�ַ���
{
	//strcpy(szTime, ctime(&tmDate)); ���ʹ������Ч������ asctime(localtime(&tmDate))

	struct tm *pNewTime;
	pNewTime = localtime(&tmDate);
	
	// strcpy(szTime, asctime(pNewTime)); ���ֱ�ӾͿ��Ի�õ�Sun Sep 16 01:03:52 1973\n\0�����Ĵ�


	/*	sprintf(szTime, "%d-%d-%d %d:%d:%d", 1900 + pNewTime->tm_year,1 + pNewTime->tm_mon, pNewTime->tm_mday,
	pNewTime->tm_hour, pNewTime->tm_min, pNewTime->tm_sec);*/ //ΪʲôҪд�����أ�Ϊ���Լ����Ʒ��ϸ�ʽ�����������Լ����ƾ�Ҫ����tm_year + 1900, tm_mon + 1


	strftime(szTime, n, "%Y-%m-%d %H:%M:%S", pNewTime); // ������ȷ��ʹ�ÿ�����ɹ��ܣ�����ʡȥ��+1900��+1�Ĳ���


	// �����Ҫ֪��ĳ��������ʱ������� clock_t start = clock();{��}; clock_t end = clock(); clock_t total = (end - start)/ CLOCKS_PER_SEC;

	// �����Ҫ֪�������������ڵĲ�ֵ(��Ϊ��λ) double difftime(time_t time1, time_t time0); ע��������time_t     ���˵֪������tm���͵�Ҫ����mktime����ֵ�ĵ�time_t���͵�ֵ

   // ʹ��mktime(struct tm *timeptr)��ʱ�����timeptr����ʵ�е����ݵĻ�Ҫ����timeptr->tm_year -= 1900; timeptr->tm_mon -= 1;���ܴ���mktime������	
   // ͬʱʹ����mktime�����������tm_mday,tm_yday��ֵ�������͵õ���ȷ�����ں�һ���еĵڼ��죬��ע���������Ǵ�0��ʼ������

	// ������ȡ���˱���ʱ��time_t,������֪������Э��ʱ��Ļ���Ӧ����gmtime(const time_t *timer),����ֵ��tm�ṹ

	// C �⺯�� size_t strftime(char *str, size_t maxsize, const char *format, const struct tm *timeptr) ���� format �ж���ĸ�ʽ�����򣬸�ʽ���ṹ timeptr ��ʾ��ʱ�䣬�������洢�� str �С�
	
	cout << szTime << endl;
}
void CTimeString::StringToTime(char *szTime, time_t &tmDate)		//�ַ���ת��Ϊʱ��
{
	int nDateList[6] = {0}, j = 0, k = 0;
	char *strP = szTime;
	// ���ַ�����ȡ������������ӵ�һ��������
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
