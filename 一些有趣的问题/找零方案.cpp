#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


int main(int argc, _TCHAR* argv[])
{      
//10ԪǮ����Ǯ˼·,1Ԫ2Ԫ5Ԫ���Թ��һ�
	for (int i = 0 ; i <= (10/1); i++)
	{
		for (int j = 0 ; j <= (10/2); j++)
		{
			for (int k = 0 ; k <= (10/5); k++)
			{
				if (i+2*j+5*k == 10)
					cout << "һԪ:" << i << "��Ԫ:" << j << "��Ԫ:" << k << endl;
			}
		}
	}
	getchar();
	return 0;
}



