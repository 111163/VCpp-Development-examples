
// ����ini�ļ���̬���ɲ˵�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C����ini�ļ���̬���ɲ˵�App:
// �йش����ʵ�֣������ ����ini�ļ���̬���ɲ˵�.cpp
//

class C����ini�ļ���̬���ɲ˵�App : public CWinApp
{
public:
	C����ini�ļ���̬���ɲ˵�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C����ini�ļ���̬���ɲ˵�App theApp;