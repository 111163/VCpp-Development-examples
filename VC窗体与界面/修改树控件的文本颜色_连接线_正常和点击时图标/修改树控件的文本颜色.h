
// �޸����ؼ����ı���ɫ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�޸����ؼ����ı���ɫApp:
// �йش����ʵ�֣������ �޸����ؼ����ı���ɫ.cpp
//

class C�޸����ؼ����ı���ɫApp : public CWinApp
{
public:
	C�޸����ؼ����ı���ɫApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�޸����ؼ����ı���ɫApp theApp;