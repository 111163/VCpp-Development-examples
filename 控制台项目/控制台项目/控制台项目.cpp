// ����̨��Ŀ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>

const int N = 5;


int _tmain(int argc, _TCHAR* argv[])
{    
	for (int i = 1;i <=N;i++)
	{
		for (int j = 0;j < 5 - i; j++)
			cout << ' '; 
		for (int j = 0; j < 2 * i - 1; j++)
			cout << '#';
			cout <<endl;
	}
	getchar();
	return 0;
}





