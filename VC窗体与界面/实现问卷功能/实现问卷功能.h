
// ʵ���ʾ���.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cʵ���ʾ���App:
// �йش����ʵ�֣������ ʵ���ʾ���.cpp
//

class Cʵ���ʾ���App : public CWinApp
{
public:
	Cʵ���ʾ���App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cʵ���ʾ���App theApp;