
// ���ƽ�����ɫ�Ŀ�����Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "���ƽ�����ɫ�Ŀ�����.h"
#include "���ƽ�����ɫ�Ŀ�����Dlg.h"
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


// C���ƽ�����ɫ�Ŀ�����Dlg �Ի���




C���ƽ�����ɫ�Ŀ�����Dlg::C���ƽ�����ɫ�Ŀ�����Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C���ƽ�����ɫ�Ŀ�����Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C���ƽ�����ɫ�Ŀ�����Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C���ƽ�����ɫ�Ŀ�����Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// C���ƽ�����ɫ�Ŀ�����Dlg ��Ϣ�������

BOOL C���ƽ�����ɫ�Ŀ�����Dlg::OnInitDialog()
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

void C���ƽ�����ɫ�Ŀ�����Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C���ƽ�����ɫ�Ŀ�����Dlg::OnPaint()
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
		CDC *pDC = GetDC();
		CRect rect;
		GetWindowRect(&rect);
		CFont font;
		font.CreatePointFont(900, "����");
		CFont *oldFont = pDC->SelectObject(&font);
		pDC->SetBkMode(TRANSPARENT);
		CPen pen(PS_SOLID, 1, RGB(0, 128, 255));
		CPen *oldPne = pDC->SelectObject(&pen);
		pDC->BeginPath();
			pDC->TextOut(10, 10,"������ã�");
		pDC->EndPath();
		pDC->SelectClipPath(RGN_AND);// ·����ĵľ��������  //RGN_DIFF---·����ľ�������
		// �ú���ѡ��ǰ��·����Ϊ�豸������һ����������ͨ��ʹ���ض���ģʽ���µ��������κδ��ڵļ�������ϲ���							
		//  ����ʹ��·���ķ�������ȡֵ���£�
		//	RGN_AND���µļ�����������ǰ���������뵱ǰ·����һ���������ص����򣩡�
		//	RGN_COPY���µļ���������ǵ�ǰ��·����
		//	RGN_DIFF���µļ�������������˵�ǰ·����ĵ�ǰ��������
		//	RGN_OR���µļ������������ǰ���������뵱ǰ·���Ĳ�����
		//	RGN_XOR���µļ������������ǰ���������뵱ǰ·���Ĳ������������ص�������
		CBrush br,*oldbr;
		oldbr=pDC->SelectObject(&br);
		for(int m=255;m>0;m--) 
		{
			int r=(600*m)/255;
			br.DeleteObject();
			br.CreateSolidBrush(RGB(255,m,128));              //������ˢ
			pDC->FillRect(CRect(0,0,r,300),&br);         //������  ��������
			CString tmp;
			//tmp.Format("%d ", r);
			//TRACE(tmp);
		}
		pDC->SelectObject(oldbr);
		pDC->SelectObject(oldFont);
		font.DeleteObject();
		pDC->SelectObject(oldPne);
		font.DeleteObject();
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C���ƽ�����ɫ�Ŀ�����Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

