
// UserFileDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UserFile.h"
#include "UserFileDlg.h"
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


// CUserFileDlg �Ի���




CUserFileDlg::CUserFileDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CUserFileDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUserFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CUserFileDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CUserFileDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CUserFileDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CUserFileDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CUserFileDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CUserFileDlg ��Ϣ�������

BOOL CUserFileDlg::OnInitDialog()
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

void CUserFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CUserFileDlg::OnPaint()
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
HCURSOR CUserFileDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CUserFileDlg::OnBnClickedButton1()
{
	FILE* pFile = fopen("demo.txt", "w+t");
	if (pFile)
	{
		char *pchData = "BeiJing2008";
		fwrite(pchData, sizeof(char), strlen(pchData),pFile);
	}
	fflush(pFile);
	fclose(pFile);
}


void CUserFileDlg::OnBnClickedButton2()
{
	FILE* pFile = fopen("demo.txt", "r");
	if (pFile)
	{
		char pchData[MAX_PATH] = {0};
		fread(pchData, sizeof(char), MAX_PATH, pFile);
		MessageBox(pchData);
	}
	fclose(pFile);
}


void CUserFileDlg::OnBnClickedButton3()
{
	CFile file;
	file.Open("demo1.txt", CFile::modeCreate|CFile::modeWrite);
	file.Write("����֮·���������", sizeof("����֮·���������"));
	file.Flush();
	file.Close();
	file.Rename("demo1.txt", "demo2.txt");
}


void CUserFileDlg::OnBnClickedButton4()
{
	CFile file;
	file.Open("demo2.txt", CFile::modeRead);
	char strBuff[MAX_PATH] = {0};
	file.Read(strBuff, MAX_PATH);
	CFileStatus flstatus;
	file.GetStatus(flstatus);
	CString createtime = flstatus.m_ctime.Format("%Y-%m-%d %H:%M:%S");
	CString hint = "�ļ�����:";
	hint += strBuff;
	hint += "\n";
	hint += "����ʱ��:";
	hint += createtime;
	MessageBox(hint);
	file.Close();
	file.Remove("demo2.txt");
}
