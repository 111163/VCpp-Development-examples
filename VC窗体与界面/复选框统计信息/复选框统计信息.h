
// ��ѡ��ͳ����Ϣ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C��ѡ��ͳ����ϢApp:
// �йش����ʵ�֣������ ��ѡ��ͳ����Ϣ.cpp
//

class C��ѡ��ͳ����ϢApp : public CWinApp
{
public:
	C��ѡ��ͳ����ϢApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C��ѡ��ͳ����ϢApp theApp;