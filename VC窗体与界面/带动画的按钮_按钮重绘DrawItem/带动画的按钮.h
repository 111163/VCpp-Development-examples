
// �������İ�ť.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�������İ�ťApp:
// �йش����ʵ�֣������ �������İ�ť.cpp
//

class C�������İ�ťApp : public CWinApp
{
public:
	C�������İ�ťApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�������İ�ťApp theApp;