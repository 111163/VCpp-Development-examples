// SaftEdit.cpp : 实现文件
//

#include "stdafx.h"
#include "密码属性.h"
#include "SaftEdit.h"


// CSaftEdit

IMPLEMENT_DYNAMIC(CSaftEdit, CEdit)

CSaftEdit::CSaftEdit()
{
	m_bAllowed = FALSE;
}

CSaftEdit::~CSaftEdit()
{
}


BEGIN_MESSAGE_MAP(CSaftEdit, CEdit)
END_MESSAGE_MAP()



// CSaftEdit 消息处理程序




LRESULT CSaftEdit::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == WM_GETTEXT || message == EM_GETLINE)
	{
		if (!m_bAllowed)
		{
			return 0;
		}
	}
	return CEdit::DefWindowProc(message, wParam, lParam);
}
