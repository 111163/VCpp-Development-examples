
// �����ݿ⶯̬���ɲ˵�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�����ݿ⶯̬���ɲ˵�App:
// �йش����ʵ�֣������ �����ݿ⶯̬���ɲ˵�.cpp
//

class C�����ݿ⶯̬���ɲ˵�App : public CWinApp
{
public:
	C�����ݿ⶯̬���ɲ˵�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern C�����ݿ⶯̬���ɲ˵�App theApp;