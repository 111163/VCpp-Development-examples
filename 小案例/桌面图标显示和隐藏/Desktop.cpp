#include "StdAfx.h"
#include "Desktop.h"
#include <Windows.h>

CDesktop::CDesktop(void)
{
}


CDesktop::~CDesktop(void)
{
}

void CDesktop::HideIcon()			//隐藏桌面图标
{
		HWND hDesktop = ::FindWindow("Progman", "Program Manager"); //查找桌面窗口
		if (hDesktop)
		{
			ShowWindow(hDesktop, SW_HIDE);
		}
}
void CDesktop::ShowIcon()
{
	// FindWindow这个函数检索处理顶级窗口的类名和窗口名称匹配指定的字符串。这个函数有两个参数，
	// 第一个是要找的窗口的类，第二个是要找的窗口的标题。在搜索的时候不一定两者都知道，但至少要知道其中的一个。

	HWND hDesktop = ::FindWindow("Progman", "Program Manager"); // Spy++ 先放到桌面上，找到桌面所属的类，找顶层父窗口
	if (hDesktop)												// 第一个参数是它所在的类，第二个参数是窗口名称，第二个窗口可能为空
	{
		::ShowWindow(hDesktop, SW_SHOW);
	}
}

void CDesktop::HideTaskbar()
{
	// SetWindowPos函数可更改子窗口、弹出窗口或顶级窗口的大小、位置和Z顺序。
	//	子窗口、弹出窗口和顶级窗口根据其在屏幕上的外观进行排序。最顶部的窗口接收最高的秩，并且是Z顺序中的第一个窗口。

	HWND hTaskbar = ::FindWindow("Shell_traywnd", NULL);
	if (hTaskbar)
	{
		::SetWindowPos(hTaskbar, HWND_TOPMOST, 0, 0, 0, 0, SWP_HIDEWINDOW);
	}
}

void CDesktop::ShowTaskbar()
{
	HWND hTaskbar = ::FindWindow("Shell_traywnd", NULL);
	if (hTaskbar)
	{
		::SetWindowPos(hTaskbar, HWND_TOPMOST, 0, 0, 0, 0, SWP_SHOWWINDOW);
	}
}