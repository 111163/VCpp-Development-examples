
// ������Ʋ���Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "������Ʋ���.h"
#include "������Ʋ���Dlg.h"
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


// C������Ʋ���Dlg �Ի���




C������Ʋ���Dlg::C������Ʋ���Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C������Ʋ���Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strEdit = _T("");
}

void C������Ʋ���Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_conEdit);
	DDX_Text(pDX, IDC_EDIT1, m_strEdit);
}

BEGIN_MESSAGE_MAP(C������Ʋ���Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C������Ʋ���Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C������Ʋ���Dlg ��Ϣ�������

BOOL C������Ʋ���Dlg::OnInitDialog()
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

void C������Ʋ���Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C������Ʋ���Dlg::OnPaint()
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
HCURSOR C������Ʋ���Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C������Ʋ���Dlg::OnBnClickedButton1()
{
	int mStart, mEnd;
	CString tmp;
	m_conEdit.GetSel(mStart, mEnd);
	if(mStart >= mEnd)return;//û�н���ѡ��
	UpdateData(TRUE);						     // �󶨿ؼ��Ͱ󶨱��������Ի�ȡ��ֵ
	tmp = m_strEdit.Mid(mStart, mEnd - mStart); // ==> m_conEdit.GetWindowText(tmp1),tmp = tmp1(mStart, mEnd-mStart);
												// Ӧ��ע�⵽Mid����Mid(start, n)

	//��ѡ�е��ַ����Ƶ������壬���ַ����Ƶ�������Ĳ����ǣ�����ʹ��GlobalAlloc����һ���ڴ�ռ䣬
	//Ȼ���ַ����ݸ��Ƶ��ÿ��ڴ��У����ͨ��SetClipboardData������ѡ�������ݸ��Ƶ��������С�
	::OpenClipboard(this->GetSafeHwnd()); // �򿪼��а壬��ǰ���ھ��this->GetSaftHwnd()
	EmptyClipboard(); // ��ռ��а�
 	HGLOBAL hGlobal=GlobalAlloc(GMEM_FIXED,tmp.GetLength()+1);
 	HANDLE hmem=GlobalLock(hGlobal);
 	memcpy(hmem,tmp.GetBuffer(0),tmp.GetLength()+1);
 	GlobalUnlock(hGlobal);
 	SetClipboardData(CF_TEXT,hGlobal);
	m_conEdit.Paste();
	CloseClipboard();

	// CWnd::Copy()��װ������Ĳ��� 
	/*m_conEdit.Copy();*/
}

