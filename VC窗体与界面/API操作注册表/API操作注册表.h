
// API����ע���.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAPI����ע���App:
// �йش����ʵ�֣������ API����ע���.cpp
//

class CAPI����ע���App : public CWinApp
{
public:
	CAPI����ע���App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAPI����ע���App theApp;