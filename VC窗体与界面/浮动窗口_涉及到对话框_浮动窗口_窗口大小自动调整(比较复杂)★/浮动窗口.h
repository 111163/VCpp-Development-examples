
// 浮动窗口.h : 浮动窗口 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// C浮动窗口App:
// 有关此类的实现，请参阅 浮动窗口.cpp
//

class C浮动窗口App : public CWinApp
{
public:
	C浮动窗口App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C浮动窗口App theApp;
