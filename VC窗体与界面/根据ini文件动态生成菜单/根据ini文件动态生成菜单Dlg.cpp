
// ����ini�ļ���̬���ɲ˵�Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ini�ļ���̬���ɲ˵�.h"
#include "����ini�ļ���̬���ɲ˵�Dlg.h"
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


// C����ini�ļ���̬���ɲ˵�Dlg �Ի���




C����ini�ļ���̬���ɲ˵�Dlg::C����ini�ļ���̬���ɲ˵�Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C����ini�ļ���̬���ɲ˵�Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C����ini�ļ���̬���ɲ˵�Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C����ini�ļ���̬���ɲ˵�Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// C����ini�ļ���̬���ɲ˵�Dlg ��Ϣ�������

BOOL C����ini�ļ���̬���ɲ˵�Dlg::OnInitDialog()
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
	m_cMenu.CreateMenu();
	CreateMenuFromFile();


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C����ini�ļ���̬���ɲ˵�Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C����ini�ļ���̬���ɲ˵�Dlg::OnPaint()
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
HCURSOR C����ini�ļ���̬���ɲ˵�Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void C����ini�ļ���̬���ɲ˵�Dlg::LoadSubMenu(CMenu* m_menu,CString str)
{
	CMenu m_tempmenu;
	m_tempmenu.CreatePopupMenu();
//	m_tempmenu.AppendMenu(MF_STRING,-1,str);
	_TCHAR buf[10240];
	CString strFilePath=".\\menu.ini";
	DWORD readlen=::GetPrivateProfileSection(str,buf,12040,strFilePath);
	_TCHAR *pbuf=buf;
	size_t size=strlen(pbuf);
	while(size)
	{
		CString strTmp(pbuf);
		CString strRight;
		int iRightPos=strTmp.Find("=");
		strRight=strTmp.Mid(iRightPos+1);
		m_tempmenu.AppendMenu(MF_STRING,-1,strRight);
		if(IsHaveSubMenu(strRight))//����Ŀ¼
			LoadSubMenu(&m_tempmenu,strRight);
		pbuf+=size+1;
		size=strlen(pbuf);
	}	
	m_cMenu.AppendMenu(MF_POPUP,(UINT)m_tempmenu.m_hMenu,str);
	m_tempmenu.Detach();
}



void C����ini�ļ���̬���ɲ˵�Dlg::CreateMenuFromFile(void)
{
	CString strFilePath=".\\menu.ini";
	CString strSectionName="mainmenu";
	_TCHAR buf[10240];
	DWORD readlen=::GetPrivateProfileSection(strSectionName,buf,12040,strFilePath);
	_TCHAR *pbuf=buf;
	size_t size=strlen(pbuf);
	while(size)
	{
		CString strTmp(pbuf);
		CString strRight;
		int iRightPos=strTmp.Find("=");
		strRight=strTmp.Mid(iRightPos+1);
		LoadSubMenu(&m_cMenu,strRight);		
		pbuf+=size+1;   // Խ����ǰ�Ⱥź�ֵ(��)
		size=strlen(pbuf);
	}	
	SetMenu(&m_cMenu);
}

BOOL C����ini�ļ���̬���ɲ˵�Dlg::IsHaveSubMenu(CString strSubMenu)
{
	CString strFilePath=".\\menu.ini";
	CString tmp;
	_TCHAR buf[10240];
	::GetPrivateProfileSectionNames(buf,10240,strFilePath);  // �õ����Ե�
	_TCHAR *pbuf=buf;
	size_t size=strlen(pbuf);
	while(size)
	{
		CString strTmp(pbuf);
		if(strTmp==strSubMenu)
			return true;
		pbuf+=size+1; // Խ���ַ�����/0
		size=strlen(pbuf);
	}	
	return false;
}
