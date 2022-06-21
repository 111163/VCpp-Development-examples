#include <Windows.h>
#include <ScrnSave.h>
#include "resource.h"
#pragma comment(lib, "scrnsave.lib")
#pragma comment(lib,"ComCtl32.lib") 


//�������������ĺ���
LRESULT WINAPI ScreenSaverProc(HWND,UINT,WPARAM,LPARAM);
BOOL WINAPI ScreenSaverConfigureDialog(HWND,UINT,WPARAM,LPARAM);
BOOL WINAPI RegisterDialogClasses(HANDLE);
LRESULT WINAPI DefScreenSaverProc (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//�������������ĺ���
LRESULT WINAPI ScreenSaverProc(HWND hWnd, UINT message, WPARAM wParam,LPARAM lParam)
{ 
	HDC hDC;
	RECT rc;
	static int xpos;//�ı��ĺ�����
	static char SlideText[]="XXX��������Ļ��������!";
	static UINT timerID;//��ʱ��
	switch (message)
	{
	case WM_CREATE:
		xpos=0;
		timerID=SetTimer(hWnd,1,250,NULL);//���ö�ʱ��
		break;
	case WM_ERASEBKGND:
		//�ղ���������DefScreenSaverProc����
		break;
	case WM_TIMER:
		hDC=GetDC(hWnd);
		//����
		SetRect(&rc,0,0,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
		FillRect(hDC,&rc,(HBRUSH)GetStockObject(BLACK_BRUSH));
		//����ı�
		SetTextColor(hDC,RGB(255*rand(),
			255*rand(),255*rand()));
		SetBkColor(hDC,RGB(0,0,0));
		TextOut(hDC,xpos,GetSystemMetrics(SM_CYSCREEN)/2,SlideText,strlen(SlideText));
		//�ƶ��ı��ĺ�����
		xpos=(xpos+10)%GetSystemMetrics(SM_CXSCREEN);
		ReleaseDC(hWnd,hDC);
		break;
	case WM_DESTROY:
		KillTimer(hWnd,timerID);//ɾ����ʱ��
		PostQuitMessage(0);
		return 0;
		// 	default:
		// 		// ȱʡ����Ϣ������
		// 		return DefScreenSaverProc(hWnd,message,wParam,lParam);
	}
	return DefScreenSaverProc(hWnd,message,wParam,lParam);;
}

BOOL WINAPI ScreenSaverConfigureDialog(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{//��ʱ����Ҫ���öԻ��򣬽�����FALSE
	return FALSE;
}

BOOL WINAPI RegisterDialogClasses(HANDLE hInst)//BOOL WINAPI RegisterDialogClasses(HINSTANCE hInstance)
{//һ�㲻��Ҫ��������TRUE
	return TRUE;
}


// ��window�½����������Ҫע���Ҳ������ӿ��ʱ��
// #pragma comment(lib, "scrnsave.lib")
// #pragma comment(lib,"ComCtl32.lib")
// #include "resource.h"����Դ�ļ���Ҫ����һ��iconͼ��#define	ID_APP	100
// ����һ���ַ���#define	IDS_DESCRIPTION	1
