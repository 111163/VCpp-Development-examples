
// �Զ�����Ϣ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�Զ�����ϢApp:
// �йش����ʵ�֣������ �Զ�����Ϣ.cpp
//

class C�Զ�����ϢApp : public CWinApp
{
public:
	C�Զ�����ϢApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�Զ�����ϢApp theApp;