
// �Ӵ���ȡ���ִ�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�Ӵ���ȡ���ִ�App:
// �йش����ʵ�֣������ �Ӵ���ȡ���ִ�.cpp
//

class C�Ӵ���ȡ���ִ�App : public CWinApp
{
public:
	C�Ӵ���ȡ���ִ�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�Ӵ���ȡ���ִ�App theApp;