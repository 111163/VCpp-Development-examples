
// �洢����λ��.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�洢����λ��App:
// �йش����ʵ�֣������ �洢����λ��.cpp
//

class C�洢����λ��App : public CWinApp
{
public:
	C�洢����λ��App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�洢����λ��App theApp;