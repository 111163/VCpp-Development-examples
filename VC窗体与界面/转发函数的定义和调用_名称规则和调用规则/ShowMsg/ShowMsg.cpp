// ShowMsg.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#define MATUREAPPROACH_EXPORTS
#include "ShowMsg.h"

void ShowMsg(char* pText)
{
	MessageBox(NULL, pText, "��ʾ", 0);
}
