
// ģ̬���ģ̬.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cģ̬���ģ̬App:
// �йش����ʵ�֣������ ģ̬���ģ̬.cpp
//

class Cģ̬���ģ̬App : public CWinApp
{
public:
	Cģ̬���ģ̬App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cģ̬���ģ̬App theApp;