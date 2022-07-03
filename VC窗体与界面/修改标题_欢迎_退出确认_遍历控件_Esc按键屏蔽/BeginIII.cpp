// BeginIII.cpp : 实现文件
//

#include "stdafx.h"
#include "修改对话框标题.h"
#include "BeginIII.h"
#include "afxdialogex.h"


// BeginIII 对话框

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


// BeginIII 消息处理程序


BOOL BeginIII::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetTimer(1,1200,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void BeginIII::OnTimer(UINT_PTR nIDEvent)
{
	KillTimer(1);
	CDialogEx::OnCancel();
	CDialogEx::OnTimer(nIDEvent);
}

