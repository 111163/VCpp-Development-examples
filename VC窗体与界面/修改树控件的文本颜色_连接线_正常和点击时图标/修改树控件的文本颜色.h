
// 修改树控件的文本颜色.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// C修改树控件的文本颜色App:
// 有关此类的实现，请参阅 修改树控件的文本颜色.cpp
//

class C修改树控件的文本颜色App : public CWinApp
{
public:
	C修改树控件的文本颜色App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern C修改树控件的文本颜色App theApp;