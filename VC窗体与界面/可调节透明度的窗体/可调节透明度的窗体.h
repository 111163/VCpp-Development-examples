
// �ɵ���͸���ȵĴ���.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�ɵ���͸���ȵĴ���App:
// �йش����ʵ�֣������ �ɵ���͸���ȵĴ���.cpp
//

class C�ɵ���͸���ȵĴ���App : public CWinApp
{
public:
	C�ɵ���͸���ȵĴ���App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�ɵ���͸���ȵĴ���App theApp;