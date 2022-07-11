// PrintDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "对话框调用文档视图(打印).h"
#include "PrintDlg.h"
#include "afxdialogex.h"


extern CString str1[9];
// CPrintDlg 对话框

IMPLEMENT_DYNAMIC(CPrintDlg, CDialog)

CPrintDlg::CPrintDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrintDlg::IDD, pParent)
{

}

CPrintDlg::~CPrintDlg()
{
}

void CPrintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
}


BEGIN_MESSAGE_MAP(CPrintDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CPrintDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CPrintDlg 消息处理程序


BOOL CPrintDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	str1[0] = "满江红";
	str1[1] = "怒发冲冠，凭栏处，潇潇雨歇。";
	str1[2] = "抬望眼，仰天长啸，壮怀激烈。";
	str1[3] = "三十功名尘于土，八千里路云和月。";
	str1[4] = "莫等闲，白了少年头，空悲切。";
	str1[5] = "靖康耻，由未雪，臣子恨，何时灭。";
	str1[6] = "驾长车，踏破贺兰山缺。";
	str1[7] = "壮士饥餐胡虏肉，笑谈渴饮匈奴血。";
	str1[8] = "待从头，收拾旧山河，朝天阙。";
	CString Text;
	Text = str1[0]+"\r\n"+str1[1]+"\r\n"+str1[2]+"\r\n"+str1[3]+"\r\n"+str1[4]+"\r\n";
	Text += str1[5]+"\r\n"+str1[6]+"\r\n"+str1[7]+"\r\n"+str1[8];
	m_Edit.SetWindowText(Text);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CPrintDlg::OnBnClickedButton1()
{
	theApp.m_pDocManager->OnFileNew();
	CDialog::OnCancel();
}
