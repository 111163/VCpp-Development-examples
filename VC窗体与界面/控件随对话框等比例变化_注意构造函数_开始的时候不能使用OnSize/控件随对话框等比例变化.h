
// �ؼ���Ի���ȱ����仯.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�ؼ���Ի���ȱ����仯App:
// �йش����ʵ�֣������ �ؼ���Ի���ȱ����仯.cpp
//

class C�ؼ���Ի���ȱ����仯App : public CWinApp
{
public:
	C�ؼ���Ի���ȱ����仯App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�ؼ���Ի���ȱ����仯App theApp;