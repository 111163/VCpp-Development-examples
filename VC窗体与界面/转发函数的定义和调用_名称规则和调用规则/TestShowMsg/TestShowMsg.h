
// TestShowMsg.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTestShowMsgApp:
// �йش����ʵ�֣������ TestShowMsg.cpp
//

class CTestShowMsgApp : public CWinApp
{
public:
	CTestShowMsgApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTestShowMsgApp theApp;