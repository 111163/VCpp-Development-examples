// LOGIN.cpp : 实现文件
//

#include "stdafx.h"
#include "登录界面2.h"
#include "LOGIN.h"
#include "afxdialogex.h"


// LOGIN 对话框

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


// LOGIN 消息处理程序


void LOGIN::OnBnClickedClose1()
{
	CDialogEx::OnCancel();
}




void LOGIN::OnBnClickedLogin()
{
	UpdateData(TRUE);
	if (m_strUserName.IsEmpty() || m_strPassWd.IsEmpty())
	{
		AfxMessageBox("用户名或密码不能为空");
		return;
	}
	if (m_strUserName == "张三" && m_strPassWd == "123456")
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
