
// �Ի澲̬�ı�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�Ի澲̬�ı�App:
// �йش����ʵ�֣������ �Ի澲̬�ı�.cpp
//

class C�Ի澲̬�ı�App : public CWinApp
{
public:
	C�Ի澲̬�ı�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�Ի澲̬�ı�App theApp;