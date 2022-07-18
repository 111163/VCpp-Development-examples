
// 使用组合框列举磁盘目录.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// C使用组合框列举磁盘目录App:
// 有关此类的实现，请参阅 使用组合框列举磁盘目录.cpp
//

class C使用组合框列举磁盘目录App : public CWinApp
{
public:
	C使用组合框列举磁盘目录App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern C使用组合框列举磁盘目录App theApp;