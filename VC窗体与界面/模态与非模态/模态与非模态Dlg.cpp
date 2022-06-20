
// ģ̬���ģ̬Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ģ̬���ģ̬.h"
#include "ģ̬���ģ̬Dlg.h"
#include "afxdialogex.h"
#include "dlgModal.h"
#include "dlgNoModal.h"

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


// Cģ̬���ģ̬Dlg �Ի���




Cģ̬���ģ̬Dlg::Cģ̬���ģ̬Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cģ̬���ģ̬Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cģ̬���ģ̬Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cģ̬���ģ̬Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_MODAL, &Cģ̬���ģ̬Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_NOMODAL, &Cģ̬���ģ̬Dlg::OnBnClickedButton3)
	ON_MESSAGE(WM_USER_CLICKED_OK,  &Cģ̬���ģ̬Dlg::OnClickEdOk)
	ON_MESSAGE(WM_USER_CLICKED_CANCEL,  &Cģ̬���ģ̬Dlg::OnClickEdOk)
END_MESSAGE_MAP()


// Cģ̬���ģ̬Dlg ��Ϣ�������

BOOL Cģ̬���ģ̬Dlg::OnInitDialog()
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

void Cģ̬���ģ̬Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cģ̬���ģ̬Dlg::OnPaint()
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
HCURSOR Cģ̬���ģ̬Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void Cģ̬���ģ̬Dlg::OnBnClickedButton2()
{
	 dlgModal doMoDal(this);
	 int ret = doMoDal.DoModal();
	 CString tmp;
	 tmp.Format("���ڵ����%d��ť�˳���", ret);
	 AfxMessageBox(tmp);
}


void Cģ̬���ģ̬Dlg::OnBnClickedButton3()
{
	dlgNoModal *pDlgNo = new dlgNoModal(this);
	pDlgNo->Create(IDD_NOMODAL);// IDD_NOMODAL
	pDlgNo->ShowWindow(TRUE);
}



// ��ģ̬�Ի��򵽵��ǵ���˵���Ǹ���ť���ص�
LRESULT Cģ̬���ģ̬Dlg::OnClickEdOk(WPARAM wParam, LPARAM lParam)
{
	switch (wParam + lParam)
	{
	case 3:
		{
			CString tmp;
			tmp.Format("���ڵ����%d��ť�˳���", wParam + lParam);
			AfxMessageBox(tmp);
				break;
		}
	case 7:
		{
			CString tmp;
			tmp.Format("���ڵ����%d��ť�˳���", wParam + lParam);
			AfxMessageBox(tmp);
			break;
		}
	}
	return LRESULT(0);
}
