
// ���ݵ����ͻ���ͼ��.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C���ݵ����ͻ���ͼ��App:
// �йش����ʵ�֣������ ���ݵ����ͻ���ͼ��.cpp
//

class C���ݵ����ͻ���ͼ��App : public CWinApp
{
public:
	C���ݵ����ͻ���ͼ��App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C���ݵ����ͻ���ͼ��App theApp;