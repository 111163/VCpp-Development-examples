
// ģ��ʱ��Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ģ��ʱ��.h"
#include "ģ��ʱ��Dlg.h"
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


// Cģ��ʱ��Dlg �Ի���




Cģ��ʱ��Dlg::Cģ��ʱ��Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cģ��ʱ��Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cģ��ʱ��Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cģ��ʱ��Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// Cģ��ʱ��Dlg ��Ϣ�������

BOOL Cģ��ʱ��Dlg::OnInitDialog()
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
	SetTimer(1, 1000, NULL);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Cģ��ʱ��Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cģ��ʱ��Dlg::OnPaint()
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
	//////////////////////////////////////////////////////////////////////////��Բ
	CDC *pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	int xStart = rect.right/2;
	int yStart = rect.bottom/2;
	CTime time = CTime::GetCurrentTime();
	CString strDigits;
	int x,y;
	CSize size;
	CPen Pen(PS_SOLID, 5, RGB(0,0,0));
	CPen *oldPne = pDC->SelectObject(&Pen);
	pDC->Ellipse(5, 5, rect.right - 5, rect.bottom - 5); 
	//////////////////////////////////////////////////////////////////////////дСʱ����
	double Radians;
	pDC->SetTextColor(RGB(0,0,0));
	for (int i = 1; i<=12; ++i)
	{	
		strDigits.Format("%d",i);
		size = pDC->GetTextExtent(strDigits, strDigits.GetLength());
		Radians = (double)i*2*3.14/12.0;
		x = (int)((double)(xStart-20)*sin(Radians)) +   // ������к��ŵ���x��
			xStart - (size.cx/2) ;
		y= -(int)((double)(yStart-20)*cos(Radians)) +
			yStart- ( size.cy/2) ;  // con�Ǹ�ֵ��Ҫ��ת��
		pDC->TextOut(x, y, strDigits);
	}
	//////////////////////////////////////////////////////////////////////////����Сʱ�ĽǶ�
	Radians = (double)time.GetHour()+(double)time.GetMinute()/60.0+
		(double)time.GetSecond()/3600.0;
	Radians *= 2 * 3.14 / 12.0;
	CPen HourPen(PS_SOLID,5,RGB(0,0,0));
	pDC->SelectObject(&HourPen);
	pDC->MoveTo(xStart,yStart);
	pDC->LineTo(xStart+(int)((double)(xStart/3) *sin(Radians)),
		yStart-(int)((double)(yStart/3)*cos(Radians)));
	//////////////////////////////////////////////////////////////////////////������ӵĽǶ�
	Radians=(double)time.GetMinute()+(double)time.GetSecond()/60.0;
	Radians*= 2 * 3.14 / 60.0;
	CPen MinutePen(PS_SOLID,3,RGB(0,0,0));
	pDC->SelectObject(&MinutePen);
	pDC->MoveTo(xStart,yStart);
	pDC->LineTo(xStart+(int)((double)((xStart*2)/3)*sin(Radians)),
		yStart-(int)((double)((yStart*2)/3)*cos(Radians)));
	//////////////////////////////////////////////////////////////////////////������ĽǶ�
	Radians=(double)time.GetSecond();
	Radians*= 2 * 3.14 / 60.0;
	CPen SecondPen(PS_SOLID,1,RGB(0,0,0));
	pDC->SelectObject(&SecondPen);
	pDC->MoveTo(xStart,yStart);
	pDC->LineTo(xStart+(int)((double)((xStart*4)/5)*sin(Radians)),
		yStart-(int)((double)((yStart*4)/5)*cos(Radians)));

	pDC->SelectObject(oldPne);
	SecondPen.DeleteObject();
	MinutePen.DeleteObject();
	HourPen.DeleteObject();
	Pen.DeleteObject();
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Cģ��ʱ��Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cģ��ʱ��Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Invalidate(TRUE);
	UpdateWindow();
	CDialogEx::OnTimer(nIDEvent);
}
