
// ListBox�Ĳ���.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CListBox�Ĳ���App:
// �йش����ʵ�֣������ ListBox�Ĳ���.cpp
//

class CListBox�Ĳ���App : public CWinApp
{
public:
	CListBox�Ĳ���App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CListBox�Ĳ���App theApp;