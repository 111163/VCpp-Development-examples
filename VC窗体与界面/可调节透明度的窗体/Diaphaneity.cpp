#include "StdAfx.h"
#include "Diaphaneity.h"


CDiaphaneity::CDiaphaneity(void)
{
}


CDiaphaneity::~CDiaphaneity(void)
{
}


void CDiaphaneity::SetDiaphaneity(CWnd* pWnd, int num)
{
	//设置窗口拓展风格
	SetWindowLong(pWnd->GetSafeHwnd(), GWL_EXSTYLE,
		GetWindowLong(pWnd->GetSafeHwnd(), GWL_EXSTYLE)|0x80000);
	typedef BOOL (WINAPI *FSetLayeredWindowAttributes)(HWND,COLORREF,BYTE,DWORD);
	FSetLayeredWindowAttributes SetLayeredWindowAttributes;
	HINSTANCE hInst = LoadLibrary("User32.DLL");
	SetLayeredWindowAttributes = (FSetLayeredWindowAttributes)
		GetProcAddress(hInst, "SetLayeredWindowAttributes");
	if (SetLayeredWindowAttributes)
		SetLayeredWindowAttributes(pWnd->GetSafeHwnd(), RGB(0,0,0), 95+num, 2);
	FreeLibrary(hInst);
}
