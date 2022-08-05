
// FindFile��ʹ��Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FindFile��ʹ��.h"
#include "FindFile��ʹ��Dlg.h"
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


// CFindFile��ʹ��Dlg �Ի���




CFindFile��ʹ��Dlg::CFindFile��ʹ��Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFindFile��ʹ��Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFindFile��ʹ��Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFindFile��ʹ��Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CFindFile��ʹ��Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CFindFile��ʹ��Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CFindFile��ʹ��Dlg ��Ϣ�������

BOOL CFindFile��ʹ��Dlg::OnInitDialog()
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

	CComboBox *pComBox = (CComboBox *)GetDlgItem(IDC_COMBO1);
	DWORD dirlen = GetLogicalDriveStrings(0, NULL);
	HANDLE hp = GetProcessHeap();
	LPSTR pdir = (LPSTR)HeapAlloc(hp, HEAP_ZERO_MEMORY, dirlen);
	LPSTR ptmp = pdir;
	GetLogicalDriveStrings(dirlen, pdir);
	while (*pdir != '\0')
	{
		pComBox->AddString(pdir);
		pdir = strchr(pdir,'\0')+1;
	}
	HeapFree(hp, HEAP_NO_SERIALIZE, ptmp);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CFindFile��ʹ��Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFindFile��ʹ��Dlg::OnPaint()
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
HCURSOR CFindFile��ʹ��Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFindFile��ʹ��Dlg::OnBnClickedButton1()
{
	CString flname,findret,dir;
	BOOL result = FALSE;
	((CEdit *)GetDlgItem(IDC_EDIT1))->GetWindowText(flname);
	((CComboBox *)GetDlgItem(IDC_COMBO1))->GetWindowText(dir);
	if (!flname.IsEmpty() && !dir.IsEmpty())
	{
		CFileFind flFind;
		dir += "*.*";
		BOOL ret = flFind.FindFile(dir);
		if (ret)
		{
			ret = flFind.FindNextFile();
			while(ret)
			{
				if (flFind.IsDots())
					continue;
				findret = flFind.GetFileName();
				if (findret == flname)
				{
					result = TRUE;
					break;
				}
				ret = flFind.FindNextFile();
			}
		}
		if (result)
		{
			CString strHint = "�����ļ���λ�ڣ�";
			strHint += flFind.GetFilePath();
			flFind.Close();
			MessageBox(strHint,"��ʾ");
		}
	}
}


void CFindFile��ʹ��Dlg::OnBnClickedButton2()
{
	CDialogEx::OnCancel();
}
