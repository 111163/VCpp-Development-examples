
// MFCʹ��win32��̬��.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCʹ��win32��̬��App:
// �йش����ʵ�֣������ MFCʹ��win32��̬��.cpp
//

class CMFCʹ��win32��̬��App : public CWinApp
{
public:
	CMFCʹ��win32��̬��App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCʹ��win32��̬��App theApp;