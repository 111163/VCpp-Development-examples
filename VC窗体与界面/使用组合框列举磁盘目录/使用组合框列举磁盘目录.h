
// ʹ����Ͽ��оٴ���Ŀ¼.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cʹ����Ͽ��оٴ���Ŀ¼App:
// �йش����ʵ�֣������ ʹ����Ͽ��оٴ���Ŀ¼.cpp
//

class Cʹ����Ͽ��оٴ���Ŀ¼App : public CWinApp
{
public:
	Cʹ����Ͽ��оٴ���Ŀ¼App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cʹ����Ͽ��оٴ���Ŀ¼App theApp;