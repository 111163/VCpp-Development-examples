// 控制台项目.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iomanip>

//打印杨辉三角，使用二维数组
int _tmain(int argc, _TCHAR* argv[])
{    
	int a[11][11] = {0};
	for (int i = 1;i<=11;i++)
	{
		a[i][1] = 1;
		a[i][i] = 1;
	}
	for (int i = 3; i<=11 ; i++)
	{
		for (int j = 2; j<= i-1; j++)
			a[i][j] = a[i-1][j] + a[i-1][j-1]; 
	}
	for (int i = 1;i<=11;i++)
	{
		for (int j = 1; j<=i;j++)
			cout << setw(5)<<a[i][j];
		cout << endl;
	}
	getchar();
	return 0;
}





