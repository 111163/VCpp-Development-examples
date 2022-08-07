
// SerializeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Serialize.h"
#include "SerializeDlg.h"
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


// CSerializeDlg �Ի���




CSerializeDlg::CSerializeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSerializeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSerializeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSerializeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_WRITE, &CSerializeDlg::OnBnClickedWrite)
	ON_BN_CLICKED(IDCREAD, &CSerializeDlg::OnBnClickedCread)
END_MESSAGE_MAP()


// CSerializeDlg ��Ϣ�������

BOOL CSerializeDlg::OnInitDialog()
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

void CSerializeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSerializeDlg::OnPaint()
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
HCURSOR CSerializeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSerializeDlg::OnBnClickedWrite()
{
	CSerialClass* serial = new CSerialClass;    // ΪʲôҪ��ô���أ���Ϊ���ݵ�����ָ�룬Ϊʲô������ָ���أ���ΪΪ�˱��⿽��������������ʧ
	serial->m_Data = 2008;
	serial->m_Text = "������ã�";
	CFile m_file;
	m_file.Open("SerialcClass.dat", CFile::modeCreate|CFile::modeWrite);
	CArchive ar(&m_file, CArchive::store);
	/*
	serial.Serialize(ar);  // ����Ƕ���Ļ���������ʹ�ã�ע���Ƕ��󣬲��Ƕ���ָ��   ʵ������������������  --�����ĵ�����������������������л����������ǿ�����MFC�����ĵ���Դ���п���������д��
	*/
	/*ar.Write(&serial, sizeof(serial));*/
	ar << serial;		  // ʵ���������Ǳ�������
	delete serial;
	serial = nullptr;
	ar.Close();
	m_file.Close();
}


void CSerializeDlg::OnBnClickedCread()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CSerialClass* serial = nullptr;     // ��������Ϊ�����л��ᶯ̬�Ĵ������󲢷��أ�������Ҫһ����ָ��
	CFile m_file;
	m_file.Open("SerialcClass.dat", CFile::modeRead);
	CArchive ar(&m_file, CArchive::load);
	/*
	serial.Serialize(ar);  // ����Ƕ���Ļ���������ʹ�ã�ע���Ƕ��󣬲��Ƕ���ָ�� ʵ������������������  --�����ĵ�����������������������л����������ǿ�����MFC�����ĵ���Դ���п���������д��
	*/
	ar >> serial;    // ʵ���������Ǳ������� ע�����ﷵ�ص���һ����̬�����Ķ����ָ�룬����Ҫ����ָ��
	CString tmp;
	tmp.Format("%d_%s", serial->m_Data, serial->m_Text);
	AfxMessageBox(tmp);
	delete serial;
	serial = nullptr;
	ar.Close();
	m_file.Close();
}
