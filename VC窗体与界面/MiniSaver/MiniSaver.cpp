#define _CRT_SECURE_NO_WARNINGS
#define _AFXDLL
#include <afxwin.h>
#include <ScrnSave.h>
#include "resource.h"
#pragma comment(lib, "scrnsave.lib")
#pragma comment(lib,"ComCtl32.lib") 


//声明三个基本的函数
LRESULT WINAPI ScreenSaverProc(HWND,UINT,WPARAM,LPARAM);
BOOL WINAPI ScreenSaverConfigureDialog(HWND,UINT,WPARAM,LPARAM);
BOOL WINAPI RegisterDialogClasses(HANDLE);
LRESULT WINAPI DefScreenSaverProc (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL WINAPI AboutDialog(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);

//定义全局变量
char szIniFileName[]="我的屏保.ini";
//屏幕保护程序配置数据存放在control.ini文件
char szSection[32];
//屏幕保护程序配置数据在control.ini文件位置区名称
char szEntry[]="Slide Text:";
//屏幕保护程序配置数据项名称
char SlideText[256];
//屏幕保护程序配置数据，这里是文本内容

//定义三个基本的函数
LRESULT WINAPI ScreenSaverProc(HWND hWnd,UINT message, WPARAM wParam, LPARAM lParam)
{ 
	static HBITMAP hBmp;//位图句柄
	HDC hDC,hMemDC;//hMemDC是内存设备，缓存位图。
	RECT rc;
	static int xpos=0;
	static UINT timerID;

	CString time;
	CTime tim;


	switch (message)
	{
	case WM_CREATE:
		//文件位置区名称szSection赋值为资源idsAPPName。其中hMainInstance为
		//SCRNSAVE.LIB定义的屏幕保护程序实例句柄
		LoadString(hMainInstance,idsAPPName,szSection,sizeof(szSection));

		strcpy(SlideText,"欢迎使用屏幕保护程序!");
		//读control.ini文件中[Screen Saver.MySaver]区的配置数据到SlideText
		GetPrivateProfileString(szSection,szEntry, SlideText,SlideText,sizeof(SlideText),szIniFileName); 
		//取位图
		hBmp=LoadBitmap(hMainInstance,MAKEINTRESOURCE(IDB_BITMAP1));
		timerID=SetTimer(hWnd,1,1000,NULL);
		break;

	case WM_ERASEBKGND:
		hDC=GetDC(hWnd);
		//显示位图
		hMemDC=CreateCompatibleDC(hDC);
		SelectObject(hMemDC,hBmp);
		SetRect(&rc,0,0,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN)-25);//
		BitBlt(hDC,rc.top,rc.left,rc.right,rc.bottom,hMemDC,rc.top,rc.left,SRCCOPY);
		//清除底行，为文本显示作准备。
		SetRect(&rc,0,GetSystemMetrics(SM_CYSCREEN)-25,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
		FillRect(hDC,&rc,(HBRUSH)GetStockObject(BLACK_BRUSH));
		ReleaseDC(hWnd,hDC);
		DeleteDC(hMemDC);
		return 1;

	case WM_TIMER:
		hDC=GetDC(hWnd);
		//清除底行
		SetRect(&rc,0,GetSystemMetrics(SM_CYSCREEN)-25,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
		FillRect(hDC,&rc,(HBRUSH)GetStockObject(BLACK_BRUSH));
		//输出文本
		SetTextColor(hDC,RGB(255*rand(),255*rand(),255*rand()));
		SetBkColor(hDC,RGB(0,0,0));

		tim = CTime::GetCurrentTime();
		time = tim.Format("%Y-%m-%d %H:%M:%S %A");      //注意大小写，否则报错

		TextOut(hDC,xpos,GetSystemMetrics(SM_CYSCREEN)-25,time,time.GetLength()); //SlideText,strlen(SlideText)
		xpos=(xpos+10)%GetSystemMetrics(SM_CXSCREEN);
		ReleaseDC(hWnd,hDC);
		break;

	case WM_DESTROY:
		DeleteObject(hBmp);
		KillTimer(hWnd,timerID);
		PostQuitMessage (0);
		return 0;
	}
	return DefScreenSaverProc
		(hWnd,message,wParam,lParam);
}

BOOL WINAPI ScreenSaverConfigureDialog(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{ 
	switch (message)
	{
	case WM_INITDIALOG:
		LoadString(hMainInstance,idsAPPName,szSection,sizeof(szSection));
		strcpy(SlideText,"欢迎使用屏幕保护程序!");
		GetPrivateProfileString(szSection,szEntry,SlideText,SlideText,sizeof(SlideText),szIniFileName); 
		SetDlgItemText(hWnd,IDC_EDIT,SlideText);
		SetFocus(GetDlgItem(hWnd,IDC_EDIT));
		return FALSE;

	case WM_COMMAND:
		switch(wParam)
		{
		case IDOK:
			//取EDIT控件文本数据并写入control.ini文件
			GetDlgItemText(hWnd,IDC_EDIT,SlideText,sizeof(SlideText));
			WritePrivateProfileString(szSection,szEntry,SlideText,szIniFileName);
			EndDialog(hWnd,TRUE);
			return TRUE;

		case IDCANCEL:
			EndDialog(hWnd,FALSE);
			return TRUE;

		case IDABOUT:
			//调用ABOUT对话框
			DialogBox(hMainInstance, MAKEINTRESOURCE(DLG_ABOUT),hWnd,AboutDialog);
			return TRUE;
		}
		break;
	}
	return FALSE;
}

BOOL WINAPI RegisterDialogClasses(HANDLE hInstance)
{
	return TRUE;
}

BOOL WINAPI AboutDialog(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{ 
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND:
		switch(wParam)
		{
		case IDOK:
			EndDialog(hWnd,TRUE);
			return TRUE;
		}
		break;
	}
	return FALSE;
}
//较完整的屏幕保护程序MySaver。该屏幕保护程序提供了配置对话框和关于对话框，并且使用了图象显示。读者可以将自己喜爱的图象加到资源中。 
//第一步，在VS中建立32位应用工程(不选MFC WIZARD EXE)并定义资源文件MiniSaver.rc。 
//在VC环境下生成一图标，其ID为ID_APP。 
//向字符串表加入ID为IDS_DESCRIPTION字符串"MiniSaver"，并作为字符串表第一项。加入ID为idsAPPName字符串"Screen Saver.MySaver"
//加入ID为IDB_BITMAP1的位图 
//加入ID为DLG_ABOUT对话框。仅有一ID为IDOK的按钮 
//加入ID为DLG_SCRNSAVECONFIGURE。此对话的ID由SCRNSAVE.H定义且只能为DLG_SCRNSAVECONFIGURE。其中有ID为IDC_EDIT的EDIT控件，ID为IDOK，IDCANCEL和IDABOUT的按钮。
//值得注意的是RESOURCE.H定义的ID_APP和DLG_SCRNSAVECONFIGURE可能与SCRNSAVE.H预定义的值冲突，可手动地将RESOURCE.H中的ID_APP设为100，DLG_SCRNSAVECONFIGURE设为2003即可。


