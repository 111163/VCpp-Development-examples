
// �Զ�����Դ�Ĳ���.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�Զ�����Դ�Ĳ���App:
// �йش����ʵ�֣������ �Զ�����Դ�Ĳ���.cpp
//

class C�Զ�����Դ�Ĳ���App : public CWinApp
{
public:
	C�Զ�����Դ�Ĳ���App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�Զ�����Դ�Ĳ���App theApp;