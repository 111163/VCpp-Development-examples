
// QQ��¼ʽ�û�ѡ���б�Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "QQ��¼ʽ�û�ѡ���б�.h"
#include "QQ��¼ʽ�û�ѡ���б�Dlg.h"
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


// CQQ��¼ʽ�û�ѡ���б�Dlg �Ի���




CQQ��¼ʽ�û�ѡ���б�Dlg::CQQ��¼ʽ�û�ѡ���б�Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CQQ��¼ʽ�û�ѡ���б�Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CQQ��¼ʽ�û�ѡ���б�Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_ConPw);
	DDX_Control(pDX, IDC_BUTTON1, m_ConLog);
	DDX_Control(pDX, IDC_BUTTON2, m_ConCel);
	DDX_Control(pDX, IDC_COMBOBOXEX1, m_ConUserNme);
}

BEGIN_MESSAGE_MAP(CQQ��¼ʽ�û�ѡ���б�Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CQQ��¼ʽ�û�ѡ���б�Dlg ��Ϣ�������

BOOL CQQ��¼ʽ�û�ѡ���б�Dlg::OnInitDialog()
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
	CString str[]={"Ǯ����","С����","��������","����","������˹","������","���"};
	m_ImageList.Create(16,16,ILC_COLOR24|ILC_MASK,1,0);		//�����б���ͼ����
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON1));		
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON2)); 		
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON3)); 		
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON4)); 		
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON5)); 		
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON6)); 		
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON7)); 		
							// �����൫��Ҫ�д���(���ݣ���񣬷���)���У�����ҪCreate����
	m_ConUserNme.SetImageList(&m_ImageList);  // ������Ͽ�ͼ���������
	for (int i = 0; i<7; ++i)
	{
		COMBOBOXEXITEM cbi;
		cbi.mask = CBEIF_IMAGE|CBEIF_INDENT|CBEIF_OVERLAY|
			CBEIF_SELECTEDIMAGE|CBEIF_TEXT;
		cbi.iItem 			= i;
		cbi.pszText 		= str[i].GetBuffer(0);	//�����б����ı�
		cbi.cchTextMax		= str[i].GetLength();	//�����ı���󳤶�
		cbi.iImage 			= i;
		cbi.iSelectedImage	= i;
		cbi.iOverlay 		= 0;
		cbi.iIndent 		= (0 & 0x03); 
		m_ConUserNme.InsertItem(&cbi);					//���ýڵ��(����ڵ��ǰ������ݣ�ͼ��λ�õȵ�) ��������-���ڵ�
	} 
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CQQ��¼ʽ�û�ѡ���б�Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CQQ��¼ʽ�û�ѡ���б�Dlg::OnPaint()
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
HCURSOR CQQ��¼ʽ�û�ѡ���б�Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


