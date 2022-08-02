
// ��֤������Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��֤������.h"
#include "��֤������Dlg.h"
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


// C��֤������Dlg �Ի���




C��֤������Dlg::C��֤������Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C��֤������Dlg::IDD, pParent)
{
	m_bNew = TRUE;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C��֤������Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECKPICTURE, m_CheckPicture);
}

BEGIN_MESSAGE_MAP(C��֤������Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ENTER, &C��֤������Dlg::OnBnClickedBtnEnter)
	ON_BN_CLICKED(IDC_BTN_EXIT, &C��֤������Dlg::OnBnClickedBtnExit)
END_MESSAGE_MAP()


// C��֤������Dlg ��Ϣ�������

BOOL C��֤������Dlg::OnInitDialog()
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

void C��֤������Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C��֤������Dlg::OnPaint()
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
		CPaintDC dc(this);
		CRect rc;
		if (m_bNew)
		{
			// m_strTemp = CreateRegionCode();
			m_strTemp = CreateRegionCode1();
			m_bNew = FALSE;
		}
		CFont font;
		font.CreatePointFont(200, "����");
		CFont *oldFont = dc.SelectObject(&font);
		m_CheckPicture.GetWindowRect(&rc);
		ScreenToClient(rc);
		dc.FillRect(rc, &CBrush(RGB(255, 255, 255))); // ����ɫ����
		dc.DrawText(m_strTemp, rc, DT_CENTER|DT_VCENTER); // д����
		//dc.TextOut(rc.left, rc.top, m_strTemp);
		dc.SelectObject(oldFont);
		font.DeleteObject();
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C��֤������Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C��֤������Dlg::OnBnClickedBtnEnter()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C��֤������Dlg::OnBnClickedBtnExit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

int n = 1;
CString C��֤������Dlg::CreateRegionCode()
{
	char buf[] = {'0', '1', '2','3','4','5','6','7','8','9',
		'a','b','c','d','e','f','g','h','i','j','k','l',
		'm','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int r1, r2, r3, r4;
	time_t t;
	n = time(&t);
	srand(n);
	r1 = rand()%36;
	r2 = rand()%36;
	r3 = rand()%36;
	r4 = rand()%36;
	CString str;
	str.Format("%c%c%c%c", buf[r1],buf[r2],buf[r3],buf[r4]);
	return str;
}

CString C��֤������Dlg::CreateRegionCode1()
{
	char buf[][3] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
		"a", "b", "c", "d", "e", "f" ,"g" ,"h" ,"i" ,"j" ,"k" ,"l",
		"m" ,"n" ,"o" ,"p" ,"q" ,"r" ,"s" ,"t" ,"u" ,"v" ,"w" ,"x" ,"y" ,"z",
		"��","��","��","��","��","��","��","��","��","ɴ"};
	int r1, r2, r3, r4;
	time_t t;
	n = time(&t);
	srand(n);
	r1 = rand()%46;
	r2 = rand()%46;
	r3 = rand()%46;
	r4 = rand()%46;
	CString str;
	str.Format("%s%s%s%s", buf[r1],buf[r2],buf[r3],buf[r4]); // ��ά����
	return str;
}

