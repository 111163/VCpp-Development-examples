
// ���ƽ�����ɫ�Ŀ�����.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C���ƽ�����ɫ�Ŀ�����App:
// �йش����ʵ�֣������ ���ƽ�����ɫ�Ŀ�����.cpp
//

class C���ƽ�����ɫ�Ŀ�����App : public CWinApp
{
public:
	C���ƽ�����ɫ�Ŀ�����App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C���ƽ�����ɫ�Ŀ�����App theApp;