
// �Ի�������ĵ���ͼ(��ӡ).h : �Ի�������ĵ���ͼ(��ӡ) Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�Ի�������ĵ���ͼ��ӡApp:
// �йش����ʵ�֣������ �Ի�������ĵ���ͼ(��ӡ).cpp
//

class C�Ի�������ĵ���ͼ��ӡApp : public CWinApp
{
public:
	C�Ի�������ĵ���ͼ��ӡApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�Ի�������ĵ���ͼ��ӡApp theApp;


