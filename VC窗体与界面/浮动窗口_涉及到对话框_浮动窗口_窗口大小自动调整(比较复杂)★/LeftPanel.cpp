// LeftPanel.cpp : 实现文件
//

#include "stdafx.h"
#include "浮动窗口.h"
#include "LeftPanel.h"
#include "afxdialogex.h"


// CLeftPanel 对话框

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


// CLeftPanel 消息处理程序


void CLeftPanel::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()

	CRect clientRC;
	GetClientRect(clientRC);
	//CBrush brush(RGB(255,0,0));
	dc.FillRect(clientRC, NULL);
}
