
// ���ε���.h : ���ε��� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C���ε���App:
// �йش����ʵ�֣������ ���ε���.cpp
//

class C���ε���App : public CWinApp
{
public:
	C���ε���App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C���ε���App theApp;
