
// ������ͬ�Ļ�ˢDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "������ͬ�Ļ�ˢ.h"
#include "������ͬ�Ļ�ˢDlg.h"
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


// C������ͬ�Ļ�ˢDlg �Ի���




C������ͬ�Ļ�ˢDlg::C������ͬ�Ļ�ˢDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C������ͬ�Ļ�ˢDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C������ͬ�Ļ�ˢDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C������ͬ�Ļ�ˢDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// C������ͬ�Ļ�ˢDlg ��Ϣ�������

BOOL C������ͬ�Ļ�ˢDlg::OnInitDialog()
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

void C������ͬ�Ļ�ˢDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C������ͬ�Ļ�ˢDlg::OnPaint()
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
		CPaintDC dc(this);
		dc.SetBkMode(TRANSPARENT);
		CFont font;
		font.CreatePointFont(80,"Courier New");
		dc.SelectObject(&font);

		CBrush br,*oldbr;
		br.CreateSolidBrush(RGB(255,0,0));
		oldbr=dc.SelectObject(&br);
		dc.Rectangle(10,10,110,110);
		dc.SelectObject(oldbr);
		br.DeleteObject();
		dc.TextOut(10,110,"��ɫˢ��");

		br.CreateHatchBrush(HS_CROSS,RGB(255,0,0));
		oldbr=dc.SelectObject(&br);
		dc.Rectangle(120,10,220,110);
		dc.SelectObject(oldbr);
		br.DeleteObject();
		dc.TextOut(120,110,"HS_CROSS");

		br.CreateHatchBrush(HS_DIAGCROSS,RGB(255,0,0));
		oldbr=dc.SelectObject(&br);
		dc.Rectangle(230,10,330,110);
		dc.SelectObject(oldbr);
		br.DeleteObject();
		dc.TextOut(230,110,"HS_DIAGCROSS");

		br.CreateHatchBrush(HS_FDIAGONAL,RGB(255,0,0));
		oldbr=dc.SelectObject(&br);
		dc.Rectangle(340,10,440,110);
		dc.SelectObject(oldbr);
		br.DeleteObject();
		dc.TextOut(340,110,"HS_FDIAGONAL");

		br.CreateHatchBrush(HS_HORIZONTAL,RGB(255,0,0));
		oldbr=dc.SelectObject(&br);
		dc.Rectangle(10,120,110,220);
		dc.SelectObject(oldbr);
		br.DeleteObject();
		dc.TextOut(10,220,"HS_HORIZONTAL");

		br.CreateHatchBrush(HS_VERTICAL,RGB(255,0,0));
		oldbr=dc.SelectObject(&br);
		dc.Rectangle(120,120,220,220);
		dc.SelectObject(oldbr);
		br.DeleteObject();
		dc.TextOut(120,220,"HS_VERTICAL");

		br.CreateHatchBrush(HS_BDIAGONAL,RGB(255,0,0));
		oldbr=dc.SelectObject(&br);
		dc.Rectangle(230,120,330,220);
		dc.SelectObject(oldbr);
		br.DeleteObject();
		dc.TextOut(230,220,"HS_BDIAGONAL");

		m_bmp.bmiHeader.biSize=sizeof(m_bmp.bmiHeader);
		m_bmp.bmiHeader.biBitCount=0;
		HBITMAP hbmp=(HBITMAP)LoadImage(::AfxGetResourceHandle(),"mr.bmp",IMAGE_BITMAP,0,
			0,LR_DEFAULTCOLOR|LR_LOADFROMFILE);
		GetDIBits(dc.GetSafeHdc(),hbmp,1,1,NULL,&m_bmp,DIB_RGB_COLORS);

		//ѹ�����豸�޹�λͼ��DIB��ָBITMAPINFO�������λͼ�����ֽ�
		m_pbmpheader=(long*)malloc(m_bmp.bmiHeader.biSizeImage+sizeof(BITMAPINFO));
		m_pbmpinfo=(BITMAPINFO*)m_pbmpheader;       // ��Ϣ��ͷ
		m_pbmpdata=m_pbmpheader+sizeof(BITMAPINFO); // ���ݿ�ͷ
		memcpy(m_pbmpheader,(const void*)&m_bmp,sizeof(BITMAPINFOHEADER));
		GetDIBits(dc.GetSafeHdc(),hbmp,1,m_pbmpinfo->bmiHeader.biHeight,m_pbmpdata,
			m_pbmpinfo,DIB_RGB_COLORS);				// ��ȡ����Ϣ������   -ʵ���Ͼ��ǽ���m_pbmpheader��ͷ�������������Ϊ����Ϣ������

		LOGBRUSH logbrush;							// �����ṹ������д�ṹ
		logbrush.lbColor=DIB_RGB_COLORS;
		logbrush.lbHatch=(LONG)m_pbmpheader;
		logbrush.lbStyle=BS_DIBPATTERNPT;
		br.CreateBrushIndirect(&logbrush);
		oldbr=dc.SelectObject(&br);
		dc.Rectangle(340,120,440,220);
		dc.SelectObject(oldbr);
		br.DeleteObject();
		dc.TextOut(340,220,"LOGBRUSH");

		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C������ͬ�Ļ�ˢDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

