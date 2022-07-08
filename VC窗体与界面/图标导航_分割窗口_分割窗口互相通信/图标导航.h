
// 图标导航.h : 图标导航 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// C图标导航App:
// 有关此类的实现，请参阅 图标导航.cpp
//

class C图标导航App : public CWinApp
{
public:
	C图标导航App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C图标导航App theApp;
