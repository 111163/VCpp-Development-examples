// ini文件读写类.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "IniFile.h"
#include <iostream>
using namespace std;

// 注意输入参数和输出参数的确定应该是在函数定义或说明的时候有了解
int _tmain(int argc, _TCHAR* argv[])
{
	CIniFile::WriteData("c:\\user.ini", "用户信息", "用户名称", "张良");
	CIniFile::WriteData("c:\\user.ini", "用户信息", "用户密码", "111111");

	char szUserName[128] = {0};
	char szPassword[128] = {0};

	CIniFile::ReadData("c:\\user.ini", "用户信息", "用户名称", szUserName);
	CIniFile::ReadData("c:\\user.ini", "用户信息", "用户密码", szPassword);

	cout << szUserName << endl;
	cout << szPassword << endl;
	return 0;
}

