
// ���ݲ˵����ɹ�����Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "���ݲ˵����ɹ�����.h"
#include "���ݲ˵����ɹ�����Dlg.h"
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


// C���ݲ˵����ɹ�����Dlg �Ի���




C���ݲ˵����ɹ�����Dlg::C���ݲ˵����ɹ�����Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C���ݲ˵����ɹ�����Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C���ݲ˵����ɹ�����Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C���ݲ˵����ɹ�����Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND_RANGE(ID_32771, ID_32781, OnCom)
END_MESSAGE_MAP()


// C���ݲ˵����ɹ�����Dlg ��Ϣ�������

BOOL C���ݲ˵����ɹ�����Dlg::OnInitDialog()
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
	m_imagelist.Create(32,32,ILC_COLOR32|ILC_MASK,0,0);
	CString strpath;
	HICON hicon;
	for(int i = 0; i<10;++i)
	{
		strpath.Format(".\\res\\toolbar\\%02d.ico", i);
		hicon = (HICON)::LoadImage(NULL, strpath, IMAGE_ICON,32,32,LR_LOADFROMFILE);
		m_imagelist.Add(hicon);
	}
	m_toolbar.Create(WS_CHILD|WS_VISIBLE, CRect(0,0,0,0), this, 154230);
	m_toolbar.EnableAutomation();
	m_toolbar.SetImageList(&m_imagelist);
	m_Menu.LoadMenu(IDR_MENU1);
	TBBUTTON button[11];
	for (int i = 0; i<11; ++i)
	{
		button[i].dwData = 0;
		button[i].fsState = TBSTATE_ENABLED;
		button[i].fsStyle = TBSTYLE_BUTTON;
	}

	int iMenuButtonCount=0;
	MENUITEMINFO info;
	CString strMenuName;

	int coun = m_Menu.GetMenuItemCount(); // �õ��˵�Ԫ������
	for (int i =0; i<coun; ++i)
	{
		CMenu* m_tmpMenu = m_Menu.GetSubMenu(i);
		int coun1 = m_tmpMenu->GetMenuItemCount();
		for(int j = 0; j<coun1;++j)
		{
			m_tmpMenu->GetMenuString(i, strMenuName, MF_BYPOSITION);
			button[iMenuButtonCount].idCommand = m_tmpMenu->GetMenuItemID(j);
			button[iMenuButtonCount].iBitmap = iMenuButtonCount%9;
			button[iMenuButtonCount].iString =m_toolbar.AddStrings(strMenuName);
			iMenuButtonCount++;
			if (iMenuButtonCount>10)
				break;
		}
	}
	
	m_toolbar.AddButtons(iMenuButtonCount, button);
	m_toolbar.AutoSize();
	m_toolbar.SetStyle(TBSTYLE_FLAT|CCS_TOP);

	SetMenu(&m_Menu);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C���ݲ˵����ɹ�����Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C���ݲ˵����ɹ�����Dlg::OnPaint()
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
HCURSOR C���ݲ˵����ɹ�����Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void C���ݲ˵����ɹ�����Dlg::OnCom(UINT nID)
{
	CString tmp;
	tmp.Format("%d", nID);
	AfxMessageBox("�����"+tmp+ "����");
}

