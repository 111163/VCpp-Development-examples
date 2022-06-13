// 控制台项目.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <iomanip>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   
	int aa[14] = {0},j = 0;
	for (int i = 1; i <= 13; i++)
	{
		int b = 0;
		for (; b < i ;j++)
			if (0 == aa[j % 13 + 1]) 
				b++;
		aa[j % 13] = i;
	}
	aa[13] = aa[j%13];
	for (int i = 1; i <= 13; i++)
		cout << aa[i] << "  ";
	getchar();

	return 0;
}






