#include "StdAfx.h"
#include "Desktop.h"
#include <Windows.h>

CDesktop::CDesktop(void)
{
}


CDesktop::~CDesktop(void)
{
}

void CDesktop::HideIcon()			//��������ͼ��
{
		HWND hDesktop = ::FindWindow("Progman", "Program Manager"); //�������洰��
		if (hDesktop)
		{
			ShowWindow(hDesktop, SW_HIDE);
		}
}
void CDesktop::ShowIcon()
{
	// FindWindow��������������������ڵ������ʹ�������ƥ��ָ�����ַ������������������������
	// ��һ����Ҫ�ҵĴ��ڵ��࣬�ڶ�����Ҫ�ҵĴ��ڵı��⡣��������ʱ��һ�����߶�֪����������Ҫ֪�����е�һ����

	HWND hDesktop = ::FindWindow("Progman", "Program Manager"); // Spy++ �ȷŵ������ϣ��ҵ������������࣬�Ҷ��㸸����
	if (hDesktop)												// ��һ�������������ڵ��࣬�ڶ��������Ǵ������ƣ��ڶ������ڿ���Ϊ��
	{
		::ShowWindow(hDesktop, SW_SHOW);
	}
}

void CDesktop::HideTaskbar()
{
	// SetWindowPos�����ɸ����Ӵ��ڡ��������ڻ򶥼����ڵĴ�С��λ�ú�Z˳��
	//	�Ӵ��ڡ��������ںͶ������ڸ���������Ļ�ϵ���۽�����������Ĵ��ڽ�����ߵ��ȣ�������Z˳���еĵ�һ�����ڡ�

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