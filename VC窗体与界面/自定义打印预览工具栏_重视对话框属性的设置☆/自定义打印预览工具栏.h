
// 自定义打印预览工具栏.h : 自定义打印预览工具栏 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// C自定义打印预览工具栏App:
// 有关此类的实现，请参阅 自定义打印预览工具栏.cpp
//

class C自定义打印预览工具栏App : public CWinApp
{
public:
	C自定义打印预览工具栏App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C自定义打印预览工具栏App theApp;
