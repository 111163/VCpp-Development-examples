
// ���ư�ťDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "���ư�ť.h"
#include "���ư�ťDlg.h"
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


// C���ư�ťDlg �Ի���




C���ư�ťDlg::C���ư�ťDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C���ư�ťDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C���ư�ťDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C���ư�ťDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// C���ư�ťDlg ��Ϣ�������

BOOL C���ư�ťDlg::OnInitDialog()
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

void C���ư�ťDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C���ư�ťDlg::OnPaint()
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
		//////////////////////////////////////////////////////////////////////////����Բ�ǰ�ť
		//CRect rect(10,10,200,100);
		//CPaintDC dc(this);
		//dc.SetBkMode(TRANSPARENT);
		//CBrush m_Brush;
		//m_Brush.CreateSolidBrush(RGB(50, 130, 200));
		//CBrush* oldBrush = dc.SelectObject(&m_Brush);
		//CPen m_Pan(PS_SOLID, 2, RGB(200, 100, 198));
		//CPen* oldPan = dc.SelectObject(&m_Pan);
		//dc.RoundRect(20, 20, rect.right,rect.bottom, 30, 30);

		//dc.SetTextColor(RGB(0,0,0));
		//CString str = "��ť����";
		//dc.DrawText(str, CRect(20, 20, rect.right, rect.bottom),
		//	DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		//
		//dc.SelectObject(oldBrush);
		//dc.SelectObject(oldPan);
		//m_Brush.DeleteObject();
		//m_Pan.DeleteObject();

		//////////////////////////////////////////////////////////////////////////���ƾ��䰴ť
		//CPaintDC dc(this); 
		//CRect rect(10,10,80,40);
		//dc.DrawFrameControl(&rect,DFC_BUTTON,DFCS_BUTTONPUSH);
		//CString str = "��ť����";
		////���ư�ť�ı�
		//dc.SetBkMode(TRANSPARENT);
		//dc.DrawText(str,CRect(10,10,rect.right,rect.bottom), 
		//	DT_CENTER|DT_VCENTER|DT_SINGLELINE); 

		//////////////////////////////////////////////////////////////////////////���������β����+��������߿�
		//CPaintDC dc(this);
		//dc.BeginPath();
		//	int x = 10;
		//	int y = 100;
		//	dc.MoveTo(x, y);
		//	x += 50;
		//	y = 30;
		//	dc.LineTo(x, y);
		//	x += 50;
		//	y = 100;
		//	dc.LineTo(x, y);
		//	x = 10;
		//	y = 100;
		//	dc.LineTo(x, y);
		//dc.EndPath();
		//CRgn rgn;
		//rgn.CreateFromPath(&dc);
		//CBrush brush(RGB(200, 100, 0));
		//dc.FillRgn(&rgn, &brush);
		//CBrush fbrush(RGB(0,0,0));
		//dc.FrameRgn(&rgn,&fbrush,2,2);

		//fbrush.DeleteObject();
		//rgn.DeleteObject();
		//brush.DeleteObject();


		////////////////////////////////////////////////////////////////////////// ����+�߿�+����+����+������ɫ
		CDC *pDC = GetDC();         //��ȡDC
		CFont font,*pOldfont;          //��������
		CPoint ptStart;                     //����λ��
		ptStart.x=10;                       //����λ��
		ptStart.y=10;
		int iOffset=12;                     //ƫ�ƴ�С
		font.CreatePointFont(500 ,"����");               //��������
		pOldfont=pDC->SelectObject(&font);                  //ѡ������
		CSize size=pDC->GetTextExtent("���տƼ�");             //��ȡ�ı���С
		//CGdiObject*object = pDC->SelectStockObject(NULL_BRUSH);         //͸��
		CBrush brush(NULL_BRUSH);//RGB(200, 100, 100)
		pDC->SelectObject(&brush);
		pDC->Rectangle(ptStart.x,ptStart.y,size.cx+iOffset,size.cy+iOffset);   //���ƾ���
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255,0,0));
		pDC->TextOut(ptStart.x,ptStart.y,"���տƼ�");           //��ָ��λ������ı�
		font.DeleteObject();  
		pDC->SelectObject(pOldfont);
		//pDC->SelectObject(object);
		brush.DeleteObject();

		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C���ư�ťDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

