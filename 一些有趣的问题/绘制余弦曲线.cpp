#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <conio.h>
using namespace std;

int main(int argc, char* argv[]) //»æÖÆy[1,-1],¼´x[0,2¦Ð]
{    
	double y;
	int x, m;
	for(y = 1;y>=-1;y-=0.1)
	{
		m = acos(y)*10;
		for (x = 1;x<m;x++)
			cout << " ";
		cout << "*";
		for (;x<62-m;x++)
			cout << " ";
		cout << "*\n";
	}
	getchar();
	return 0;
}