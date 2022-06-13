// 控制台项目.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>

int dev(int num, int *);

int _tmain(int argc, _TCHAR* argv[])
{    
//	int aa[30-10+1] = {0};
//	int bb[10] = {0};
//	int j = 0;
//	for (int i = 10 ; i <= 30 ; i++)
//	{
//		if (((i*i)/100)>0 && ((i*i)/100)<=9)
//		{
//			if (((i*i*i)/1000)>0 && ((i*i*i)/1000)<=9)
//			{
//				if (((i*i*i*i)/100000)>0 && ((i*i*i*i)/100000)<=9)
//				{
//					cout << i << endl;
//					aa[j++] = i;
//				}
//			}
//		}
//	}
//	for (int i = 0;i < j; i++)
//	{
//		bb[aa[i]*aa[i]/100]++;
//		bb[aa[i]*aa[i]%100/10]++;
//		bb[aa[i]*aa[i]%10/1]++;
//	}
	int aa[40] = {0};
	cout << "输入了一个"<<dev((long long)(922337203), aa) <<"位数"<< endl;
	getchar();
	return 0;
}

int dev(int num, int aa[])
{
	int n = 1;
	int i = 0;
	while(num / n )
	{
		aa[i++]=(num % (10 * n))/n;
		n *= 10;	
	}
	n = i;
	for (i-=1; i >= 0;i--)
		cout << aa[i];
	return n;
}



