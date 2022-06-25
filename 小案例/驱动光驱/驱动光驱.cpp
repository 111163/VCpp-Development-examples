// 驱动光驱.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "CDManager.h"
#include <WinDef.h>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	cout << "弹出光驱1, 回退2, 退出系统其他"  << endl;
	cout << "请输入命令字符:";
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
		cout << "弹出光驱1, 回退2, 退出系统其他"  << endl;
		cout << "请输入命令字符:";
	}
	return 0;
}

