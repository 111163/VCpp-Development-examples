
// �б�����ݽ���.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�б�����ݽ���App:
// �йش����ʵ�֣������ �б�����ݽ���.cpp
//

class C�б�����ݽ���App : public CWinApp
{
public:
	C�б�����ݽ���App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�б�����ݽ���App theApp;