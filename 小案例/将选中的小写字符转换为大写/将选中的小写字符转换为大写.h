
// 将选中的小写字符转换为大写.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// C将选中的小写字符转换为大写App:
// 有关此类的实现，请参阅 将选中的小写字符转换为大写.cpp
//

class C将选中的小写字符转换为大写App : public CWinApp
{
public:
	C将选中的小写字符转换为大写App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern C将选中的小写字符转换为大写App theApp;