
// ���ݲ˵����ɹ�����.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C���ݲ˵����ɹ�����App:
// �йش����ʵ�֣������ ���ݲ˵����ɹ�����.cpp
//

class C���ݲ˵����ɹ�����App : public CWinApp
{
public:
	C���ݲ˵����ɹ�����App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C���ݲ˵����ɹ�����App theApp;