
// �б������������Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�б������������.h"
#include "�б������������Dlg.h"
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


// C�б������������Dlg �Ի���




C�б������������Dlg::C�б������������Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C�б������������Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C�б������������Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ConListBox);
	DDX_Control(pDX, IDC_DOWN, m_ConDown);
	DDX_Control(pDX, IDC_UP, m_ConUp);
}

BEGIN_MESSAGE_MAP(C�б������������Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_UP, &C�б������������Dlg::OnBnClickedUp)
	ON_BN_CLICKED(IDC_DOWN, &C�б������������Dlg::OnBnClickedDown)
END_MESSAGE_MAP()


// C�б������������Dlg ��Ϣ�������

BOOL C�б������������Dlg::OnInitDialog()
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
	m_ConListBox.AddString("����������");
	m_ConListBox.AddString("������ɺ");
	m_ConListBox.AddString("�������������");
	m_ConListBox.AddString("���ﲻ֪���ǿ�");
	m_ConListBox.AddString("һ��̰��");
	m_ConListBox.AddString("����Īƾ��");
	m_ConListBox.AddString("���޽�ɽ");
	m_ConListBox.AddString("��ʱ���׼�ʱ��");
	m_ConListBox.AddString("��ˮ�仨��ȥҲ");
	m_ConListBox.AddString("�����˼�");

	m_ConUp.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP3)));
	m_ConDown.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP2)));
	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C�б������������Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C�б������������Dlg::OnPaint()
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
HCURSOR C�б������������Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C�б������������Dlg::OnBnClickedUp()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int pos = m_ConListBox.GetCurSel();
	if(pos < 0)
	{
		MessageBox("��ѡ��Ҫ�ƶ����ļ���");
		return;
	}
	if(pos == 0)								//�������Ϊ0
	{
		MessageBox("�Ѿ������ϱ��ˣ�");			//��ʾ�ǵ�һ���ļ�
		return;
	}
	CString Text;
	m_ConListBox.GetText(pos-1, Text);
	m_ConListBox.DeleteString(pos-1);
	m_ConListBox.InsertString(pos, Text);
}


void C�б������������Dlg::OnBnClickedDown()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int pos = m_ConListBox.GetCurSel();
	if(pos < 0)
	{
		MessageBox("��ѡ��Ҫ�ƶ����ļ���");
		return;
	}
	if(pos >= m_ConListBox.GetCount()-1)								//�������Ϊ���
	{
		MessageBox("�Ѿ������±��ˣ�");			//��ʾ�����һ���ļ�
		return;
	}
	CString Text;
	m_ConListBox.GetText(pos+1, Text);
	m_ConListBox.DeleteString(pos+1);
	m_ConListBox.InsertString(pos, Text);
}
