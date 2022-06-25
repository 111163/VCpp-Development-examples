// 设计ini文件操作类.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "FileOpt.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//char *pszStudent = "姓名:张某\n年龄:28\n学历:本科\n";
	char str[128];
	memset(str, 0, 128);
	CFileOpt file;
	file.OpenFile("./user.ini", 1); // WriteFile("./user.ini");
	int a = file.RradFile(str, 128);// WriteFile(pszStudent, strlen(pszStudent)) RradFile(str, strlen(str))这里这么写的话strlen(str)=>0
	cout << str ;      //
	cout << a << endl; //
	getchar();
	return 0;
}

