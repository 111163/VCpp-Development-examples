
// �ڹ��λ�ü����ַ���.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�ڹ��λ�ü����ַ���App:
// �йش����ʵ�֣������ �ڹ��λ�ü����ַ���.cpp
//

class C�ڹ��λ�ü����ַ���App : public CWinApp
{
public:
	C�ڹ��λ�ü����ַ���App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�ڹ��λ�ü����ַ���App theApp;