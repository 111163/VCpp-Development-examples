// BeginIII.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�޸ĶԻ������.h"
#include "BeginIII.h"
#include "afxdialogex.h"


// BeginIII �Ի���

IMPLEMENT_DYNAMIC(BeginIII, CDialogEx)

BeginIII::BeginIII(CWnd* pParent /*=NULL*/)
	: CDialogEx(BeginIII::IDD, pParent)
{

}

BeginIII::~BeginIII()
{
}

void BeginIII::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(BeginIII, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// BeginIII ��Ϣ�������


BOOL BeginIII::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetTimer(1,1200,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void BeginIII::OnTimer(UINT_PTR nIDEvent)
{
	KillTimer(1);
	CDialogEx::OnCancel();
	CDialogEx::OnTimer(nIDEvent);
}

