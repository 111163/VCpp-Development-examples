#include <time.h>

time_t nowTime;
time(&nowTime);                                //��ȡϵͳʱ��
struct tm *sysTime = localtime(&nowTime);                 //ת��Ϊϵͳʱ��  
cout << "ϵͳ���ڣ�" << 1900 + sysTime->tm_year << "-" <<
sysTime->tm_mon + 1 << "-" << sysTime->tm_mday << endl;   //�����Ϣ
cout << "ϵͳʱ�䣺" << sysTime->tm_hour << ":" <<
sysTime->tm_min << ":" << sysTime->tm_sec << endl;    //�����Ϣ