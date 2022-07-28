// ClogDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ͼ���б�ؼ�.h"
#include "ClogDlg.h"
#include "afxdialogex.h"
#include "Resource.h"


// ClogDlg �Ի���

IMPLEMENT_DYNAMIC(ClogDlg, CDialogEx)

ClogDlg::ClogDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ClogDlg::IDD, pParent)
{

}

ClogDlg::~ClogDlg()
{
}

void ClogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_LIST1, m_ImageList);
	DDX_Control(pDX, IDC_LIST1, m_Icon);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
}


BEGIN_MESSAGE_MAP(ClogDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ClogDlg::OnBnClickedButton1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &ClogDlg::OnNMClickList1)
END_MESSAGE_MAP()


// ClogDlg ��Ϣ�������


BOOL ClogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

 	m_ImageList.Create(32,32,ILC_COLOR24|ILC_MASK,1,0);
 	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
 	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
 	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON3));
 	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON4));
 	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON5));
 	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON6));
 	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON7));
 	m_Icon.SetImageList(&m_ImageList, LVSIL_NORMAL);
 	m_Icon.InsertItem(0,"��һ",0);
 	m_Icon.InsertItem(1,"����",1);
 	m_Icon.InsertItem(2,"����",2);
 	m_Icon.InsertItem(3,"����",3);
 	m_Icon.InsertItem(4,"����",4);
 	m_Icon.InsertItem(5,"����",5);
 	m_Icon.InsertItem(6,"����",6);
	n = 0;

	char buf[256];                                                         //�����ַ�����
	::GetCurrentDirectory(256,buf);                                        //��ó����Ŀ¼·��
	strcat(buf,"\\BK.bmp");                                             //����λͼ�ļ�·��
	m_Icon.SetBkImage(buf);                                                //����λͼ����
	m_Icon.SetTextBkColor(CLR_NONE);                             //�������ֱ���͸��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void ClogDlg::OnBnClickedButton1()
{
	CString tmpPw;
	m_Edit.GetWindowText(tmpPw);
	char a[256];
	m_Icon.GetItemText(n, 0, a, 256); // �õ��ı�
	CString tmp;
	tmp.Format("%d%d%d%d%d%d", n,n,n,n,n,n);
	tmp = tmp + " " + a;
	if (tmp != tmpPw)
	{
		AfxMessageBox(tmp + " " + "�������������" );
		return;
	}
	CDialogEx::OnOK();
}


void ClogDlg::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	n = m_Icon.GetSelectionMark();

	*pResult = 0;
}
