
// ����ƴ������.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C����ƴ������App:
// �йش����ʵ�֣������ ����ƴ������.cpp
//

class C����ƴ������App : public CWinApp
{
public:
	C����ƴ������App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C����ƴ������App theApp;