// ����ͼ����ʾ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Desktop.h"
#include <iostream>
using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	cout << "��������1, ��ʾ����2, ����������3, ��ʾ������4, �˳�ϵͳ����"  << endl;
	cout << "�����������ַ�:";
	while (true)
	{
		int  nCmd;
		cin >> nCmd;
		switch (nCmd)
		{
		case 1:
			{
				CDesktop::HideIcon();
				break;
			}
		case 2:
			{
				CDesktop::ShowIcon();
				break;
			}
		case 3:
			{
				CDesktop::HideTaskbar();
				break;
			}
		case 4:
			{
				CDesktop::ShowTaskbar();
				break;
			}
		default:
			{
				return 0;
			}

		}
		cout << "��������1, ��ʾ����2, ����������3, ��ʾ������4, �˳�ϵͳ0"  << endl;
		cout << "�����������ַ�:";
	}

	return 0;
}

