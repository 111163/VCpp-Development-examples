
// ini�ļ��Ĳ���Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ini�ļ��Ĳ���.h"
#include "ini�ļ��Ĳ���Dlg.h"
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


// Cini�ļ��Ĳ���Dlg �Ի���




Cini�ļ��Ĳ���Dlg::Cini�ļ��Ĳ���Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cini�ļ��Ĳ���Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cini�ļ��Ĳ���Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_IP);
	DDX_Control(pDX, IDC_EDIT2, m_Database);
	DDX_Control(pDX, IDC_EDIT3, m_UID);
	DDX_Control(pDX, IDC_EDIT4, m_PWD);
	DDX_Control(pDX, IDC_EDIT5, m_ID);
}

BEGIN_MESSAGE_MAP(Cini�ļ��Ĳ���Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cini�ļ��Ĳ���Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cini�ļ��Ĳ���Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// Cini�ļ��Ĳ���Dlg ��Ϣ�������

BOOL Cini�ļ��Ĳ���Dlg::OnInitDialog()
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
	CFileFind finder;
	if (!finder.FindFile(".\\xxx.ini"))   //��ѯ�ļ��Ƿ����Ҳ�Ǻ���Ҫ��һ������
	{
		WritePrivateProfileString("XXX", "IP", "192.168.0.0", ".\\xxx.ini");
		WritePrivateProfileString("XXX", "Database", "RoadNetData", ".\\xxx.ini");
		WritePrivateProfileString("XXX", "UID", "sa", ".\\xxx.ini");
		WritePrivateProfileString("XXX", "PWD", "4814278", ".\\xxx.ini");
		WritePrivateProfileString("XXX", "ID", "001", ".\\xxx.ini");
	}

	//////////////////////////////////////////////////////////////////////////
	// ��������ȫ��ȡ���ǿ��Գ��������һ��������
	CHAR bufName[256] = {0}, *pbufName = bufName; // memsetҲ���Գ�ʼ��
	int a = sizeof(bufName);
	CHAR bufSec[256] = {0}, *pbufSec = bufSec;
	GetPrivateProfileSectionNames(bufName, sizeof(bufName), ".\\xxx.ini");  // �õ� ��
	while(strcmp(pbufName, ""))
	{
		GetPrivateProfileSection(pbufName, bufSec, sizeof(bufSec), ".\\xxx.ini"); // �õ� key-value
		while(strcmp(pbufSec, ""))
		{
			CString tmp = pbufSec;
			CString m_key;
			int pos = tmp.Find("=");
			m_key = tmp.Left(pos);
			/*  // ��ȡ�����ԵĽ������еļ����ͼ�ֵ��ͨ�� = ���ּ���ֵ ֪���˽�
			CString m_value;
			m_value = tmp.Right(tmp.GetLength() - pos - 1);
			*/
			///// ͨ����ֱ�ӻ�ȡֵ(CString���͵�ֵ)  ---֪���˼���ȡֵ
			CHAR m_value[30];
			GetPrivateProfileString(pbufName, m_key, NULL, m_value , sizeof(m_value), ".\\xxx.ini");
			////
			if (m_key == "IP") m_IP.SetWindowText(m_value);
			if (m_key == "Database") m_Database.SetWindowText(m_value);
			if (m_key == "UID") m_UID.SetWindowText(m_value);
			if (m_key == "PWD") m_PWD.SetWindowText(m_value);
			if (m_key == "ID") m_ID.SetWindowText(m_value);

			if (m_key == "PWD")
			{
				int b = GetPrivateProfileInt(pbufName, m_key, -1, ".\\xxx.ini"); // ��ȡ�����֣�ʵ���Ϻ�ȡ�ü�ֵ��ֵ��ת������һ����
				CString tmpt;
				tmpt.Format("%d", b);
				AfxMessageBox(tmpt);
			}
			
			pbufSec += strlen(pbufSec) + 1;
		}

		pbufName += strlen(pbufName)+1;
	}

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Cini�ļ��Ĳ���Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cini�ļ��Ĳ���Dlg::OnPaint()
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
HCURSOR Cini�ļ��Ĳ���Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cini�ļ��Ĳ���Dlg::OnBnClickedButton1()
{
	CDialogEx::OnCancel();
}


void Cini�ļ��Ĳ���Dlg::OnBnClickedButton2() // �������á��޸�����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString tmp;
	m_IP.GetWindowText(tmp);
	WritePrivateProfileString("XXX", "IP", tmp, ".\\xxx.ini");
	m_Database.GetWindowText(tmp);
	WritePrivateProfileString("XXX", "Database", tmp, ".\\xxx.ini");
	m_UID.GetWindowText(tmp);
	WritePrivateProfileString("XXX", "UID", tmp, ".\\xxx.ini");
	m_PWD.GetWindowText(tmp);
	WritePrivateProfileString("XXX", "PWD", tmp, ".\\xxx.ini");
	m_ID.GetWindowText(tmp);
	WritePrivateProfileString("XXX", "ID", tmp, ".\\xxx.ini");
}
