// dlgModal.cpp : 实现文件
//

#include "stdafx.h"
#include "模态与非模态.h"
#include "dlgModal.h"
#include "afxdialogex.h"


// dlgModal 对话框

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


// dlgModal 消息处理程序


BOOL dlgModal::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_strEdit = "Hello World";
	UpdateData(FALSE);
	m_ConEdit.SetReadOnly(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void dlgModal::OnBnClickedOk()
{
	if (AfxMessageBox("模态-确定要退出吗？", MB_YESNO) == IDNO)
		return;
	EndDialog(5);
}


void dlgModal::OnBnClickedCancel()
{
	if (AfxMessageBox("模态-确定要退出吗？", MB_YESNO) == IDNO)
		return;
	CDialogEx::OnCancel();
}
