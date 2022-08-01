// Input.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "���Ʊ�ͼ.h"
#include "Input.h"
#include "afxdialogex.h"


// CInput �Ի���

IMPLEMENT_DYNAMIC(CInput, CDialogEx)

CInput::CInput(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInput::IDD, pParent)
{

}

CInput::~CInput()
{
}

void CInput::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInput, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_SET, &CInput::OnBnClickedBtnSet)
END_MESSAGE_MAP()


// CInput ��Ϣ�������


void CInput::OnBnClickedBtnSet()
{
	GetDlgItem(IDC_ED_X)->GetWindowText(m_centerX);
	GetDlgItem(IDC_ED_Y)->GetWindowText(m_centerY);
	GetDlgItem(IDC_ED_RADIUS)->GetWindowText(m_radius);
	GetDlgItem(IDC_ED_STARTANGLE)->GetWindowText(m_startAngle);
	GetDlgItem(IDC_ED_ANGLE)->GetWindowText(m_sweepAngle);
	this->OnCancel();
}
