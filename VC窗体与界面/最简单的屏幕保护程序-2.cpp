#include <Windows.h>
#include <ScrnSave.h>
#include "resource.h"
#pragma comment(lib, "scrnsave.lib")
#pragma comment(lib,"ComCtl32.lib") 


//声明三个基本的函数
LRESULT WINAPI ScreenSaverProc(HWND,UINT,WPARAM,LPARAM);
BOOL WINAPI ScreenSaverConfigureDialog(HWND,UINT,WPARAM,LPARAM);
BOOL WINAPI RegisterDialogClasses(HANDLE);
LRESULT WINAPI DefScreenSaverProc (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//定义三个基本的函数
LRESULT WINAPI ScreenSaverProc(HWND hWnd, UINT message, WPARAM wParam,LPARAM lParam)
{ 
	HDC hDC;
	RECT rc;
	static int xpos;//文本的横坐标
	static char SlideText[]="XXX制作的屏幕保护程序!";
	static UINT timerID;//定时器
	switch (message)
	{
	case WM_CREATE:
		xpos=0;
		timerID=SetTimer(hWnd,1,250,NULL);//设置定时器
		break;
	case WM_ERASEBKGND:
		//空操作，交由DefScreenSaverProc处理
		break;
	case WM_TIMER:
		hDC=GetDC(hWnd);
		//清屏
		SetRect(&rc,0,0,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
		FillRect(hDC,&rc,(HBRUSH)GetStockObject(BLACK_BRUSH));
		//输出文本
		SetTextColor(hDC,RGB(255*rand(),
			255*rand(),255*rand()));
		SetBkColor(hDC,RGB(0,0,0));
		TextOut(hDC,xpos,GetSystemMetrics(SM_CYSCREEN)/2,SlideText,strlen(SlideText));
		//移动文本的横坐标
		xpos=(xpos+10)%GetSystemMetrics(SM_CXSCREEN);
		ReleaseDC(hWnd,hDC);
		break;
	case WM_DESTROY:
		KillTimer(hWnd,timerID);//删除定时器
		PostQuitMessage(0);
		return 0;
		// 	default:
		// 		// 缺省的消息处理函数
		// 		return DefScreenSaverProc(hWnd,message,wParam,lParam);
	}
	return DefScreenSaverProc(hWnd,message,wParam,lParam);;
}

BOOL WINAPI ScreenSaverConfigureDialog(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{//暂时不需要配置对话框，仅返回FALSE
	return FALSE;
}

BOOL WINAPI RegisterDialogClasses(HANDLE hInst)//BOOL WINAPI RegisterDialogClasses(HINSTANCE hInstance)
{//一般不需要，仅返回TRUE
	return TRUE;
}


// 在window下建立这个程序，要注意找不到连接库的时候
// #pragma comment(lib, "scrnsave.lib")
// #pragma comment(lib,"ComCtl32.lib")
// #include "resource.h"在资源文件中要创建一个icon图标#define	ID_APP	100
// 创建一个字符串#define	IDS_DESCRIPTION	1
