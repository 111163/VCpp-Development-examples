
// API����ע���Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "API����ע���.h"
#include "API����ע���Dlg.h"
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


// CAPI����ע���Dlg �Ի���




CAPI����ע���Dlg::CAPI����ע���Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAPI����ע���Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAPI����ע���Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_KEYNAME, m_KeyName);
	DDX_Control(pDX, IDC_ITEMVALUE, m_ItemValue);
	DDX_Control(pDX, IDC_ITEMNAME, m_ItemName);
}

BEGIN_MESSAGE_MAP(CAPI����ע���Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OK, &CAPI����ע���Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_READ, &CAPI����ע���Dlg::OnBnClickedRead)
END_MESSAGE_MAP()


// CAPI����ע���Dlg ��Ϣ�������

BOOL CAPI����ע���Dlg::OnInitDialog()
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

void CAPI����ע���Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAPI����ע���Dlg::OnPaint()
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
HCURSOR CAPI����ע���Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAPI����ע���Dlg::OnBnClickedOk()
{
	HKEY hroot;
	DWORD action;
	CString keyname;
	m_KeyName.GetWindowText(keyname);
	keyname +="\\";
	RegCreateKeyEx(HKEY_CURRENT_USER, keyname, 0, NULL, 0, KEY_WRITE, NULL, &hroot, &action); //////////////////////////////////////////////////////////////////////////
	CString itemname;
	m_ItemName.GetWindowText(itemname);		
	CString itemvalue;
	m_ItemValue.GetWindowText(itemvalue);
	DWORD size = itemvalue.GetLength();
	if (ERROR_SUCCESS == RegSetValueEx(hroot, itemname, 0, REG_SZ, (unsigned char*)itemvalue.GetBuffer(0), size)) //////////////////////////////////////////////////////////////////////////
		MessageBox("Successful");
	RegCloseKey(hroot); //////////////////////////////////////////////////////////////////////////
}


void CAPI����ע���Dlg::OnBnClickedRead()
{
	HKEY hroot;
	CString keyname;
	m_KeyName.GetWindowText(keyname);
	RegOpenKeyEx(HKEY_CURRENT_USER, keyname, 0, KEY_READ, &hroot); //////////////////////////////////////////////////////////////////////////


	CString itemname;
	m_ItemName.GetWindowText(itemname);		
	CString itemvalue;
	DWORD type = REG_SZ;
	unsigned char data[MAX_PATH]= "temp";                                                                    //����һ���ַ�������
	DWORD size = MAX_PATH;                                                                //�����ַ�������


	RegQueryValueEx(hroot, itemname, 0, &type, data, &size); //////////////////////////////////////////////////////////////////////////
	MessageBox(CString(data), "��ʾ");
	LONG flg = RegDeleteValue(hroot, keyname); //////////////////////////////////////////////////////////////////////////
	if (ERROR_SUCCESS == flg) //---------------------------ע��������漰��RegOpenKeyExʱ��Ȩ���ˣ����Ҫɾ�����ҪKEY_WRITEȨ�޲���
		MessageBox("ɾ������ɹ�", "��ʾ");
	else
	{
		CString tmp;
		tmp.Format("%d", flg);
		MessageBox(tmp, "û��ɾ��");
	}
	RegCloseKey(hroot);
	RegDeleteKey(HKEY_CURRENT_USER, keyname); //////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////��EX �Ĳ������Ǵ򿪵�ע�����, ����EX �Ĳ������� ����-�Ӽ� ��ʽ
}
