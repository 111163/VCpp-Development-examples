
// �༭������ʱ�б��Ҳ��ʾ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�༭������ʱ�б��Ҳ��ʾApp:
// �йش����ʵ�֣������ �༭������ʱ�б��Ҳ��ʾ.cpp
//

class C�༭������ʱ�б��Ҳ��ʾApp : public CWinApp
{
public:
	C�༭������ʱ�б��Ҳ��ʾApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�༭������ʱ�б��Ҳ��ʾApp theApp;