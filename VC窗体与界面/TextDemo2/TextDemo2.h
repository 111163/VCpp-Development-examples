
// TextDemo2.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTextDemo2App:
// �йش����ʵ�֣������ TextDemo2.cpp
//

class CTextDemo2App : public CWinApp
{
public:
	CTextDemo2App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTextDemo2App theApp;