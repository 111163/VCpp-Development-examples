
// 对话框调用文档视图(打印).h : 对话框调用文档视图(打印) 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// C对话框调用文档视图打印App:
// 有关此类的实现，请参阅 对话框调用文档视图(打印).cpp
//

class C对话框调用文档视图打印App : public CWinApp
{
public:
	C对话框调用文档视图打印App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C对话框调用文档视图打印App theApp;


