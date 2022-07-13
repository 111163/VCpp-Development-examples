
// ���ת��Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "���ת��.h"
#include "���ת��Dlg.h"
#include "afxdialogex.h"
#include <WinUser.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C���ת��Dlg �Ի���




C���ת��Dlg::C���ת��Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C���ת��Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_StrEdit2 = _T("");
}

void C���ת��Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_ConInp);
	//  DDX_Control(pDX, IDC_EDIT2, m_ConOut);
	//  DDX_Control(pDX, IDC_EDIT2, m_StrEdit2);
	DDX_Text(pDX, IDC_EDIT2, m_StrEdit2);
}

BEGIN_MESSAGE_MAP(C���ת��Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C���ת��Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C���ת��Dlg ��Ϣ�������

BOOL C���ת��Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CButton* bTn =(CButton*) GetDlgItem(IDC_BUTTON1);
	bTn->SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP2)));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C���ת��Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C���ת��Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C���ת��Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


CString C���ת��Dlg::Capitalization(CString str)
{
	str.Replace("0","��");
	str.Replace("1","Ҽ");
	str.Replace("2","��");
	str.Replace("3","��");
	str.Replace("4","��");
	str.Replace("5","��");
	str.Replace("6","½");
	str.Replace("7","��");
	str.Replace("8","��");
	str.Replace("9","��");
	return str;
}

void C���ת��Dlg::ChangeMoney(CString str,int num)
{
	CString string[30];
	CString rstr;
	for(int i=1;i<=num;i++)
	{
		rstr = str.Right(1);
		string[2*num-2*(i-1)-1] = Capitalization(rstr);
		str = str.Left(num-i);
		switch(i)
		{
		case 1:
			string[2*num-2*(i-1)] = "Ԫ";
			break;
		case 2:
		case 6:
		case 10:
			string[2*num-2*(i-1)] = "ʰ";
			break;
		case 3:
		case 7:
		case 11:
			string[2*num-2*(i-1)] = "��";
			break;
		case 4:
		case 8:
		case 12:
			string[2*num-2*(i-1)] = "Ǫ";
			break;
		case 5:
			string[2*num-2*(i-1)] = "��";
			break;
		case 9:
			string[2*num-2*(i-1)] = "��";
			break;
		}
	}
	for(int i=0;i<=2*num;i++)
		m_StrEdit2 += string[i];
}




void C���ת��Dlg::OnBnClickedButton1()
{
	m_StrEdit2 = "";
	CString str,lstr,rstr;
	CString string[4];
	string[1] = "��";
	string[3] = "��";
	m_ConInp.GetWindowText(str);
	int n,m;
	m = str.GetLength();
	n = str.Find('.',0);
	if(n == -1)
	{
		if(m > 12)
		{
			MessageBox("������Ľ��̫��");
			return;
		}
		ChangeMoney(str,m);
	}
	else
	{
		if(m > 12)
		{
			MessageBox("������Ľ��̫��");
			return;
		}
		lstr = str.Left(n);
		ChangeMoney(lstr,n);
		if(m-n == 3)
		{
			rstr = str.Right(2);
			lstr = rstr.Left(1);
			rstr = rstr.Right(1);
			string[0] = Capitalization(lstr);
			string[2] = Capitalization(rstr);
		}
		if(m-n == 2)
		{
			rstr = str.Right(1);
			string[0] = Capitalization(rstr);
		}
		for(int i=0;i<2*(m-n-1);i++)
			m_StrEdit2 += string[i];
	}
	UpdateData(FALSE);
}
