// dlgNoModal.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ģ̬���ģ̬.h"
#include "dlgNoModal.h"
#include "afxdialogex.h"


// dlgNoModal �Ի���

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


// dlgNoModal ��Ϣ�������


BOOL dlgNoModal::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_strEdit = "Hello World";
	UpdateData(FALSE);
	m_ConEdit.SetReadOnly(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
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
	if (AfxMessageBox("��ģ̬-ȷ��Ҫ�˳���", MB_YESNO) == IDNO)
		return;	
	int a = 1;
	int b = 2;
	::SendMessage(GetParent()->GetSafeHwnd(), WM_USER_CLICKED_OK, a, b);
	DestroyWindow();
}


void dlgNoModal::OnCancel()
{
	if (AfxMessageBox("��ģ̬-ȷ��Ҫ�˳���", MB_YESNO) == IDNO)
		return;
	int a = 3;
	int b = 4;
	::SendMessage(GetParent()->GetSafeHwnd(), WM_USER_CLICKED_CANCEL, a, b);
	DestroyWindow();
}
