
// ˮƽ��������.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cˮƽ��������App:
// �йش����ʵ�֣������ ˮƽ��������.cpp
//

class Cˮƽ��������App : public CWinApp
{
public:
	Cˮƽ��������App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cˮƽ��������App theApp;