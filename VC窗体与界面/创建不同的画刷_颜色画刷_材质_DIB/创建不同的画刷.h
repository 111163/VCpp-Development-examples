
// ������ͬ�Ļ�ˢ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C������ͬ�Ļ�ˢApp:
// �йش����ʵ�֣������ ������ͬ�Ļ�ˢ.cpp
//

class C������ͬ�Ļ�ˢApp : public CWinApp
{
public:
	C������ͬ�Ļ�ˢApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C������ͬ�Ļ�ˢApp theApp;