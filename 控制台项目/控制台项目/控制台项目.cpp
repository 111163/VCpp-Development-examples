// 控制台项目.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <math.h>
#include <conio.h>

int _tmain(int argc, _TCHAR* argv[])
{    
	double y;
	int x, m;
	for(y = 1;y>=-1;y-=0.1)
	{
		m = acos(y)*10;
		for (x = 1;x<m;x++)
			cout << " ";
		cout << "*";
		for (;x<62-m;x++)
			cout << " ";
		cout << "*\n";
	}
	getchar();
	return 0;
}





