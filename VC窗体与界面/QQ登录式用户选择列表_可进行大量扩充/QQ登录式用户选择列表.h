
// QQ��¼ʽ�û�ѡ���б�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CQQ��¼ʽ�û�ѡ���б�App:
// �йش����ʵ�֣������ QQ��¼ʽ�û�ѡ���б�.cpp
//

class CQQ��¼ʽ�û�ѡ���б�App : public CWinApp
{
public:
	CQQ��¼ʽ�û�ѡ���б�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CQQ��¼ʽ�û�ѡ���б�App theApp;