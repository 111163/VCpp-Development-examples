
// 提取字符串中汉字.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// C提取字符串中汉字App:
// 有关此类的实现，请参阅 提取字符串中汉字.cpp
//

class C提取字符串中汉字App : public CWinApp
{
public:
	C提取字符串中汉字App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern C提取字符串中汉字App theApp;