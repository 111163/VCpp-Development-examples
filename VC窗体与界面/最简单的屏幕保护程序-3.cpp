#define _CRT_SECURE_NO_WARNINGS
#define _AFXDLL
#include <afxwin.h>
#include <ScrnSave.h>
#include "resource.h"
#pragma comment(lib, "scrnsave.lib")
#pragma comment(lib,"ComCtl32.lib") 


//�������������ĺ���
LRESULT WINAPI ScreenSaverProc(HWND,UINT,WPARAM,LPARAM);
BOOL WINAPI ScreenSaverConfigureDialog(HWND,UINT,WPARAM,LPARAM);
BOOL WINAPI RegisterDialogClasses(HANDLE);
LRESULT WINAPI DefScreenSaverProc (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL WINAPI AboutDialog(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);

//����ȫ�ֱ���
char szIniFileName[]="�ҵ�����.ini";
//��Ļ���������������ݴ����control.ini�ļ�
char szSection[32];
//��Ļ������������������control.ini�ļ�λ��������
char szEntry[]="Slide Text:";
//��Ļ����������������������
char SlideText[256];
//��Ļ���������������ݣ��������ı�����

//�������������ĺ���
LRESULT WINAPI ScreenSaverProc(HWND hWnd,UINT message, WPARAM wParam, LPARAM lParam)
{ 
	static HBITMAP hBmp;//λͼ���
	HDC hDC,hMemDC;//hMemDC���ڴ��豸������λͼ��
	RECT rc;
	static int xpos=0;
	static UINT timerID;

	CString time;
	CTime tim;


	switch (message)
	{
	case WM_CREATE:
		//�ļ�λ��������szSection��ֵΪ��ԴidsAPPName������hMainInstanceΪ
		//SCRNSAVE.LIB�������Ļ��������ʵ�����
		LoadString(hMainInstance,idsAPPName,szSection,sizeof(szSection));

		strcpy(SlideText,"��ӭʹ����Ļ��������!");
		//��control.ini�ļ���[Screen Saver.MySaver]�����������ݵ�SlideText
		GetPrivateProfileString(szSection,szEntry, SlideText,SlideText,sizeof(SlideText),szIniFileName); 
		//ȡλͼ
		hBmp=LoadBitmap(hMainInstance,MAKEINTRESOURCE(IDB_BITMAP1));
		timerID=SetTimer(hWnd,1,1000,NULL);
		break;

	case WM_ERASEBKGND:
		hDC=GetDC(hWnd);
		//��ʾλͼ
		hMemDC=CreateCompatibleDC(hDC);
		SelectObject(hMemDC,hBmp);
		SetRect(&rc,0,0,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN)-25);//
		BitBlt(hDC,rc.top,rc.left,rc.right,rc.bottom,hMemDC,rc.top,rc.left,SRCCOPY);
		//������У�Ϊ�ı���ʾ��׼����
		SetRect(&rc,0,GetSystemMetrics(SM_CYSCREEN)-25,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
		FillRect(hDC,&rc,(HBRUSH)GetStockObject(BLACK_BRUSH));
		ReleaseDC(hWnd,hDC);
		DeleteDC(hMemDC);
		return 1;

	case WM_TIMER:
		hDC=GetDC(hWnd);
		//�������
		SetRect(&rc,0,GetSystemMetrics(SM_CYSCREEN)-25,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
		FillRect(hDC,&rc,(HBRUSH)GetStockObject(BLACK_BRUSH));
		//����ı�
		SetTextColor(hDC,RGB(255*rand(),255*rand(),255*rand()));
		SetBkColor(hDC,RGB(0,0,0));


		//////////////////////////////////////////////////////////////////////////
		tim = CTime::GetCurrentTime();
		time = tim.Format("%Y-%m-%d %H:%M:%S %A");      //ע���Сд�����򱨴�
		//////////////////////////////////////////////////////////////////////////

		TextOut(hDC,xpos,GetSystemMetrics(SM_CYSCREEN)-25,time,time.GetLength()); // ���������̶�������������滻   SlideText,strlen(SlideText)
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
		strcpy(SlideText,"��ӭʹ����Ļ��������!");
		GetPrivateProfileString(szSection,szEntry,SlideText,SlideText,sizeof(SlideText),szIniFileName); 
		SetDlgItemText(hWnd,IDC_EDIT,SlideText);
		SetFocus(GetDlgItem(hWnd,IDC_EDIT));
		return FALSE;

	case WM_COMMAND:
		switch(wParam)
		{
		case IDOK:
			//ȡEDIT�ؼ��ı����ݲ�д��control.ini�ļ�
			GetDlgItemText(hWnd,IDC_EDIT,SlideText,sizeof(SlideText));
			WritePrivateProfileString(szSection,szEntry,SlideText,szIniFileName);
			EndDialog(hWnd,TRUE);
			return TRUE;

		case IDCANCEL:
			EndDialog(hWnd,FALSE);
			return TRUE;

		case IDABOUT:
			//����ABOUT�Ի���
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
//����������Ļ��������MySaver������Ļ���������ṩ�����öԻ���͹��ڶԻ��򣬲���ʹ����ͼ����ʾ�����߿��Խ��Լ�ϲ����ͼ��ӵ���Դ�С� 
//��һ������VS�н���32λӦ�ù���(��ѡMFC WIZARD EXE)��������Դ�ļ�MiniSaver.rc�� 
//��VC����������һͼ�꣬��IDΪID_APP�� 
//���ַ��������IDΪIDS_DESCRIPTION�ַ���"MiniSaver"������Ϊ�ַ������һ�����IDΪidsAPPName�ַ���"Screen Saver.MySaver"
//����IDΪIDB_BITMAP1��λͼ 
//����IDΪDLG_ABOUT�Ի��򡣽���һIDΪIDOK�İ�ť 
//����IDΪDLG_SCRNSAVECONFIGURE���˶Ի���ID��SCRNSAVE.H������ֻ��ΪDLG_SCRNSAVECONFIGURE��������IDΪIDC_EDIT��EDIT�ؼ���IDΪIDOK��IDCANCEL��IDABOUT�İ�ť��
//ֵ��ע�����RESOURCE.H�����ID_APP��DLG_SCRNSAVECONFIGURE������SCRNSAVE.HԤ�����ֵ��ͻ�����ֶ��ؽ�RESOURCE.H�е�ID_APP��Ϊ100��DLG_SCRNSAVECONFIGURE��Ϊ2003���ɡ�


