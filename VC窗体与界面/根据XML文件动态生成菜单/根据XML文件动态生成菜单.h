
// 根据XML文件动态生成菜单.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// C根据XML文件动态生成菜单App:
// 有关此类的实现，请参阅 根据XML文件动态生成菜单.cpp
//

class C根据XML文件动态生成菜单App : public CWinApp
{
public:
	C根据XML文件动态生成菜单App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern C根据XML文件动态生成菜单App theApp;