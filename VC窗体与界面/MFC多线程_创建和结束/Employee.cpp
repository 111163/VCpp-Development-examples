// Employee.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC���߳�.h"
#include "Employee.h"
#include "afxdialogex.h"


// CEmployee �Ի���

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


// CEmployee ��Ϣ�������
