
// �Զ����ӡԤ��������.h : �Զ����ӡԤ�������� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�Զ����ӡԤ��������App:
// �йش����ʵ�֣������ �Զ����ӡԤ��������.cpp
//

class C�Զ����ӡԤ��������App : public CWinApp
{
public:
	C�Զ����ӡԤ��������App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�Զ����ӡԤ��������App theApp;
