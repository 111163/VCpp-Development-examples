
// �༭������ʱ�б��Ҳ��ʾDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�༭������ʱ�б��Ҳ��ʾ.h"
#include "�༭������ʱ�б��Ҳ��ʾDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

 bool enter=false;
 int i=0;
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


// C�༭������ʱ�б��Ҳ��ʾDlg �Ի���




C�༭������ʱ�б��Ҳ��ʾDlg::C�༭������ʱ�б��Ҳ��ʾDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C�༭������ʱ�б��Ҳ��ʾDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C�༭������ʱ�б��Ҳ��ʾDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ConList);
	DDX_Control(pDX, IDC_EDIT1, m_ConEdit);
}

BEGIN_MESSAGE_MAP(C�༭������ʱ�б��Ҳ��ʾDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &C�༭������ʱ�б��Ҳ��ʾDlg::OnEnChangeEdit1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &C�༭������ʱ�б��Ҳ��ʾDlg::OnDblclkList1)
END_MESSAGE_MAP()


// C�༭������ʱ�б��Ҳ��ʾDlg ��Ϣ�������

BOOL C�༭������ʱ�б��Ҳ��ʾDlg::OnInitDialog()
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

	m_ConList.ModifyStyle(0L, LVS_REPORT);
	m_ConList.ModifyStyle(0L, LVS_SHOWSELALWAYS);
	m_ConList.ModifyStyle(0L, LVS_NOSORTHEADER);
	m_ConList.SetExtendedStyle(LVS_EX_GRIDLINES); // ������
	m_ConList.InsertColumn(0, "����");
	m_ConList.InsertColumn(1, "�Ա�");
	m_ConList.InsertColumn(2, "��������");

	m_ConList.SetColumnWidth(0,50);
	m_ConList.SetColumnWidth(1,50);
	m_ConList.SetColumnWidth(2,100);

	m_ConEdit.MoveWindow(15,15,150,21);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C�༭������ʱ�б��Ҳ��ʾDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C�༭������ʱ�б��Ҳ��ʾDlg::OnPaint()
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
HCURSOR C�༭������ʱ�б��Ҳ��ʾDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void C�༭������ʱ�б��Ҳ��ʾDlg::SetDataBase(CString sql)
{
	::CoInitialize(NULL);
	m_pConnection=NULL;
	m_pConnection.CreateInstance(__uuidof(Connection)); 
	// ��Ϊ�и����������Open�е�������û����Ḳ��ConnectionString�еģ�����ͳһ��������û���д��Open��
	// ��ConnectionString��ֻ�� ���� ·�� ������ָ���򿪿ͻ�������ʱʹ�õ��ṩ�����ƣ�������Զ�����ݷ���ָ���򿪿ͻ�������ʱʹ�õķ�������·�����ƣ�������Զ�����ݷ����趨
	m_pConnection->ConnectionString="Provider=Microsoft.ACE.OLEDB.12.0;Data Source=mrdb.accdb;";//uid=;pwd=;
	m_pConnection->Open(L"",L"",L"",adCmdUnspecified);
	CString text;
	text.Format("select * from info where xm like '%s%%'",sql);
	m_pRecordset=m_pConnection->Execute((_bstr_t)text,NULL,adCmdText);
	if(m_pRecordset->GetRecordCount()==0)
	{m_ConList.ShowWindow(SW_HIDE);}
	int i=0;
	while(!m_pRecordset->adoEOF)
	{
		xm=(char*)(_bstr_t)m_pRecordset->GetCollect("xm");
		xb=(char*)(_bstr_t)m_pRecordset->GetCollect("xb");
		csrq=(char*)(_bstr_t)m_pRecordset->GetCollect("csrq");
		gzdw=(char*)(_bstr_t)m_pRecordset->GetCollect("gzdw");
		yddh=(char*)(_bstr_t)m_pRecordset->GetCollect("yddh");
		gddh=(char*)(_bstr_t)m_pRecordset->GetCollect("gddh");
		m_ConList.InsertItem(i,"");
		m_ConList.SetItemText(i,0,xm);
		m_ConList.SetItemText(i,1,xb);
		m_ConList.SetItemText(i,2,csrq);
		m_ConList.SetItemText(i,3,gzdw);
		m_ConList.SetItemText(i,4,yddh);
		m_ConList.SetItemText(i,5,gddh);
		i+=1;
		m_pRecordset->MoveNext();
	}
	m_pRecordset->Close();
	m_pConnection->Close();
	m_pRecordset=NULL;
	m_pConnection=NULL;
	::CoUninitialize();
}


BOOL C�༭������ʱ�б��Ҳ��ʾDlg::PreTranslateMessage(MSG* pMsg) // �Լ��������Ϣ�Ĵ���
{
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE) // ���»س���
	{
		m_ConList.ShowWindow(SW_HIDE);
		IsShowing=false;
		pMsg->wParam=VK_CONTROL;  // ���������ֵ�������ˣ����Ǿ͸�����һ�����õ�ֵ����ֹ�����ٴδ���
	}
	if (pMsg->message==WM_LBUTTONDOWN)  // ������������Ҳ����б�Χ�ڣ��б���ʧ
	{
		if (pMsg->hwnd!= m_ConList.m_hWnd)
		{m_ConList.ShowWindow(SW_HIDE);
		IsShowing=false;}
	}
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==13) // ����ȷ�ϼ�
	{	
		if(IsShowing)
			m_ConEdit.SetWindowText(xm);
		m_ConList.ShowWindow(SW_HIDE);
		IsShowing=false;
		i=0;
		pMsg->wParam=VK_CONTROL;
	}
	if(pMsg->hwnd==m_ConList.m_hWnd&& pMsg->message==WM_LBUTTONDBLCLK) // ���˫��(���ﲶ��������б����˫��)
	{
		m_ConEdit.SetWindowText(xm);
		m_ConList.ShowWindow(SW_HIDE);
		IsShowing=false;
	}
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_DOWN) // ����ť
	{
		if(IsShowing) // �����ǰ����ʾ״̬����Ҫ���������ƶ�
		{
			if(i==m_ConList.GetItemCount())
				i=0;
			m_ConList.SetHotItem(i);
			xm=m_ConList.GetItemText(i,0);
			i+=1;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}



void C�༭������ʱ�б��Ҳ��ʾDlg::AutoPostion()  // ��λ�б��涨��С
{
	this->m_ConList.MoveWindow(15,36,210,100);
}


void C�༭������ʱ�б��Ҳ��ʾDlg::OnEnChangeEdit1() // ��Edit�е�
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	CString edit;
	m_ConEdit.GetWindowText(edit);
	if (!edit.IsEmpty())
	{
		this->AutoPostion();
		m_ConList.DeleteAllItems();
		this->SetDataBase(edit);
		if (m_ConList.GetItemCount()>0) // ���ݴ����ݿ��ж�ȡֵ������б����б��Ƿ�Ϊ�գ����ж��Ƿ���ʾ�б�
		{
			m_ConList.ShowWindow(SW_SHOW);
			IsShowing = TRUE;
		}
	}
	else
	{
		m_ConList.ShowWindow(SW_HIDE);
		IsShowing = FALSE;
	}
}


void C�༭������ʱ�б��Ҳ��ʾDlg::OnDblclkList1(NMHDR *pNMHDR, LRESULT *pResult) // ��CListCtrl�ķ���˫����Ϣ(NM_DBLCLK)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	int i=m_ConList.GetHotItem(); // ��ȡ�����λ��
	CString text;
	xm=m_ConList.GetItemText(i,1); // ��ȡ�����λ�õĽڵ��ֵ
	

	*pResult = 0;
}

