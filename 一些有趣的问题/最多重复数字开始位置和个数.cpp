#include <stdio.h>
#include <string>
#include <iomanip>
#include <string.h>
#include <conio.h>
using namespace std;


int main(int argc, char* argv[])
{  
	int a[10]={2,5,3,6,7,7,7,4,7,3};
	int i=0;
	int n=10;
	int len=1,k=0,j=0;
	printf("Array element:\n");
	for(int m=0;m<10;m++)
	{
		printf("%d ",a[m]);
	}
	printf("\n");
	while (i<n-1) 
	{ 
		while (i<n-1 &&a[i]==a[i+1]) 
			i++;                              
		if (i-j+1>len) 
		{
			len=i-j+1;
			k=j;                         /*记下最长的下标*/
		}
		i++;                                    /*连续两个数据不等*/
		j=i;                                      /*记下下一个开始位置*/
	}
	printf("Same max len is %d, Postion is %d\n",len,k);            
	getchar();      
	return 0;
}  