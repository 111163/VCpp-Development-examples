
// �Ի���ҳ�����Ӿ�̬�ı�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�Ի���ҳ�����Ӿ�̬�ı�App:
// �йش����ʵ�֣������ �Ի���ҳ�����Ӿ�̬�ı�.cpp
//

class C�Ի���ҳ�����Ӿ�̬�ı�App : public CWinApp
{
public:
	C�Ի���ҳ�����Ӿ�̬�ı�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�Ի���ҳ�����Ӿ�̬�ı�App theApp;