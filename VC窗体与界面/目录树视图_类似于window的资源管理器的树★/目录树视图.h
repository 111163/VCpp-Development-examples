
// Ŀ¼����ͼ.h : Ŀ¼����ͼ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CĿ¼����ͼApp:
// �йش����ʵ�֣������ Ŀ¼����ͼ.cpp
//

class CĿ¼����ͼApp : public CWinApp
{
public:
	CĿ¼����ͼApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CĿ¼����ͼApp theApp;
