
// �ĵ���ͼ�ṹʵ�ִ�ӡԤ��.h : �ĵ���ͼ�ṹʵ�ִ�ӡԤ�� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��App:
// �йش����ʵ�֣������ �ĵ���ͼ�ṹʵ�ִ�ӡԤ��.cpp
//

class C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��App : public CWinApp
{
public:
	C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��App theApp;
