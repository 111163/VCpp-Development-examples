// ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "CDManager.h"
#include <WinDef.h>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	cout << "��������1, ����2, �˳�ϵͳ����"  << endl;
	cout << "�����������ַ�:";
	while(TRUE)
	{
		int nCmd;
		cin >> nCmd;
		switch (nCmd)
		{
		case 1:
			{
				CCDManager::PopCDRom();
							break;
			}
		case 2:
			{
				CCDManager::BackCDRom();
				break;
			}
		default:
			{
				return 0;
			}
		}
		cout << "��������1, ����2, �˳�ϵͳ����"  << endl;
		cout << "�����������ַ�:";
	}
	return 0;
}

