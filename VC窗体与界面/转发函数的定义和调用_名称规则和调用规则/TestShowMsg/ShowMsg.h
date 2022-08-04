#include "stdafx.h"

#ifdef MATUREAPPROACH_EXPORTS          // 解决导入导出问题
#define MATUREAPPROACH_API __declspec(dllexport)
#else
#define MATUREAPPROACH_API __declspec(dllimport)
#endif


#ifndef MATUREAPPROACH_EXPORTS  // 导出转发函数  参见.def中对转发函数的使用
extern "C" MATUREAPPROACH_API int WINAPI ShowM(HWND,LPCSTR,LPCSTR,UINT); // 命名规则 和 调用规则
#endif

MATUREAPPROACH_API void  ShowMsg(char* pText);


