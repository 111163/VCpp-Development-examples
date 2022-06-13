#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


int main(int argc, _TCHAR* argv[])
{      
	for (int a = 1;a < 6;a++)
	{
		for (int b = 1;b < 6;b++)
		{
			if (b!=a)
			{
				for (int c = 1;c < 6;c++)
				{
					if (c!=a && c!= b)
					{
						for (int d = 1;d < 6;d++)
						{
							if (d!=a && d!= b && d!=c)
							{
								for (int e = 1;e < 6; e++)
								{
									if (e != a && e!= b && e!=c && e!= d)
									{ //C不是第一名，D比E低二个名次，而E不是第二名，A既不是第一名，也不是最后一名，B比C低一个名次
										if ((c!=1) && ((d - e)== 2) && (e!=2) && ((a!=1)&&(a!=5)) && ((b-c)==1))
										{
											cout << "A:" << a << endl;
											cout << "B:" << b << endl;
											cout << "C:" << c << endl;
											cout << "D:" << d << endl;
											cout << "E:" << e << endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	getchar();
	return 0;
}



