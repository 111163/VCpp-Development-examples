
// UserFile.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUserFileApp:
// �йش����ʵ�֣������ UserFile.cpp
//

class CUserFileApp : public CWinApp
{
public:
	CUserFileApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CUserFileApp theApp;