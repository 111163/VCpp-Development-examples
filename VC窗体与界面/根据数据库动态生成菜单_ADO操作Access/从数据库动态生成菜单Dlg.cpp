
// �����ݿ⶯̬���ɲ˵�Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�����ݿ⶯̬���ɲ˵�.h"
#include "�����ݿ⶯̬���ɲ˵�Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern _ConnectionPtr m_pCon;
extern _RecordsetPtr m_pRecord;


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


// C�����ݿ⶯̬���ɲ˵�Dlg �Ի���




C�����ݿ⶯̬���ɲ˵�Dlg::C�����ݿ⶯̬���ɲ˵�Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C�����ݿ⶯̬���ɲ˵�Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C�����ݿ⶯̬���ɲ˵�Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C�����ݿ⶯̬���ɲ˵�Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// C�����ݿ⶯̬���ɲ˵�Dlg ��Ϣ�������

BOOL C�����ݿ⶯̬���ɲ˵�Dlg::OnInitDialog()
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
	m_menu.CreateMenu();
	LoadMenuFromDatabase();

	//SetMenu(&m_Menu);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C�����ݿ⶯̬���ɲ˵�Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C�����ݿ⶯̬���ɲ˵�Dlg::OnPaint()
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
HCURSOR C�����ݿ⶯̬���ɲ˵�Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL C�����ݿ⶯̬���ɲ˵�Dlg::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetWindowRect(&rect);
	CBitmap m_Bitmap;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	memDC.SelectObject(&m_Bitmap);

	CBitmap* bmp = NULL;
	pDC->BitBlt(0,0,rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);
	if (bmp) memDC.SelectObject(bmp);
	return TRUE;
	//return CDialogEx::OnEraseBkgnd(pDC);
}


void C�����ݿ⶯̬���ɲ˵�Dlg::LoadMenuFromDatabase(void)
{
	CString sql;
	sql.Format( "select * from tb_menuinfo where �ϼ��˵� is NULL"); // �˵�����Ŀ��û�и�����
	m_pRecord = m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	CString c_menustr;
	while (! m_pRecord->ADOEOF)
	{
		c_menustr = m_pRecord->GetCollect("�˵�����").bstrVal;
		LoadSubMenu(&m_menu,c_menustr);	
		m_pRecord->MoveNext();
	}
	SetMenu(&m_menu);
}


void C�����ݿ⶯̬���ɲ˵�Dlg::LoadSubMenu(CMenu* m_menu, CString str)
{
	_ConnectionPtr m_con;
	_RecordsetPtr m_record;
	m_con.CreateInstance("ADODB.Connection");
	m_record.CreateInstance("ADODB.Recordset");
	m_con->ConnectionString = m_pCon->ConnectionString;
	m_con->Open("","","",-1);
	CString sql;
	sql.Format("select * from tb_menuinfo where �ϼ��˵� = '%s'",str);
	m_record = m_con->Execute((_bstr_t)sql,NULL,adCmdText);
	CMenu m_tempmenu;
	m_tempmenu.CreatePopupMenu();

	while (!m_record->ADOEOF)
	{
		CString c_menustr;
		c_menustr = m_record->GetCollect("�˵�����").bstrVal;
		m_tempmenu.AppendMenu(MF_STRING,-1,c_menustr);  // �˵���
		if (IsHaveSubMenu(c_menustr))
			LoadSubMenu(&m_tempmenu,c_menustr);
		m_record->MoveNext();
	}

	m_menu->AppendMenu(MF_POPUP,(UINT)m_tempmenu.m_hMenu,str); // �����˵����뵽�˵�
	m_tempmenu.Detach();

	if (m_record != NULL)
		m_record.Release();
	if (m_con!= NULL)
		m_con.Release();
}





BOOL C�����ݿ⶯̬���ɲ˵�Dlg::IsHaveSubMenu(CString str)
{
	_ConnectionPtr m_con;
	_RecordsetPtr m_record;
	m_con.CreateInstance("ADODB.Connection");
	m_record.CreateInstance("ADODB.Recordset");
	m_con->ConnectionString = m_pCon->ConnectionString;
	m_con->Open("","","",-1);
	CString sql;
	sql.Format("select * from tb_menuinfo where �ϼ��˵� = '%s'",str);
	m_record = m_con->Execute((_bstr_t)sql,NULL,adCmdText);
	if ((!m_record->BOF) && (! m_record->ADOEOF))
	{
		return TRUE;
	}
	return FALSE;
}
