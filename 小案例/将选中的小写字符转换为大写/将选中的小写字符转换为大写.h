
// ��ѡ�е�Сд�ַ�ת��Ϊ��д.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C��ѡ�е�Сд�ַ�ת��Ϊ��дApp:
// �йش����ʵ�֣������ ��ѡ�е�Сд�ַ�ת��Ϊ��д.cpp
//

class C��ѡ�е�Сд�ַ�ת��Ϊ��дApp : public CWinApp
{
public:
	C��ѡ�е�Сд�ַ�ת��Ϊ��дApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C��ѡ�е�Сд�ַ�ת��Ϊ��дApp theApp;