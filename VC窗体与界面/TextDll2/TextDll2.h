// TextDll2.h : TextDll2 DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

#ifndef TEXT_DLL 
#define MYDLL __declspec(dllexport) 
#else
#define MYDLL __declspec(dllimport)
#endif

// CTextDll2App
// �йش���ʵ�ֵ���Ϣ������� TextDll2.cpp
//

class CTextDll2App : public CWinApp
{
public:
	CTextDll2App();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

MYDLL int AddInt(int var1, int var2);
MYDLL int SUBInt(int var1, int var2);