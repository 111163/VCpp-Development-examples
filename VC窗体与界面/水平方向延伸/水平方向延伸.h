
// 水平方向延伸.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// C水平方向延伸App:
// 有关此类的实现，请参阅 水平方向延伸.cpp
//

class C水平方向延伸App : public CWinApp
{
public:
	C水平方向延伸App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern C水平方向延伸App theApp;