
// ģ��ʱ��.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cģ��ʱ��App:
// �йش����ʵ�֣������ ģ��ʱ��.cpp
//

class Cģ��ʱ��App : public CWinApp
{
public:
	Cģ��ʱ��App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cģ��ʱ��App theApp;