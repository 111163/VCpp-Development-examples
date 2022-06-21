#include "stdafx.h"
#include <ScrnSave.h>
#pragma comment(lib, "scrnsave.lib")

LRESULT CALLBACK ScreenSaverProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) 
	{
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hDC = BeginPaint(hWnd, &ps);//开始绘图
			SetBkMode(hDC, TRANSPARENT);//设置背景绘图模式
			SetTextColor(hDC, RGB(0x33, 0xcc, 0));//设置文本颜色
			char *str = "XXX，屏幕保护程序！";//屏保显示字符串
			TextOut(hDC, 150, 150, str, strlen(str));//绘制字符串
			EndPaint(hWnd, &ps);//结速绘图
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;         
	default:
		// 缺省的消息处理函数
		return DefScreenSaverProc(hWnd,message,wParam,lParam);
	}
	return 0;
}
BOOL WINAPI ScreenSaverConfigureDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	return FALSE;
}
BOOL WINAPI RegisterDialogClasses(HANDLE hInst)
{
	return TRUE;
}