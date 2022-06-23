
// ��GifDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��Gif.h"
#include "��GifDlg.h"
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


// C��GifDlg �Ի���




C��GifDlg::C��GifDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C��GifDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C��GifDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C��GifDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// C��GifDlg ��Ϣ�������

BOOL C��GifDlg::OnInitDialog()
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

void C��GifDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C��GifDlg::OnPaint()
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
		CPaintDC dc(this); // device context for painting

		//TODO: Add your message handler code here
		char buf[512];
		::GetCurrentDirectory(512,buf); // �õ���ǰ��������·��
		strcat(buf,"\\test.gif");       // �ҵ�·���µ�gif�ļ�
		CFileStatus fstatus;            // CFile::GetStatus����ʹ�ô˽ṹ�������й��ļ���״̬��Ϣ��
		CFile file; 
		IStream *pStm;
		ULONGLONG cb;       
		if(file.Open(buf,CFile::modeRead)&&file.GetStatus(buf,fstatus)&& // ��ֻ����ʽ���ļ�����ȡ�ļ�״̬�ɹ��������ļ���Ϊ��
			((cb = fstatus.m_size) != -1)) 
		{ 
			HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb); // �ú����Ӷ��з���һ����Ŀ���ֽ���
			LPVOID pvData = NULL; 
			if (hGlobal != NULL)  // ����ɹ�
			{ 
				if ((pvData = GlobalLock(hGlobal)) != NULL) 
				{ 
					file.Read(pvData, cb);  // ���ļ���ȡ��pvDataָ��ָ���ȫ���ڴ�λ��
					GlobalUnlock(hGlobal);  // ȫ����Դ����
					CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); // �������ڴ����
				} 
			} 
		}
		IPicture *pPic; //CComQIPtr<IPicture> pPic;

		//��OleLoadPicture���IPicture�ӿ�ָ��
		//�õ�IPicture COM�ӿڶ������Ϳ��Խ��л��ͼƬ��Ϣ����ʾͼƬ�Ȳ���
		if(SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,false,IID_IPicture,(LPVOID*)&pPic)))
		{
			// ��API OleLoadPicture������JPG��GIF��ʽ��ͼƬ��ע����֧��PNG��ʽ������GIFֻ�ܼ��ص�һ֡���Ҳ�֧��͸���� 
			// OleLoadPicture ����ʵ���ϴ�����һ��IPicture���͵�COM�ӿڶ���Ȼ�����ǿ���ͨ�����COM�ӿ�������ͼƬ
			//��ʵ������Ҳ������API OleCreatePictureIndirect������ͼƬ��
			// ������ȶ���OleLoadPicture�������˻�������IPicture����Ĵ� ������
			long a,b;
			pPic->get_Width(&a);
			pPic->get_Height(&b);
			CSize sz(a,b);
			CDC *pdc=GetDC();
			pdc->HIMETRICtoDP(&sz);  // ��HIMETRIC��С��OLEת��Ϊ����ʱ����ʹ�ô˺���
			CRect rect;              // �õ��ͻ�������
			this->GetClientRect(&rect);
			pPic->Render(*pdc,rect.left+1,rect.top+1,sz.cx,sz.cy,0,b,a,-b,&rect); //��ָ����DC�ϻ��ͼƬ
		}                                                                         // ��com�ӿڶ�ȡ���ݵ�DC��
		//Do not call CDialog::OnPaint() for painting messages
		/*CDialogEx::OnPaint();*/
	}
}



//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C��GifDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

