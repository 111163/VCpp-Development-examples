
// ���л���ʵ��.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C���л���ʵ��App:
// �йش����ʵ�֣������ ���л���ʵ��.cpp
//

class C���л���ʵ��App : public CWinApp
{
public:
	C���л���ʵ��App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C���л���ʵ��App theApp;