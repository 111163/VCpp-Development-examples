// 控制台项目.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>


int _tmain(int argc, _TCHAR* argv[])
{      
//10元钱找零钱思路,1元2元5元可以供兑换
	for (int i = 0 ; i <= (10/1); i++)
	{
		for (int j = 0 ; j <= (10/2); j++)
		{
			for (int k = 0 ; k <= (10/5); k++)
			{
				if (i+2*j+5*k == 10)
					cout << "一元:" << i << "二元:" << j << "五元:" << k << endl;
			}
		}
	}
	getchar();
	return 0;
}



