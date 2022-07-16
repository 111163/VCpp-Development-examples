
// ����ת����Dlg.cpp : ʵ���ļ�
//
#define  _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "����ת����.h"
#include "����ת����Dlg.h"
#include "afxdialogex.h"

#define ADDNAME(s,q) s##q 


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


// C����ת����Dlg �Ի���




C����ת����Dlg::C����ת����Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C����ת����Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C����ת����Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_m1);
	DDX_Control(pDX, IDC_EDIT2, m_m2);
	DDX_Control(pDX, IDC_EDIT3, m_m3);
	DDX_Control(pDX, IDC_EDIT4, m_m4);
}

BEGIN_MESSAGE_MAP(C����ת����Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BUTTON1, IDC_BUTTON4, OnButtonClick)
END_MESSAGE_MAP()


// C����ת����Dlg ��Ϣ�������

BOOL C����ת����Dlg::OnInitDialog()
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
	m_m1.SetChange(2);
	m_m2.SetChange(8);
	m_m3.SetChange(10);
	m_m4.SetChange(16);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C����ת����Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C����ת����Dlg::OnPaint()
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
HCURSOR C����ת����Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void C����ת����Dlg::OnButtonClick(UINT nID)  
{
	CString str1;
	int i;
	char aa[50]={};
	int j[4] = {2, 8, 10, 16};
	GetDlgItem(nID - 4)->GetWindowText(str1); // ȫ����10���ƵĻ����Ͻ��У�ͨ�����ķ�ʽ��������չΪ2-36���Ƶ�
	i = strtol(str1, NULL, j[nID-4-1000]); str1.Format("%d", i);GetDlgItem(IDC_EDIT3)->SetWindowText(str1);
	_itoa(i, aa, 2);GetDlgItem(IDC_EDIT1)->SetWindowText(aa);
	_itoa(i, aa, 8);GetDlgItem(IDC_EDIT2)->SetWindowText(aa);
	_itoa(i, aa, 16);GetDlgItem(IDC_EDIT4)->SetWindowText(aa);
}
