// TextDll.h : TextDll DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTextDllApp
// �йش���ʵ�ֵ���Ϣ������� TextDll.cpp
//

class CTextDllApp : public CWinApp
{
public:
	CTextDllApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
