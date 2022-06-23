
// ���С��ϷDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "���С��Ϸ.h"
#include "���С��ϷDlg.h"
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


// C���С��ϷDlg �Ի���




C���С��ϷDlg::C���С��ϷDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C���С��ϷDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_DeathCount = 0;
	m_Grade = 0;
	m_nLevel = 0;
	m_MisCount = 0;
	m_EscCount = 0;

	m_ptOrg.x = m_ptOrg.y = 15;       //��������ԭ��
	m_nCellHeight = 39;                   //���õ�Ԫ��߶�
	m_nCellWidth = 37;                    //���õ�Ԫ����
	m_nPerson = -1;
	for(int i=0; i<100; i++)                //������Ϸ���������
	{
		m_nLevels[i] = 1200 - i*100;
	}
	m_bHit = FALSE;
	m_State = GS_NONE;                //��ʼ����Ϸ״̬
}

void C���С��ϷDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DEATHCOUNT, m_DeathCount);
	DDX_Text(pDX, IDC_GRADE, m_Grade);
	DDX_Text(pDX, IDC_LEVEL, m_nLevel);
	DDX_Text(pDX, IDC_MISPLAY, m_MisCount);
	DDX_Text(pDX, IDC_ESCCOUNT, m_EscCount);
}

BEGIN_MESSAGE_MAP(C���С��ϷDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_START, &C���С��ϷDlg::OnBnClickedStart)
	ON_BN_CLICKED(IDC_ENDGAME, &C���С��ϷDlg::OnBnClickedEndgame)
END_MESSAGE_MAP()


// C���С��ϷDlg ��Ϣ�������

BOOL C���С��ϷDlg::OnInitDialog()
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
	srand((unsigned)time(NULL));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C���С��ϷDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C���С��ϷDlg::OnPaint()
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
		// ����Ҫ�ȵ��ø����OnPaint�������Ƚ�Ĭ�ϴ���������ٻ������ǵ�ͼ��ͼ��---����һ��Ҫע��
		CDialogEx::OnPaint();

		m_GridRC.left = m_ptOrg.x;                         //���ñ������
		m_GridRC.top = m_ptOrg.y;
		m_GridRC.right = m_ptOrg.x + 9*m_nCellWidth;
		m_GridRC.bottom = m_ptOrg.y + 9*m_nCellHeight;
		//���Ʊ��
		CDC* pDC  = GetDC();                                //��ȡ�����豸������
		pDC->FillRect(m_GridRC, NULL);                      //�������
		for(int i=0; i<=9; i++)                             //������
		{    
			pDC->MoveTo(m_ptOrg.x, m_ptOrg.y + i*m_nCellHeight);
			pDC->LineTo(m_ptOrg.x + 9*m_nCellWidth ,m_ptOrg.y + i*m_nCellHeight);
		}
		for(int j=0; j<=9; j++)                            //������
		{ 

			pDC->MoveTo(m_ptOrg.x + j*m_nCellWidth, m_ptOrg.y);
			pDC->LineTo(m_ptOrg.x + j*m_nCellWidth, m_ptOrg.y + 9*m_nCellHeight);
		}
		if (m_nPerson > 0)                                   //��������
		{
			CBitmap bmp;                                     //����λͼ����
			bmp.LoadBitmap(IDB_PERSON);                      //����λͼ
			CDC memDC;
			memDC.CreateCompatibleDC(pDC);                   //�������ݵ��豸������
			memDC.SelectObject(&bmp);                        //ѡ��λͼ
			pDC->StretchBlt(m_PersonRC.left, m_PersonRC.top, m_PersonRC.Width(), 
				m_PersonRC.Height(), &memDC, 0, 0, m_PersonRC.Width()-1, 
				m_PersonRC.Height()-1, SRCCOPY);      //��������
			bmp.DeleteObject();                                           //�ͷ�λͼ����
			memDC.DeleteDC();                                          //�ͷ��ڴ��豸������
		}
		ReleaseDC(pDC);	
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C���С��ϷDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C���С��ϷDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_nPerson = rand() % 73;    //����һ�������
	if (m_nPerson == 0)
		m_nPerson = 1;

	int nX = m_nPerson % 9;            //����������ֵ�λ��
	int nY = m_nPerson / 9;
	if(nX == 0)
	{
		nX = 9;
	}
	else 
	{
		nY++;
	}
	//ȷ��С�˳��ֵ�����   
	m_PersonRC.left = m_ptOrg.x + (nX-1)*m_nCellWidth;
	m_PersonRC.right = m_PersonRC.left + m_nCellWidth;
	m_PersonRC.top = m_ptOrg.y + (nY-1)*m_nCellHeight;
	m_PersonRC.bottom = m_PersonRC.top + m_nCellHeight;

	InvalidateRect(m_PersonRC);      //������������
	if (m_bHit == FALSE)          //����û�б�����
	{
		m_EscCount++;             //������������
		UpdateData(FALSE);
	}
	m_bHit = FALSE;
	if (m_nLevel <= 100)
	{
		if (m_Grade >= m_nLevel*50*15)
		{
			m_nLevel++;
			UpdateData(FALSE);
			NextLevel();            //��һ��
		}
	}
	else       //
	{
		OnEndgame();               //������Ϸ
	}
	CDialogEx::OnTimer(nIDEvent);
}


void C���С��ϷDlg::NextLevel(void)
{
	KillTimer(1);                  //������ʱ��
	m_State = GS_BEGIN;
	m_bHit = TRUE;
	SetTimer(1, m_nLevels[m_nLevel-1], NULL);      //���¿�ʼ��ʱ��
}


void C���С��ϷDlg::OnStart(void)
{
	if (m_State != GS_BEGIN)
	{
		m_State = GS_BEGIN;
		m_bHit = TRUE;
		SetTimer(1, m_nLevels[m_nLevel-1], NULL);       //����һ����ʱ������ʼ�µ���Ϸ
	}
}


void C���С��ϷDlg::OnEndgame(void)
{
	if (m_State == GS_BEGIN)                  //��Ϸ�ѿ�ʼ
	{
		m_State = GS_END;                     //������Ϸ״̬
		KillTimer(1);                                 //������ʱ��
		m_Grade = 0;                               //��ʼ������
		m_EscCount = 0;
		m_DeathCount = 0;
		m_MisCount = 0;
		m_nLevel = 1;
		UpdateData(FALSE);
		m_nPerson = -1;

		InvalidateRect(m_PersonRC);         //������������

	}
}


void C���С��ϷDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_State == GS_BEGIN)
	{
		if (m_PersonRC.PtInRect(point))           //����Ŀ��
		{
			CDC *pDC = GetDC();                   //��ȡ�����豸������
			CBitmap bmp;
			bmp.LoadBitmap(IDB_HITPERSON);         //����λͼ
			CDC memDC;
			memDC.CreateCompatibleDC(pDC);         //�����ڴ��豸������
			memDC.SelectObject(&bmp);              //ѡ��λͼ

			pDC->StretchBlt(m_PersonRC.left, m_PersonRC.top, m_PersonRC.Width(), 
				m_PersonRC.Height(), &memDC, 0, 0, m_PersonRC.Width()-1, 
				m_PersonRC.Height()-1, SRCCOPY);       //����λͼ

			bmp.DeleteObject();                        //�ͷ�λͼ����
			memDC.DeleteDC();
			ReleaseDC(pDC);

			m_DeathCount++;                                               
			m_Grade = m_DeathCount*50;                 //���û���
		}
		else                                            //δ����Ŀ�� 
		{
			m_MisCount++;                               //�ۼ�δ���д���
		}
		UpdateData(FALSE);

	}
	if (m_GridRC.PtInRect(point))
	{
		//�������ָ���µ���״
		SetCursor(LoadCursor(AfxGetResourceHandle(), MAKEINTRESOURCE(IDC_CURSOR2)));
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void C���С��ϷDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_bHit = TRUE;
	if (m_GridRC.PtInRect(point))             //���ָ��λ�ڱ������
	{
		//�����µ����ָ����״
		SetCursor(LoadCursor(AfxGetResourceHandle(), MAKEINTRESOURCE(IDC_CURSOR1)));

	}

	CDialogEx::OnLButtonDown(nFlags, point);
}


void C���С��ϷDlg::OnBnClickedStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnStart();
}


void C���С��ϷDlg::OnBnClickedEndgame()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnEndgame();
}
