#include <time.h>

time_t nowTime;
time(&nowTime);                                //获取系统时间
struct tm *sysTime = localtime(&nowTime);                 //转换为系统时间  
cout << "系统日期：" << 1900 + sysTime->tm_year << "-" <<
sysTime->tm_mon + 1 << "-" << sysTime->tm_mday << endl;   //输出信息
cout << "系统时间：" << sysTime->tm_hour << ":" <<
sysTime->tm_min << ":" << sysTime->tm_sec << endl;    //输出信息