
// ���ư�ť.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C���ư�ťApp:
// �йش����ʵ�֣������ ���ư�ť.cpp
//

class C���ư�ťApp : public CWinApp
{
public:
	C���ư�ťApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C���ư�ťApp theApp;