
// ����������������Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����������������.h"
#include "����������������Dlg.h"
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


// C����������������Dlg �Ի���




C����������������Dlg::C����������������Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C����������������Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C����������������Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C����������������Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// C����������������Dlg ��Ϣ�������

BOOL C����������������Dlg::OnInitDialog()
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

void C����������������Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C����������������Dlg::OnPaint()
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
		CDC *pDC = GetDC();				//��ȡDC
		CBrush br,*oldbr;
		oldbr=pDC->SelectObject(&br);		//ѡ��ˢ
		for(int m=255;m>0;m--)
		{
			int r=(500*m)/255;			//�޸���ɫֵ
			br.DeleteObject();
			br.CreateSolidBrush(RGB(255,m,0));	//�����»�ˢ
			pDC->FillRect(CRect(0,0,r,r),&br);		//�������
		}
		CFont font;
		CFont *pOldFont; 
		font.CreatePointFont(500,"����");				//��������
		pOldFont=pDC->SelectObject(&font);				//ѡ������
		pDC->SetBkMode(TRANSPARENT);				//�����ı�͸��
		CPen pen(PS_SOLID,1,RGB(0, 128, 255));		//��������
		CPen *pOldPen;
		pOldPen=pDC->SelectObject(&pen);				//ѡ�񻭱�
		// ��ʼһ��·��
		pDC->BeginPath();
		pDC->TextOut(10, 10, "���տƼ�");				//�����ı�
		pDC->EndPath();		//����·��
		int num=pDC->GetPath(NULL,NULL,0);		//��ȡ·��������
		CPoint*pt=new CPoint[num];					//����������
		BYTE*type=new BYTE[num];					//��������������
		num=pDC->GetPath(pt,type,num);				//��ȡ·����Ϣ
		CPoint pstart;
		for(int j=0;j<num;j++)						//���ݲ�ͬ�����ͻ�����
		{
			switch(type[j])
			{
			case PT_MOVETO:
				pDC->MoveTo(pt[j]);
				pstart=pt[j];
				break;
			case PT_LINETO:
				pDC->LineTo(pt[j]);
				break;
			case PT_BEZIERTO:
				pDC->PolyBezierTo(pt+j,3);
				j=j+2;
				break;
			case PT_BEZIERTO|PT_CLOSEFIGURE:
				pt[j+2]=pstart;
				pDC->PolyBezierTo(pt+j,3);
				j=j+2;
				break;
			case PT_LINETO|PT_CLOSEFIGURE:
				pDC->LineTo(pstart);
				break;
			}
			pDC->CloseFigure();
			//��׼����һ��·�������һϵ���߶Σ�
			//�ͻ���һ���򿪵�ͼ�Ρ��������������ʱ��
			//windows���ڵ�ǰλ�ú�ͼ�ε���ʼ����ͨ�������һ��
			//MoveToEx�������û���λ�õĵط�����һ���ߡ�
			//ͼ�е������ߺ͵�һ���߻����ӵ�һ��
			//ע�������Լ���������ߣ�ͼ���Իᴦ�ڴ�״̬������ʹ������յ���ͬ��
			//������������뼸�λ��ʵĲ��졣����CloseFigure��
			//�߶λ����ӵ�һ�𡪡��������ǻ��ñʼ���ʾ������
			//һ���ر���ͼ�Σ���·���л�����һ���߾ͻ��һ����ͼ�ο�ʼ��
			//�򿪵�ͼ�λᱻ��Щ�������·���ĺ����Զ��ر�
		}
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C����������������Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

