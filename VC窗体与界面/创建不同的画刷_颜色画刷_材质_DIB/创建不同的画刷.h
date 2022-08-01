
// 创建不同的画刷.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// C创建不同的画刷App:
// 有关此类的实现，请参阅 创建不同的画刷.cpp
//

class C创建不同的画刷App : public CWinApp
{
public:
	C创建不同的画刷App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern C创建不同的画刷App theApp;