// dlgModal.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ģ̬���ģ̬.h"
#include "dlgModal.h"
#include "afxdialogex.h"


// dlgModal �Ի���

IMPLEMENT_DYNAMIC(dlgModal, CDialogEx)

dlgModal::dlgModal(CWnd* pParent /*=NULL*/)
	: CDialogEx(dlgModal::IDD, pParent)
{

	m_strEdit = _T("");
}

dlgModal::~dlgModal()
{
}

void dlgModal::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strEdit);
	DDX_Control(pDX, IDC_EDIT1, m_ConEdit);
}


BEGIN_MESSAGE_MAP(dlgModal, CDialogEx)
	ON_BN_CLICKED(IDOK, &dlgModal::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &dlgModal::OnBnClickedCancel)
END_MESSAGE_MAP()


// dlgModal ��Ϣ�������


BOOL dlgModal::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_strEdit = "Hello World";
	UpdateData(FALSE);
	m_ConEdit.SetReadOnly(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void dlgModal::OnBnClickedOk()
{
	if (AfxMessageBox("ģ̬-ȷ��Ҫ�˳���", MB_YESNO) == IDNO)
		return;
	EndDialog(5);
}


void dlgModal::OnBnClickedCancel()
{
	if (AfxMessageBox("ģ̬-ȷ��Ҫ�˳���", MB_YESNO) == IDNO)
		return;
	CDialogEx::OnCancel();
}
