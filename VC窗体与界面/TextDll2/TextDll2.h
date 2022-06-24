// TextDll2.h : TextDll2 DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号

#ifndef TEXT_DLL 
#define MYDLL __declspec(dllexport) 
#else
#define MYDLL __declspec(dllimport)
#endif

// CTextDll2App
// 有关此类实现的信息，请参阅 TextDll2.cpp
//

class CTextDll2App : public CWinApp
{
public:
	CTextDll2App();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

MYDLL int AddInt(int var1, int var2);
MYDLL int SUBInt(int var1, int var2);