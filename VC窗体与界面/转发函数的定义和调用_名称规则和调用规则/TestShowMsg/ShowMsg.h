#include "stdafx.h"

#ifdef MATUREAPPROACH_EXPORTS          // ������뵼������
#define MATUREAPPROACH_API __declspec(dllexport)
#else
#define MATUREAPPROACH_API __declspec(dllimport)
#endif


#ifndef MATUREAPPROACH_EXPORTS  // ����ת������  �μ�.def�ж�ת��������ʹ��
extern "C" MATUREAPPROACH_API int WINAPI ShowM(HWND,LPCSTR,LPCSTR,UINT); // �������� �� ���ù���
#endif

MATUREAPPROACH_API void  ShowMsg(char* pText);


