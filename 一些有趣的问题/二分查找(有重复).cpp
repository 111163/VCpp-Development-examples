#include <stdio.h>
#include <string>
#include <iomanip>
#include <string.h>
#include <conio.h>
using namespace std;


int main(int argc, char* argv[])
{  
	// ��ֵ
	int a[10] = {0},temp, num;
	for (int i = 0;i < 10 ;i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
	// ������
	for (int i = 0; i < 9;i++)
	{
		for (int j = i + 1;j < 10;j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	// ��ʾ�ź����
	cout<<"����Ҫ���ҵ����ݣ�"<<"\n";
	cin >> num;
	cout<<"������飺"<<"\n";
	for(int i=0;i<10;i++)
	{
		cout<< "a["<< i <<"]=" << a[i]<<"\t";
		if((i+1)%3 == 0)
			cout<<"\n";
	}
	cout<< endl;
	//���ֲ���(һ���ǻ����ź����)��ע�⿼���ظ�Ԫ��
	int left = 0, right = 9, mid, l = 0,r = 0, n = 0;
	while(left < right)
	{
		mid = (left + right)/ 2;
		if (a[mid] == num)
		{
			for(int i = mid ; i > left; i--)
			{
				if (a[i - 1] != a [i])break;
				l++;
			}
			for(int i = mid ; i < right; i++)
			{
				if ( a[i] != a[i + 1])break;
				r++;
			}	
			// ���ҵ�����
			n = l + r + 1;
			for (int i = mid - l; i <= mid + r ;i++)
			{
				cout << "Ҫ���ҵ�Ԫ���ǣ�" << "\n";
				cout << "a["<< i <<"]="<< num << "\n";
			}
			break;
		} 
		if (a[mid] > num)
			right = mid - 1;
		if (a[mid] < num)
			left = mid + 1;
	}
	if(0==n)
		cout<<"Ҫ���ҵ�Ԫ�ز����ڣ�"<<"\n";
	getchar();
	return 0;
}  