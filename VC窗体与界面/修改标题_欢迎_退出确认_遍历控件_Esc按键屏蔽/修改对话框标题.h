
// �޸ĶԻ������.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�޸ĶԻ������App:
// �йش����ʵ�֣������ �޸ĶԻ������.cpp
//

class C�޸ĶԻ������App : public CWinApp
{
public:
	C�޸ĶԻ������App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�޸ĶԻ������App theApp;