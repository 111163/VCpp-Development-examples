#include <stdio.h>
#include <string>
#include <iomanip>
using namespace std;


//��������Ԫ��
void inverte(int *x, int n)
{
	int *p = x, *q = x + n - 1, tmp = 0;
	for (int i = 0; i <= (n-1)/2 ; i++)
	{
		tmp = *(p+i);
		*(p+i) = *(q-i);
		*(q-i) = tmp;
	}
}
int main(int argc, char* argv[])
{   
	int i, a[10] ={1, 2, 3, 4, 5, 6, 7, 8, 9, 0};   //��������
	cout << "��������Ԫ��:\n";
	for (i = 0; i < 10; i++)                        //�������
		cout << a[i] << " ";
	cout << endl;
	inverte(a, 10);                                  //ʹ����Ԫ������
	cout << "�����������Ԫ��:\n";
	for (i = 0; i < 10; i++)                         //������������
		cout << a[i] << " ";
	cout << endl;

	getchar();
	return 0;
}