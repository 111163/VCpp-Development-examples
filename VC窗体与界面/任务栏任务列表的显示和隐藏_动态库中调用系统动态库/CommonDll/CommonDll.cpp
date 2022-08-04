// CommonDll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#define MATUREAPPROACH_EXPORTS 
#include "CommonDll.h"
#include <stdio.h>

HWND GetTeskmanHwnd(void)
{
	typedef HWND (WINAPI * GetTeskHwnd)();
	HMODULE hModule = GetModuleHandle("user32.dll");
	GetTeskHwnd pGetTeskHWnd = (GetTeskHwnd)GetProcAddress(hModule, "GetTaskmanWindow");
	char Test[50] = {0};
	sprintf(Test, "0x%x", pGetTeskHWnd());
	MessageBox(NULL,Test, "测试", MB_OK);
	return ::GetParent(pGetTeskHWnd());
}

