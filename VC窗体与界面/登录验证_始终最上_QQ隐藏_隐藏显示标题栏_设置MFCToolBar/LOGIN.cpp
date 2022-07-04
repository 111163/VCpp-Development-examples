// LOGIN.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��¼����2.h"
#include "LOGIN.h"
#include "afxdialogex.h"


// LOGIN �Ի���

IMPLEMENT_DYNAMIC(LOGIN, CDialogEx)

LOGIN::LOGIN(CWnd* pParent /*=NULL*/)
	: CDialogEx(LOGIN::IDD, pParent)
{

	m_strPassWd = _T("");
	m_strUserName = _T("");
}

LOGIN::~LOGIN()
{
}

void LOGIN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PASSWD, m_strPassWd);
	DDV_MaxChars(pDX, m_strPassWd, 6);
	DDX_Text(pDX, IDC_USERNAME, m_strUserName);
	DDV_MaxChars(pDX, m_strUserName, 10);
}


BEGIN_MESSAGE_MAP(LOGIN, CDialogEx)
	ON_BN_CLICKED(IDC_CLOSE1, &LOGIN::OnBnClickedClose1)
	ON_BN_CLICKED(IDC_LOGIN, &LOGIN::OnBnClickedLogin)
END_MESSAGE_MAP()


// LOGIN ��Ϣ�������


void LOGIN::OnBnClickedClose1()
{
	CDialogEx::OnCancel();
}




void LOGIN::OnBnClickedLogin()
{
	UpdateData(TRUE);
	if (m_strUserName.IsEmpty() || m_strPassWd.IsEmpty())
	{
		AfxMessageBox("�û��������벻��Ϊ��");
		return;
	}
	if (m_strUserName == "����" && m_strPassWd == "123456")
	{
		CDialogEx::OnOK();
		return;
	}
	else
	{
		m_strUserName = "";
		m_strPassWd = "";
		UpdateData(FALSE);
		return;
	}
}


BOOL LOGIN::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN && (pMsg->wParam == 13 || pMsg->wParam == 27))
		return NULL;
	return CDialogEx::PreTranslateMessage(pMsg);
}
