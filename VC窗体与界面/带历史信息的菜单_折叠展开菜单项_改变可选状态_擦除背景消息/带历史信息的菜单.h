
// ����ʷ��Ϣ�Ĳ˵�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C����ʷ��Ϣ�Ĳ˵�App:
// �йش����ʵ�֣������ ����ʷ��Ϣ�Ĳ˵�.cpp
//

class C����ʷ��Ϣ�Ĳ˵�App : public CWinApp
{
public:
	C����ʷ��Ϣ�Ĳ˵�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C����ʷ��Ϣ�Ĳ˵�App theApp;