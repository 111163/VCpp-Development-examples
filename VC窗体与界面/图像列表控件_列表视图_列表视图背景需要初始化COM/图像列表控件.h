
// ͼ���б�ؼ�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cͼ���б�ؼ�App:
// �йش����ʵ�֣������ ͼ���б�ؼ�.cpp
//

class Cͼ���б�ؼ�App : public CWinApp
{
public:
	Cͼ���б�ؼ�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cͼ���б�ؼ�App theApp;