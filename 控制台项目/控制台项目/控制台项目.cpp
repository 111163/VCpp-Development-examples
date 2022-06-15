// 控制台项目.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <iomanip>
#include <string.h>
#include <conio.h>
using namespace std;


//int main(int argc, char* argv[])
// int _tmain(int argc, _TCHAR* argv[])
// {  
//	int a[10]={2,5,3,6,7,7,7,4,7,3};
//	int i=0;
//	int n=10;
//	int len=1,k=0,j=0;
//	printf("Array element:\n");
//	for(int m=0;m<10;m++)
//	{
//		printf("%d ",a[m]);
//	}
//	printf("\n");
//	while (i<n-1) 
//	{ 
//		while (i<n-1 &&a[i]==a[i+1]) 
//			i++;                              
//		if (i-j+1>len) 
//		{
//			len=i-j+1;
//			k=j;                         /*记下最长的下标*/
//		}
//		i++;                                    /*连续两个数据不等*/
//		j=i;                                      /*记下下一个开始位置*/
//	}
//	printf("Same max len is %d, Postion is %d\n",len,k);            
//	getchar();      
//	return 0;
//}  

void combin(int *a,int *b,int *c,int n,int m)
{
	int *p1,*p2,*p3;
	for (p1=a,p2=b,p3=c;p1<a+n && p2<b+m;)
		if (*p1<*p2)                                 /*将数据小的存放到p3指向的地址空间*/
			*p3++=*p1++;
		else
			*p3++=*p2++;
	while (p1<a+n)  *p3++=*p1++;   //如果是将p1放入到了p3,
	while (p2<b+m) *p3++=*p2++;
}
void main() 
{
	int a[6]={1,11,2,12,3,13};//1,2,3,4,5,6
	int b[5]={4,14,5,15,6};//11,12,13,14,15
	int c[5+6];
	int *p=a,*q=b;
	printf("Array a: ");
	for(int i=0;i<6;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	printf("Array b: ");
	for(int j=0;j<5;j++)
	{
		printf("%d ",b[j]);
	}
	printf("\n");
	combin(a,b,c,6,5);                               /*实参为数组*/
	for(p=c;p<c+5+6;p++)
		printf("%2d ",*p);
	printf("\n",*p);
	getchar();
}