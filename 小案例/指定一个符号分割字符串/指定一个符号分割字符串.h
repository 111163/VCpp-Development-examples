
// ָ��һ�����ŷָ��ַ���.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cָ��һ�����ŷָ��ַ���App:
// �йش����ʵ�֣������ ָ��һ�����ŷָ��ַ���.cpp
//

class Cָ��һ�����ŷָ��ַ���App : public CWinApp
{
public:
	Cָ��һ�����ŷָ��ַ���App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cָ��һ�����ŷָ��ַ���App theApp;