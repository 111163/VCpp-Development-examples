
// �б�����ݽ���Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�б�����ݽ���.h"
#include "�б�����ݽ���Dlg.h"
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


// C�б�����ݽ���Dlg �Ի���




C�б�����ݽ���Dlg::C�б�����ݽ���Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C�б�����ݽ���Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C�б�����ݽ���Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RIGHT, m_ConBr);
	DDX_Control(pDX, IDC_LEFT, m_ConBl);
	DDX_Control(pDX, IDC_LEFTALL, m_ConBla);
	DDX_Control(pDX, IDC_RIGHTALL, m_ConBra);
	DDX_Control(pDX, IDC_LISTLEFT, m_ConLl);
	DDX_Control(pDX, IDC_LISTRIGHT, m_ConLr);
}

BEGIN_MESSAGE_MAP(C�б�����ݽ���Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RIGHT, &C�б�����ݽ���Dlg::OnBnClickedRight)
	ON_BN_CLICKED(IDC_LEFT, &C�б�����ݽ���Dlg::OnBnClickedLeft)
	ON_BN_CLICKED(IDC_RIGHTALL, &C�б�����ݽ���Dlg::OnBnClickedRightall)
	ON_BN_CLICKED(IDC_LEFTALL, &C�б�����ݽ���Dlg::OnBnClickedLeftall)
END_MESSAGE_MAP()


// C�б�����ݽ���Dlg ��Ϣ�������

BOOL C�б�����ݽ���Dlg::OnInitDialog()
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
	m_ConLl.AddString("����");
	m_ConLl.AddString("��ѧ");
	m_ConLl.AddString("Ӣ��");
	m_ConLl.AddString("����");
	m_ConLl.AddString("��ѧ");
	m_ConLl.AddString("��ʷ");
	m_ConLl.AddString("����");
	m_ConLl.AddString("����");
	m_ConLl.AddString("����");
	m_ConLl.AddString("�����");
	m_ConBr.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP4)));
	m_ConBl.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP2)));
	m_ConBra.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP5)));
	m_ConBla.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP3)));
	m_ConBl.EnableWindow(FALSE);
	m_ConBla.EnableWindow(FALSE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C�б�����ݽ���Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C�б�����ݽ���Dlg::OnPaint()
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
HCURSOR C�б�����ݽ���Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C�б�����ݽ���Dlg::OnBnClickedRight()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int  pos = m_ConLl.GetCurSel();
	if (pos < 0)
	{
		MessageBox("��ѡ��Ҫ�ƶ���ѡ��");
		return;
	}
	CString text;
	m_ConLl.GetText(pos,text);
	m_ConLl.DeleteString(pos);
	m_ConLr.AddString(text);
	m_ConBl.EnableWindow(TRUE);
	m_ConBla.EnableWindow(TRUE);
	if(m_ConLl.GetCount()==0)
	{
		m_ConBr.EnableWindow(FALSE);
		m_ConBra.EnableWindow(FALSE);
		return;
	}
	m_ConLl.SetCurSel(0);
}


void C�б�����ݽ���Dlg::OnBnClickedLeft()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int i=m_ConLr.GetCurSel();
	if(i<0)
	{
		MessageBox("��ѡ��Ҫ�ƶ���ѡ��");
		return;
	}
	CString text;
	m_ConLr.GetText(i,text);
	m_ConLr.DeleteString(i);
	m_ConLl.AddString(text);
	m_ConBr.EnableWindow(TRUE);
	m_ConBra.EnableWindow(TRUE);
	if(m_ConLr.GetCount()==0)
	{
		m_ConBl.EnableWindow(FALSE);
		m_ConBla.EnableWindow(FALSE);
		return;
	}
	m_ConLr.SetCurSel(0);
}


void C�б�����ݽ���Dlg::OnBnClickedRightall()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for (int i = 0;i<m_ConLl.GetCount();++i)
	{
		CString text;
		m_ConLl.GetText(i, text);
		m_ConLr.AddString(text);
	}
	m_ConLl.ResetContent();
	m_ConBl.EnableWindow(TRUE);
	m_ConBla.EnableWindow(TRUE);
	m_ConBr.EnableWindow(FALSE);
	m_ConBra.EnableWindow(FALSE);	
}


void C�б�����ݽ���Dlg::OnBnClickedLeftall()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for (int i = 0;i<m_ConLr.GetCount();++i)
	{
		CString text;
		m_ConLr.GetText(i, text);
		m_ConLl.AddString(text);
	}
	m_ConLr.ResetContent();
	m_ConBr.EnableWindow(TRUE);
	m_ConBra.EnableWindow(TRUE);
	m_ConBl.EnableWindow(FALSE);
	m_ConBla.EnableWindow(FALSE);	
}
