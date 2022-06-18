#include <iostream>
#include <string.h>
#include <Windows.h>
using namespace std;

// 在main函数中调用GetLogicalDriveStrings函数获取系统盘符字符串，然后利用while循环语句分解字符串。
	int main(int argc, char* argv[])
{
	DWORD dwLen = GetLogicalDriveStrings(0, nullptr);        //获取系统盘符字符串长度
	char *pszDriver = new char[dwLen];                                //构建字符数组
	GetLogicalDriveStrings(dwLen, pszDriver);                //获取系统盘符字符串
	char* pDriver = pszDriver;                                        //定义一个临时指针
	while (*pDriver != '\0')                                      //遍历字符串
	{
		cout << pDriver << endl;                                    //输出系统盘符
		pDriver += strlen(pDriver) + 1;                                   //定位到下一个字符串，加1是为了跳过\0字符
	}
	delete [] pszDriver;                                            //释放字符数组
	return 0;
}