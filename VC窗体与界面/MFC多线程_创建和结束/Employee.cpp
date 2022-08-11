// Employee.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC多线程.h"
#include "Employee.h"
#include "afxdialogex.h"


// CEmployee 对话框

IMPLEMENT_DYNAMIC(CEmployee, CDialogEx)

CEmployee::CEmployee(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEmployee::IDD, pParent)
{

}

CEmployee::~CEmployee()
{
}

void CEmployee::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEmployee, CDialogEx)
END_MESSAGE_MAP()


// CEmployee 消息处理程序
