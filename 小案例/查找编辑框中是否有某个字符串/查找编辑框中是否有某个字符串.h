
// ���ұ༭�����Ƿ���ĳ���ַ���.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C���ұ༭�����Ƿ���ĳ���ַ���App:
// �йش����ʵ�֣������ ���ұ༭�����Ƿ���ĳ���ַ���.cpp
//

class C���ұ༭�����Ƿ���ĳ���ַ���App : public CWinApp
{
public:
	C���ұ༭�����Ƿ���ĳ���ַ���App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C���ұ༭�����Ƿ���ĳ���ַ���App theApp;