// LeftPanel.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��������.h"
#include "LeftPanel.h"
#include "afxdialogex.h"


// CLeftPanel �Ի���

IMPLEMENT_DYNAMIC(CLeftPanel, CDialog)

CLeftPanel::CLeftPanel(CWnd* pParent /*=NULL*/)
	: CDialog(CLeftPanel::IDD, pParent)
{

}

CLeftPanel::~CLeftPanel()
{
}

void CLeftPanel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLeftPanel, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CLeftPanel ��Ϣ�������


void CLeftPanel::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()

	CRect clientRC;
	GetClientRect(clientRC);
	//CBrush brush(RGB(255,0,0));
	dc.FillRect(clientRC, NULL);
}
