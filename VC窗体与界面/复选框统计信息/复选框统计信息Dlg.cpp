
// ��ѡ��ͳ����ϢDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ѡ��ͳ����Ϣ.h"
#include "��ѡ��ͳ����ϢDlg.h"
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


// C��ѡ��ͳ����ϢDlg �Ի���




C��ѡ��ͳ����ϢDlg::C��ѡ��ͳ����ϢDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C��ѡ��ͳ����ϢDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C��ѡ��ͳ����ϢDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHINA, m_ConChi);
	DDX_Control(pDX, IDC_ENG, m_ConEng);
	DDX_Control(pDX, IDC_F, m_ConF);
	DDX_Control(pDX, IDC_G, m_ConG);
	DDX_Control(pDX, IDC_HUA, m_ConHua);
	DDX_Control(pDX, IDC_JNP, m_ConJnp);
	DDX_Control(pDX, IDC_MATH, m_ConMat);
	DDX_Control(pDX, IDC_PHY, m_ConPhy);
}

BEGIN_MESSAGE_MAP(C��ѡ��ͳ����ϢDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C��ѡ��ͳ����ϢDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C��ѡ��ͳ����ϢDlg ��Ϣ�������

BOOL C��ѡ��ͳ����ϢDlg::OnInitDialog()
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
	m_ConChi.SetCheck(1);
	m_ConChi.EnableWindow(FALSE);
	m_ConMat.SetCheck(1);
	m_ConMat.EnableWindow(FALSE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C��ѡ��ͳ����ϢDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C��ѡ��ͳ����ϢDlg::OnPaint()
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
HCURSOR C��ѡ��ͳ����ϢDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C��ѡ��ͳ����ϢDlg::OnBnClickedButton1()
{
	CString ID, Name;
	GetDlgItem(IDC_NUM)->GetWindowText(ID);
	GetDlgItem(IDC_NAME)->GetWindowText(Name);

	CString str,text;
	str = "ѧ��:" +  ID + " ����:" + Name + "\r\n";
	m_ConChi.GetWindowText(text);str += "���޿�Ŀ:" + text + "��";
	m_ConMat.GetWindowText(text);str += text + "\r\n";
	
	str += "ѡ�޿�Ŀ:";

	for (int i = 0; i < 6; ++i)
	{
		CButton* but =(CButton*)GetDlgItem(IDC_ENG + i);
		if (but->GetCheck())
		{
			but->GetWindowText(text);
			str += text + "��"; 
		}
	}
	str = str.Left(str.GetLength()-2);
	
	MessageBox(str);
}
