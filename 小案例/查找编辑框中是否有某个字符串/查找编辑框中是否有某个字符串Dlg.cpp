
// ���ұ༭�����Ƿ���ĳ���ַ���Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "���ұ༭�����Ƿ���ĳ���ַ���.h"
#include "���ұ༭�����Ƿ���ĳ���ַ���Dlg.h"
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


// C���ұ༭�����Ƿ���ĳ���ַ���Dlg �Ի���




C���ұ༭�����Ƿ���ĳ���ַ���Dlg::C���ұ༭�����Ƿ���ĳ���ַ���Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C���ұ༭�����Ƿ���ĳ���ַ���Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strInput = _T("");
	m_strFind = _T("");
}

void C���ұ༭�����Ƿ���ĳ���ַ���Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INPUT, m_strInput);
	DDX_Text(pDX, IDC_FIND, m_strFind);
}

BEGIN_MESSAGE_MAP(C���ұ༭�����Ƿ���ĳ���ַ���Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C���ұ༭�����Ƿ���ĳ���ַ���Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C���ұ༭�����Ƿ���ĳ���ַ���Dlg ��Ϣ�������

BOOL C���ұ༭�����Ƿ���ĳ���ַ���Dlg::OnInitDialog()
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

void C���ұ༭�����Ƿ���ĳ���ַ���Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C���ұ༭�����Ƿ���ĳ���ַ���Dlg::OnPaint()
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
HCURSOR C���ұ༭�����Ƿ���ĳ���ַ���Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C���ұ༭�����Ƿ���ĳ���ַ���Dlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	CString tmp = m_strInput;
	int pos = tmp.Find("\r\n"), i = 0; // \r\n����Ϊһ���ַ�   ---- ����\r\n������[�����ݲ���]
	while (pos >= 0)
	{
		strArray.Add(tmp.Left(pos));  // ��ȷ����CStringArray�ַ�������
		tmp = tmp.Right(tmp.GetLength() - pos - 1);
		pos = tmp.Find("\r\n");
	}
	for (int j = 0; j < strArray.GetSize(); j++)
	{
		if (strArray.GetAt(j) == m_strFind)   // ����Ƚ�Ҳ������ !strArray.GetAt(j).Compare(m_strFind)   [��Ϊ���ʱ����0]          
		{
			AfxMessageBox("�ҵ���");
			return;
		}
	}
	AfxMessageBox("δ�ҵ�");
}
