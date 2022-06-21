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
			HDC hDC = BeginPaint(hWnd, &ps);//��ʼ��ͼ
			SetBkMode(hDC, TRANSPARENT);//���ñ�����ͼģʽ
			SetTextColor(hDC, RGB(0x33, 0xcc, 0));//�����ı���ɫ
			char *str = "XXX����Ļ��������";//������ʾ�ַ���
			TextOut(hDC, 150, 150, str, strlen(str));//�����ַ���
			EndPaint(hWnd, &ps);//���ٻ�ͼ
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;         
	default:
		// ȱʡ����Ϣ������
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