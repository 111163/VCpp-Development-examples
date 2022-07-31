
// GDIplusʹ��Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GDIplusʹ��.h"
#include "GDIplusʹ��Dlg.h"
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


// CGDIplusʹ��Dlg �Ի���




CGDIplusʹ��Dlg::CGDIplusʹ��Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGDIplusʹ��Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nCheck = 1;
}

void CGDIplusʹ��Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IMAGENAME, m_ImageName);
	DDX_Radio(pDX, IDC_BMP, m_nCheck);
}

BEGIN_MESSAGE_MAP(CGDIplusʹ��Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CGDIplusʹ��Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_QUIT, &CGDIplusʹ��Dlg::OnBnClickedQuit)
	ON_BN_CLICKED(IDC_CONVERT, &CGDIplusʹ��Dlg::OnBnClickedConvert)
	/*ON_CONTROL_RANGE(IDC_BMP, IDC_GIF,  &CGDIplusʹ��Dlg::OnBnClickedBmp)*/
	ON_BN_CLICKED(IDC_BMP, &CGDIplusʹ��Dlg::OnBnClickedBmp)
	ON_BN_CLICKED(IDC_JPEG, &CGDIplusʹ��Dlg::OnBnClickedJpeg)
	ON_BN_CLICKED(IDC_GIF, &CGDIplusʹ��Dlg::OnBnClickedGif)
END_MESSAGE_MAP()


// CGDIplusʹ��Dlg ��Ϣ�������

BOOL CGDIplusʹ��Dlg::OnInitDialog()
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
	GdiplusStartup(&m_pGdiToken,&m_Gdiplus,NULL);	


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CGDIplusʹ��Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGDIplusʹ��Dlg::OnPaint()
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
HCURSOR CGDIplusʹ��Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGDIplusʹ��Dlg::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���
	GdiplusShutdown(m_pGdiToken);
	CDialogEx::OnCancel();
}


void CGDIplusʹ��Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog flDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"ͼ���ļ�|*.bmp;*.jpeg;*.gif|�����ļ�|*.*||", this);
	if (flDlg.DoModal() == IDOK)
	{
		m_FileName = flDlg.GetPathName();
		m_ImageName.SetWindowText(m_FileName);
	}
	/*CDialogEx::OnOK();*/
}


void CGDIplusʹ��Dlg::OnBnClickedQuit()
{
	OnCancel();
}

int GetCodecClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT  num = 0;		//��¼ͼ����������
	UINT  size = 0;		//��¼���������С
	ImageCodecInfo* pImageCodecInfo = NULL;	//����ͼ�������Ϣ
	GetImageEncodersSize(&num, &size);		//��ȡͼ�����������ͱ��������С
	if(size == 0)
		return -1; 
	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if(pImageCodecInfo == NULL)
		return -1;  
	GetImageEncoders(num, size, pImageCodecInfo);	//��ȡͼ�����
	for(UINT j = 0; j < num; ++j)					//ƥ��ͼ���ʽ,
	{
		if( wcscmp(pImageCodecInfo[j].MimeType, format) == 0 )
		{
			*pClsid = pImageCodecInfo[j].Clsid;

			return j;  
		}    
	} 
	return -1; 
}


void CGDIplusʹ��Dlg::OnBnClickedConvert()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	switch(m_nCheck)
	{
	case 0:
		{
			CFileDialog flDlg(FALSE,"bmp","convert",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"�����ļ�|*.*||",this);
			if (flDlg.DoModal()==IDOK)
			{
				CString svname = flDlg.GetPathName();
				Bitmap bmp(m_FileName.AllocSysString());
				CLSID clsid ;
				GetCodecClsid(L"image/bmp", &clsid);
				bmp.Save(svname.AllocSysString(),&clsid);	
			}
		}
		break;
	case 1:
		{
			CFileDialog flDlg(FALSE,"jpeg","convert",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"�����ļ�|*.*||",this);
			if (flDlg.DoModal()==IDOK)
			{
				CString svname = flDlg.GetPathName();
				Bitmap bmp(m_FileName.AllocSysString());
				CLSID clsid;
				GetCodecClsid(L"image/jpeg", &clsid);
				bmp.Save(svname.AllocSysString(),&clsid);
			}
		}
		break;
	case 2:
		{
			CFileDialog flDlg(FALSE,"gif","convert",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"�����ļ�|*.*||",this);
			if (flDlg.DoModal()==IDOK)
			{
				CString svname = flDlg.GetPathName();
				Bitmap bmp(m_FileName.AllocSysString());
				CLSID clsid = ImageFormatGIF;
				GetCodecClsid(L"image/gif", &clsid);
				bmp.Save(svname.AllocSysString(),&clsid);	
			}
		}
		break;
	}	
}


void CGDIplusʹ��Dlg::OnBnClickedBmp()
{
	m_nCheck = 0;
}


void CGDIplusʹ��Dlg::OnBnClickedJpeg()
{
	m_nCheck = 1;
}


void CGDIplusʹ��Dlg::OnBnClickedGif()
{
	m_nCheck = 2;
}
