// PrintDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�Ի�������ĵ���ͼ(��ӡ).h"
#include "PrintDlg.h"
#include "afxdialogex.h"


extern CString str1[9];
// CPrintDlg �Ի���

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


// CPrintDlg ��Ϣ�������


BOOL CPrintDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	str1[0] = "������";
	str1[1] = "ŭ����ڣ�ƾ������������Ъ��";
	str1[2] = "̧���ۣ����쳤Х��׳�����ҡ�";
	str1[3] = "��ʮ��������������ǧ��·�ƺ��¡�";
	str1[4] = "Ī���У���������ͷ���ձ��С�";
	str1[5] = "�����ܣ���δѩ�����Ӻޣ���ʱ��";
	str1[6] = "�ݳ�����̤�ƺ���ɽȱ��";
	str1[7] = "׳ʿ���ͺ�²�⣬Ц̸������ūѪ��";
	str1[8] = "����ͷ����ʰ��ɽ�ӣ������ڡ�";
	CString Text;
	Text = str1[0]+"\r\n"+str1[1]+"\r\n"+str1[2]+"\r\n"+str1[3]+"\r\n"+str1[4]+"\r\n";
	Text += str1[5]+"\r\n"+str1[6]+"\r\n"+str1[7]+"\r\n"+str1[8];
	m_Edit.SetWindowText(Text);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CPrintDlg::OnBnClickedButton1()
{
	theApp.m_pDocManager->OnFileNew();
	CDialog::OnCancel();
}
