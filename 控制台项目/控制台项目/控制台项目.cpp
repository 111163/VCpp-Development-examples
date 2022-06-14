// 控制台项目.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <iomanip>
using namespace std;


//逆序数组元素
void inverte(int *x, int n)
{
	int *p = x, *q = x + n - 1, tmp = 0;
	for (int i = 0; i <= (n-1)/2 ; i++)
	{
		tmp = *(p+i);
		*(p+i) = *(q-i);
		*(q-i) = tmp;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{   
	int i, a[10] =
	{
		1, 2, 3, 4, 5, 6, 7, 8, 9, 0
	};                                                            //定义数组
	cout << "输入数组元素:\n";
	for (i = 0; i < 10; i++)                                              //输出数组
		cout << a[i] << " ";
	cout << endl;
	inverte(a, 10);                                                  //使数组元素逆序
	cout << "逆序输出数组元素:\n";
	for (i = 0; i < 10; i++)                                              //输出逆序后数组
		cout << a[i] << " ";
	cout << endl;

	getchar();
	return 0;
}






