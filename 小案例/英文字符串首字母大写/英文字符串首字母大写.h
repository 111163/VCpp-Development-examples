
// Ӣ���ַ�������ĸ��д.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CӢ���ַ�������ĸ��дApp:
// �йش����ʵ�֣������ Ӣ���ַ�������ĸ��д.cpp
//

class CӢ���ַ�������ĸ��дApp : public CWinApp
{
public:
	CӢ���ַ�������ĸ��дApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CӢ���ַ�������ĸ��дApp theApp;