
// ini�ļ��Ĳ���.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cini�ļ��Ĳ���App:
// �йش����ʵ�֣������ ini�ļ��Ĳ���.cpp
//

class Cini�ļ��Ĳ���App : public CWinApp
{
public:
	Cini�ļ��Ĳ���App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cini�ļ��Ĳ���App theApp;