
// ��ȡ�ַ����к���.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C��ȡ�ַ����к���App:
// �йش����ʵ�֣������ ��ȡ�ַ����к���.cpp
//

class C��ȡ�ַ����к���App : public CWinApp
{
public:
	C��ȡ�ַ����к���App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C��ȡ�ַ����к���App theApp;