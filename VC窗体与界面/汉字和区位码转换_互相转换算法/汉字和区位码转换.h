
// ���ֺ���λ��ת��.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C���ֺ���λ��ת��App:
// �йش����ʵ�֣������ ���ֺ���λ��ת��.cpp
//

class C���ֺ���λ��ת��App : public CWinApp
{
public:
	C���ֺ���λ��ת��App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C���ֺ���λ��ת��App theApp;