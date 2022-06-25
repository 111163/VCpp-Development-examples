// 设计ini文件操作类.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "FileOpt.h"

int _tmain(int argc, _TCHAR* argv[])
{
	char *pszStudent = "姓名:张某\n年龄:28\n学历:本科\n";
	CFileOpt file;
	file.OpenFile("./user.ini");
	file.WriteFile(pszStudent, strlen(pszStudent));
	getchar();
	return 0;
}

