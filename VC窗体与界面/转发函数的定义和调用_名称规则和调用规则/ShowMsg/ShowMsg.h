#include "stdafx.h"

#ifdef MATUREAPPROACH_EXPORTS          // ������뵼������
#define MATUREAPPROACH_API __declspec(dllexport)
#else
#define MATUREAPPROACH_API __declspec(dllimport)
#endif

//#ifndef MATUREAPPROACH_EXPORTS
//MATUREAPPROACH_API int ShowM(HWND,LPCSTR,LPCSTR,UINT);
//#endif

MATUREAPPROACH_API void  ShowMsg(char* pText);


