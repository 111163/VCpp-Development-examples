// UserThread.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC���߳�.h"
#include "UserThread.h"
#include "Employee.h"


// CUserThread

IMPLEMENT_DYNCREATE(CUserThread, CWinThread)

CUserThread::CUserThread()
{
}

CUserThread::~CUserThread()
{
}

BOOL CUserThread::InitInstance()
{
	CEmployee EmEmployeeDlg; 
	EmEmployeeDlg.DoModal();
	return TRUE;
}

int CUserThread::ExitInstance()
{
	// TODO: �ڴ�ִ���������߳�����
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CUserThread, CWinThread)
END_MESSAGE_MAP()


// CUserThread ��Ϣ�������
