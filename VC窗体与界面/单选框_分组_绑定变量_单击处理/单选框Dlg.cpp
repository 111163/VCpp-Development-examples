
// ��ѡ��Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ѡ��.h"
#include "��ѡ��Dlg.h"
#include "afxdialogex.h"

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


// C��ѡ��Dlg �Ի���




C��ѡ��Dlg::C��ѡ��Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C��ѡ��Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_ValFir = 0;
	m_VarSec = 0;
}

void C��ѡ��Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_RADIO1, m_ConFir);
	//  DDX_Control(pDX, IDC_RADIO5, m_ConSec);
	DDX_Radio(pDX, IDC_RADIO1, m_ValFir);
	DDX_Radio(pDX, IDC_RADIO5, m_VarSec);
}

BEGIN_MESSAGE_MAP(C��ѡ��Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &C��ѡ��Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &C��ѡ��Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &C��ѡ��Dlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &C��ѡ��Dlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &C��ѡ��Dlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &C��ѡ��Dlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO7, &C��ѡ��Dlg::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO8, &C��ѡ��Dlg::OnBnClickedRadio8)
	ON_BN_CLICKED(IDC_BUTTON1, &C��ѡ��Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C��ѡ��Dlg ��Ϣ�������

BOOL C��ѡ��Dlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C��ѡ��Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C��ѡ��Dlg::OnPaint()
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
HCURSOR C��ѡ��Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C��ѡ��Dlg::OnBnClickedRadio1()
{
	m_ValFir = 0;
	AfxMessageBox("m_ValFir");
}


void C��ѡ��Dlg::OnBnClickedRadio2()
{
	m_ValFir = 1;
	AfxMessageBox("m_ValFir");
}


void C��ѡ��Dlg::OnBnClickedRadio3()
{
	m_ValFir = 2;
	AfxMessageBox("m_ValFir");
}


void C��ѡ��Dlg::OnBnClickedRadio4()
{
	m_ValFir = 3;
	AfxMessageBox("m_ValFir");
}


void C��ѡ��Dlg::OnBnClickedRadio5()
{
	m_VarSec = 0;
}


void C��ѡ��Dlg::OnBnClickedRadio6()
{
	m_VarSec = 1;
	AfxMessageBox("m_VarSec");
}


void C��ѡ��Dlg::OnBnClickedRadio7()
{
	m_VarSec = 2;
	AfxMessageBox("m_VarSec");
}


void C��ѡ��Dlg::OnBnClickedRadio8()
{
	m_VarSec = 3;
	AfxMessageBox("m_VarSec");
}


void C��ѡ��Dlg::OnBnClickedButton1()
{
	CString str,text;
	CButton* but = (CButton*)GetDlgItem(IDC_RADIO1 + m_ValFir);
	but->GetWindowText(text);
	str += text + "\r\n";
	but = (CButton*)GetDlgItem(IDC_RADIO5 + m_VarSec);
	but->GetWindowText(text);
	str +=text;
	MessageBox(str);
}
