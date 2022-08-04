#pragma once

#ifdef MATUREAPPROACH_EXPORTS          // 解决导入导出问题
#define MATUREAPPROACH_API __declspec(dllexport)
#else
#define MATUREAPPROACH_API __declspec(dllimport)
#endif


MATUREAPPROACH_API HWND GetTeskmanHwnd(void);
