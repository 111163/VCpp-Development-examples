#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//打印杨辉三角，使用二维数组
int main(int argc, char* argv[])
{    
	int a[12][12] = {0};
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
