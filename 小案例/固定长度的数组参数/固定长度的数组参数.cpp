#include <stdio.h>
#include <iostream>
using namespace std;

void Sort(int (&nArray)[5])                      //定义一个排序函数，使用数组引用作为参数
{
	int nTmp = 0;                                     //定义一个临时变量
	for(int i=0; i<5; i++)                            //利用冒泡法排序
	{
		for(int j=0; j<5-1;j++)
		{
			if (nArray[j]>nArray[j+1])               //交换数组元素
			{
				nTmp = nArray[j];
				nArray[j] = nArray[j+1];
				nArray[j+1] = nTmp;
			}
		}
	}
	cout << "排序之后" <<endl;
	for(int i=0; i<5; i++)                                 //输出排序后的结果
	{
		cout << nArray[i] << endl;
	}
}

int main(_In_ int _Argc, _In_count_(_Argc) _Pre_z_ char ** _Argv, _In_z_ char ** _Env)
{
	int nList[] = {78, 98, 75, 86, 78};                 //定义6个元素的整型数组
	Sort(nList);                                             //语法错误，不能够编译
	return 0;
}