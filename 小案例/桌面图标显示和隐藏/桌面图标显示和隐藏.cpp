// 桌面图标显示和隐藏.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Desktop.h"
#include <iostream>
using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	cout << "隐藏桌面1, 显示桌面2, 隐藏任务栏3, 显示任务栏4, 退出系统其他"  << endl;
	cout << "请输入命令字符:";
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
		cout << "隐藏桌面1, 显示桌面2, 隐藏任务栏3, 显示任务栏4, 退出系统0"  << endl;
		cout << "请输入命令字符:";
	}

	return 0;
}

