
// �ļ���׼�Ի���.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�ļ���׼�Ի���App:
// �йش����ʵ�֣������ �ļ���׼�Ի���.cpp
//

class C�ļ���׼�Ի���App : public CWinApp
{
public:
	C�ļ���׼�Ի���App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�ļ���׼�Ի���App theApp;