﻿// 控制台项目.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <iomanip>
#include <string.h>
#include <conio.h>
using namespace std;


int add(int a, int b)
{
	return a + b;
}

//int main(int argc, char* argv[])
int _tmain(int argc, _TCHAR* argv[])
{  
	int a[10] = {0},temp, num;
	for (int i = 0;i < 10 ;i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
	for (int i = 0; i < 9;i++)
	{
		for (int j = i + 1;j < 10;j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	cout<<"输入要查找的数据："<<"\n";
	cin >> num;
	cout<<"输出数组："<<"\n";
	for(int i=0;i<10;i++)
	{
		cout<< "a["<< i <<"]=" << a[i]<<"\t";
		if((i+1)%3 == 0)
			cout<<"\n";
	}
	cout<< endl;


	int left = 0, right = 9, mid, l = 0,r = 0, n = 0;
	while(left < right)
	{
		mid = (left + right)/ 2;
		if (a[mid] == num)
		{
 			for(int i = mid ; i > left; i--)
 			{
 				if (a[i - 1] != a [i])break;
 				l++;
 			}
 			for(int i = mid ; i < right; i++)
 			{
 				if ( a[i] != a[i + 1])break;
 				r++;
 			}	
			// 共找到几个
			n = l + r + 1;
			for (int i = mid - l; i <= mid + r ;i++)
			{
				cout << "要查找的元素是：" << "\n";
				cout << "a["<< i <<"]="<< num << "\n";
			}
			break;
		} 
		if (a[mid] > num)
			right = mid - 1;
		if (a[mid] < num)
			left = mid + 1;
	}
	if(0==n)
		cout<<"要查找的元素不存在！"<<"\n";
	getchar();
	return 0;
}  







