
// ���ݵ����ͻ���ͼ��Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "���ݵ����ͻ���ͼ��.h"
#include "���ݵ����ͻ���ͼ��Dlg.h"
#include "afxdialogex.h"
#include <math.h>

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


// C���ݵ����ͻ���ͼ��Dlg �Ի���




C���ݵ����ͻ���ͼ��Dlg::C���ݵ����ͻ���ͼ��Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C���ݵ����ͻ���ͼ��Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C���ݵ����ͻ���ͼ��Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C���ݵ����ͻ���ͼ��Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// C���ݵ����ͻ���ͼ��Dlg ��Ϣ�������

BOOL C���ݵ����ͻ���ͼ��Dlg::OnInitDialog()
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

void C���ݵ����ͻ���ͼ��Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C���ݵ����ͻ���ͼ��Dlg::OnPaint()
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
		/*
		CDC *pDC = GetDC();						//��ȡDC
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
		}
		*/

		CPoint pt[5];
		CDC *pDC = GetDC();
		pDC->SetViewportOrg(100,100); // �����в����ڸ����ϣ�Ϊ�˶����������ϣ����ƶ�ԭ�����
		int i;
		for(i=0;i<5;i++)
		{
			pt[i].x=100*cos(2*3.14/5*(i+1)); // [(2 * ��) / 5] * (i + 1)  ��Բƽ����5�ݣ�ͨ������������
			pt[i].y=100*sin(2*3.14/5*(i+1));
			CString tmp;
			tmp.Format("%d,%d ",pt[i].x, pt[i].y);
			//pDC->SetPixel(pt[i].x,pt[i].y,RGB(255,0,0));
		}

		for(i=0;i<5;i++)  // ��������0-2�� 1-3�� 2-4�� 3-0�� 4-1
		{
			int a;
			pDC->MoveTo(pt[i].x,pt[i].y);  // �ƶ�
			a=i+2;
			if(a>4) a-=5;				   // ����4���ǲ����ڵģ�Ӧ����5���ڲ���
			pDC->LineTo(pt[a].x,pt[a].y);  // ����
		}
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C���ݵ����ͻ���ͼ��Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

