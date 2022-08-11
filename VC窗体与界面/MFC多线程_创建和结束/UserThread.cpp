// UserThread.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC多线程.h"
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
	// TODO: 在此执行任意逐线程清理
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CUserThread, CWinThread)
END_MESSAGE_MAP()


// CUserThread 消息处理程序
