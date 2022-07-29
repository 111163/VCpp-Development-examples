
// �޸����ؼ����ı���ɫDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�޸����ؼ����ı���ɫ.h"
#include "�޸����ؼ����ı���ɫDlg.h"
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


// C�޸����ؼ����ı���ɫDlg �Ի���




C�޸����ؼ����ı���ɫDlg::C�޸����ؼ����ı���ɫDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C�޸����ؼ����ı���ɫDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C�޸����ؼ����ı���ɫDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C�޸����ؼ����ı���ɫDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// C�޸����ؼ����ı���ɫDlg ��Ϣ�������

BOOL C�޸����ؼ����ı���ɫDlg::OnInitDialog()
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
	m_TreeCtrl.Create(TVS_LINESATROOT |TVS_HASLINES |TVS_HASBUTTONS|WS_BORDER
		|LVS_SHOWSELALWAYS,CRect(0,0,0,0),this,10001);
	m_TreeCtrl.MoveWindow(10,10,200,300);                                           //���ÿؼ���ʾλ��
	m_TreeCtrl.ShowWindow(SW_SHOW);                                                     //��ʾ�ؼ�
	m_ImageList.Create(16, 16, ILC_COLOR24|ILC_MASK, 1, 1);
	m_ImageList.Add(LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON1))); // �� 0
	m_ImageList.Add(LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON2))); // �� 1
	m_ImageList.Add(LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON3))); // ʡ 2
	m_TreeCtrl.SetImageList(&m_ImageList, TVSIL_NORMAL);

	HTREEITEM hProvince = m_TreeCtrl.InsertItem("����ʡ",2,2);
	HTREEITEM hTown = m_TreeCtrl.InsertItem("��ԭ��", 0, 0, hProvince);
	m_TreeCtrl.InsertItem("�׳���", 0, 0, hProvince);
	m_TreeCtrl.InsertItem("������", 0, 0, hProvince);
	m_TreeCtrl.InsertItem("������", 0, 0, hProvince);
	m_TreeCtrl.InsertItem("������", 1, 1, hTown);
	m_TreeCtrl.InsertItem("ǰ����", 1, 1, hTown);
	m_TreeCtrl.InsertItem("������", 1, 1, hTown);
	m_TreeCtrl.InsertItem("ũ����", 1, 1, hTown);
	m_TreeCtrl.InsertItem("������", 1, 1, hTown);
	m_TreeCtrl.SetTextColor(RGB(255, 0, 0));		  //�����ı���ɫ
	m_TreeCtrl.SetLineColor(RGB(0,255,0));            //������������ɫ
	m_TreeCtrl.Expand(hProvince,TVE_EXPAND);          //չ�����ڵ�
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C�޸����ؼ����ı���ɫDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C�޸����ؼ����ı���ɫDlg::OnPaint()
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
HCURSOR C�޸����ؼ����ı���ɫDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

