
// TestCommonDll.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTestCommonDllApp:
// �йش����ʵ�֣������ TestCommonDll.cpp
//

class CTestCommonDllApp : public CWinApp
{
public:
	CTestCommonDllApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTestCommonDllApp theApp;