
// ʹ����Ͽ��оٴ���Ŀ¼Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ʹ����Ͽ��оٴ���Ŀ¼.h"
#include "ʹ����Ͽ��оٴ���Ŀ¼Dlg.h"
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


// Cʹ����Ͽ��оٴ���Ŀ¼Dlg �Ի���




Cʹ����Ͽ��оٴ���Ŀ¼Dlg::Cʹ����Ͽ��оٴ���Ŀ¼Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cʹ����Ͽ��оٴ���Ŀ¼Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cʹ����Ͽ��оٴ���Ŀ¼Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBOBOXEX1, m_ComboEx);
}

BEGIN_MESSAGE_MAP(Cʹ����Ͽ��оٴ���Ŀ¼Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// Cʹ����Ͽ��оٴ���Ŀ¼Dlg ��Ϣ�������

BOOL Cʹ����Ͽ��оٴ���Ŀ¼Dlg::OnInitDialog()
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
	SHFILEINFO shInfo;
	memset(&shInfo,0,sizeof(SHFILEINFO));
	HIMAGELIST hImage = (HIMAGELIST)SHGetFileInfo("C:\\",0,&shInfo, sizeof( SHFILEINFO ),
		SHGFI_SYSICONINDEX | SHGFI_SMALLICON );
	m_ImageList.Attach(hImage); 
	LoadSysDisk();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Cʹ����Ͽ��оٴ���Ŀ¼Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cʹ����Ͽ��оٴ���Ŀ¼Dlg::OnPaint()
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
HCURSOR Cʹ����Ͽ��оٴ���Ŀ¼Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cʹ����Ͽ��оٴ���Ŀ¼Dlg::LoadSysDisk(void)
{
	m_ComboEx.SetImageList(&m_ImageList);
	m_ComboEx.ResetContent();
	char pchDrives[128] = {0};
	char* pchDrive;
	GetLogicalDriveStrings(sizeof(pchDrives), pchDrives);

	pchDrive = pchDrives;
	int nItem = 0;
	while (*pchDrive)
	{
		COMBOBOXEXITEM cbi;
		CString		 csText;
		cbi.mask = CBEIF_IMAGE|CBEIF_INDENT|CBEIF_OVERLAY|
			CBEIF_SELECTEDIMAGE|CBEIF_TEXT;

		SHFILEINFO shInfo;
		int nIcon;
		SHGetFileInfo(pchDrive, 0, &shInfo, sizeof(SHFILEINFO),
			SHGFI_ICON |SHGFI_SMALLICON);
		nIcon = shInfo.iIcon;

		cbi.iItem = nItem;
		cbi.pszText = pchDrive;
		cbi.cchTextMax = strlen(pchDrive);
		cbi.iImage = nIcon;
		cbi.iSelectedImage = nIcon;
		cbi.iOverlay = 0;
		cbi.iIndent = (0 & 0x03);
		m_ComboEx.InsertItem(&cbi);
		nItem++;
		pchDrive += strlen(pchDrive) + 1;
	}
}
