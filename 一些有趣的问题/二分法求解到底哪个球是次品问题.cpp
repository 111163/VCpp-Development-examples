#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int Weight(int* , int, int);

int main(int argc, char* argv[])
{      
	int aa[10] = {1,1,1,1,1,2,1,1,1,1};//  2,  ,2 
	cout << Weight(aa, 0, 10) + 1;
	getchar();
	return 0;
}


int Weight(int iArray[], int first, int end1)
{
	int  a = 0, b = 0;
	for (int i = 0; i < end1/2; i++)
	{
		int j = first + i;
		a += iArray[j];
		b += iArray[j + end1/2];
	}
	if (2 == end1) return ((a > b)? first: first+1);
	if (a != b)
	{
		if (a < b) first = end1 / 2;	
		end1 /= 2;
		return Weight(iArray, first, end1);
	}
	return end1-1;
}
