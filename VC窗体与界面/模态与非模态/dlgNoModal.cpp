// dlgNoModal.cpp : 实现文件
//

#include "stdafx.h"
#include "模态与非模态.h"
#include "dlgNoModal.h"
#include "afxdialogex.h"


// dlgNoModal 对话框

IMPLEMENT_DYNAMIC(dlgNoModal, CDialogEx)

dlgNoModal::dlgNoModal(CWnd* pParent /*=NULL*/)
	: CDialogEx(dlgNoModal::IDD, pParent)
{

	m_strEdit = _T("");
}

dlgNoModal::~dlgNoModal()
{
}

void dlgNoModal::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strEdit);
	DDX_Control(pDX, IDC_EDIT1, m_ConEdit);
}


BEGIN_MESSAGE_MAP(dlgNoModal, CDialogEx)
	ON_BN_CLICKED(IDOK, &dlgNoModal::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &dlgNoModal::OnBnClickedCancel)
END_MESSAGE_MAP()


// dlgNoModal 消息处理程序


BOOL dlgNoModal::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_strEdit = "Hello World";
	UpdateData(FALSE);
	m_ConEdit.SetReadOnly(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void dlgNoModal::PostNcDestroy()
{
	CDialogEx::PostNcDestroy();
	delete this;
}


void dlgNoModal::OnBnClickedOk()
{
	OnOK();
}


void dlgNoModal::OnBnClickedCancel()
{
	OnCancel();
}


void dlgNoModal::OnOK()
{
	if (AfxMessageBox("非模态-确定要退出吗？", MB_YESNO) == IDNO)
		return;	
	int a = 1;
	int b = 2;
	::SendMessage(GetParent()->GetSafeHwnd(), WM_USER_CLICKED_OK, a, b);
	DestroyWindow();
}


void dlgNoModal::OnCancel()
{
	if (AfxMessageBox("非模态-确定要退出吗？", MB_YESNO) == IDNO)
		return;
	int a = 3;
	int b = 4;
	::SendMessage(GetParent()->GetSafeHwnd(), WM_USER_CLICKED_CANCEL, a, b);
	DestroyWindow();
}
