#include <stdio.h>
#include <iostream>
using namespace std;

void Sort(int (&nArray)[5])                      //����һ����������ʹ������������Ϊ����
{
	int nTmp = 0;                                     //����һ����ʱ����
	for(int i=0; i<5; i++)                            //����ð�ݷ�����
	{
		for(int j=0; j<5-1;j++)
		{
			if (nArray[j]>nArray[j+1])               //��������Ԫ��
			{
				nTmp = nArray[j];
				nArray[j] = nArray[j+1];
				nArray[j+1] = nTmp;
			}
		}
	}
	cout << "����֮��" <<endl;
	for(int i=0; i<5; i++)                                 //��������Ľ��
	{
		cout << nArray[i] << endl;
	}
}

int main(_In_ int _Argc, _In_count_(_Argc) _Pre_z_ char ** _Argv, _In_z_ char ** _Env)
{
	int nList[] = {78, 98, 75, 86, 78};                 //����6��Ԫ�ص���������
	Sort(nList);                                             //�﷨���󣬲��ܹ�����
	return 0;
}