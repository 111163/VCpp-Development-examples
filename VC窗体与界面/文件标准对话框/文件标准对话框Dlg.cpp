
// �ļ���׼�Ի���Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ļ���׼�Ի���.h"
#include "�ļ���׼�Ի���Dlg.h"
#include "afxdialogex.h"
#include <cstdlib>
#include <afxmsg_.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static const UINT WM_FINDMESSAGE = ::RegisterWindowMessage(FINDMSGSTRING);


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


// C�ļ���׼�Ի���Dlg �Ի���




C�ļ���׼�Ի���Dlg::C�ļ���׼�Ի���Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C�ļ���׼�Ի���Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strEdit = _T("");
}

void C�ļ���׼�Ի���Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT, m_strEdit);
	DDX_Control(pDX, IDC_PATH, m_ConSta);
	DDX_Control(pDX, IDC_EDIT, m_ConEdit);
}

BEGIN_MESSAGE_MAP(C�ļ���׼�Ի���Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C�ļ���׼�Ի���Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C�ļ���׼�Ի���Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &C�ļ���׼�Ի���Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &C�ļ���׼�Ի���Dlg::OnBnClickedButton4)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON5, &C�ļ���׼�Ի���Dlg::OnBnClickedButton5)
	ON_REGISTERED_MESSAGE(WM_FINDMESSAGE, &C�ļ���׼�Ի���Dlg::OnFindReplace)
	ON_BN_CLICKED(IDC_BUTTON6, &C�ļ���׼�Ի���Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &C�ļ���׼�Ի���Dlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// C�ļ���׼�Ի���Dlg ��Ϣ�������

BOOL C�ļ���׼�Ի���Dlg::OnInitDialog()
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
	nindex = 0;
	degree = FALSE;

	str[0] = "    ����ȥ�ߣ�����֮�ղ��������������ߣ�";
	str[1] = "����֮�նෳ�š��������������㣬�Դ˿���";
	str[2] = "����¥���������½����ǣ��м�Сл���෢��";
	str[3] = "�߻�����׳˼�ɣ��������������¡��鵶��ˮ";
	str[4] = "ˮ�������ٱ���������������������⣬";
	str[5] = "����ɢ��Ū���ۡ�";

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C�ļ���׼�Ի���Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C�ļ���׼�Ի���Dlg::OnPaint()
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
		CDC* pDC = GetDC();
	screenx = pDC->GetDeviceCaps(LOGPIXELSX);
	screeny = pDC->GetDeviceCaps(LOGPIXELSY);
	DrawText(pDC,FALSE);
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C�ļ���׼�Ի���Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C�ļ���׼�Ի���Dlg::OnBnClickedButton1()
{
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		"All Files(*.TXT)|*.TXT||",AfxGetMainWnd()); 
	CString strPsth;
	if (dlg.DoModal() == IDOK)
	{
		strPsth = dlg.GetPathName();
		m_ConSta.SetWindowText(strPsth);
		CFile file(strPsth, CFile::modeRead);
		char *p = new char[(int)file.GetLength()];
		file.Read(p, static_cast<int>(file.GetLength()));
		m_strEdit = p;
		delete[] p;
		file.Close();
	}
	UpdateData(FALSE);
}


void C�ļ���׼�Ի���Dlg::OnBnClickedButton2()
{
	CFileDialog dlg(FALSE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		"All Files(*.TXT)|*.TXT||",AfxGetMainWnd());
	CString strPath; //��������                                                        //�����ַ�����
	if(dlg.DoModal() == IDOK)                                                    //�ж��Ƿ��¡����桱��ť
	{
		strPath = dlg.GetPathName();                                            //����ļ�����·��
		if(strPath.Right(4) != ".TXT")                                           //�ж��ļ���չ��
			strPath += ".TXT";                                              //�����ļ���չ��
		m_ConSta.SetWindowText(strPath);  //��ʾ�ļ�·��
		CFile file(strPath,CFile::modeCreate|CFile::modeWrite);  //�����ļ�
		UpdateData(TRUE);//��ñ༭��������
		CString write;
		write = m_strEdit;                                                     //���ַ����������ַ�������
		file.Write(write,m_strEdit.GetLength());                                        //���ļ���д������
		file.Close();                                                        //�ر��ļ�
	}
}


void C�ļ���׼�Ի���Dlg::OnBnClickedButton3()
{
	CFont* TempFont = m_ConEdit.GetFont();
	LOGFONT LogFont;
	TempFont->GetLogFont(&LogFont);
	CFontDialog dlg(&LogFont);
	if (dlg.DoModal() == IDOK)
	{
		m_Font.Detach();                   //��������
		LOGFONT temp;                   //����LOGFONT�ṹָ��
		dlg.GetCurrentFont(&temp);   //��ȡ��ǰ������Ϣ
		m_Font.CreateFontIndirect(&temp);      //ֱ�Ӵ�������
		m_ConEdit.SetFont(&m_Font);    //��������
	}
	// ��������һЩ���ڿؼ�״̬���޸�,����������ļ�����һ�±��棬�´δ򿪵�ʱ�����������ļ��Ϳ�����
	// �����ʱ���Ҫ����һ���������ı��ļ��ǲ����涨�Ƶĸ�ʽ���ģ������ǵı༭�������������������ļ���
	// ��Ҳͬʱ˵���������ļ��ı�Ҫ��
}


void C�ļ���׼�Ի���Dlg::OnBnClickedButton4()
{
	CColorDialog dlg(m_Color);
	if (dlg.DoModal() == IDOK)
	{
		m_Color = dlg.GetColor();
		Invalidate();
	}
}


HBRUSH C�ļ���׼�Ի���Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	if (nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetBkColor(m_Color);
	}
	return hbr;
}

long C�ļ���׼�Ի���Dlg::OnFindReplace(WPARAM wParam, LPARAM lParam)
{
	UpdateData(TRUE);
	CString strStr,repText;							//�����ַ�������
	strStr = dlg->GetFindString();						//��ò����ַ���
	CString str;										//�����ַ�������
	str = m_strEdit;						//��ñ༭�������ı�
	if(dlg->ReplaceCurrent())							//�ж��Ƿ�����滻
		find = FALSE;									//�����滻
	else
		find = TRUE;									//���в���
	int len;											//�������ͱ���
	if(dlg->ReplaceAll())							//�ж��Ƿ�ȫ���滻
	{
		repText = dlg->GetReplaceString();			//����滻�ַ���v
		len    = repText.GetLength();				//����滻�ַ�������
		str.Replace(strStr,repText);				//ʹ���滻�ַ����滻�����ַ���
		m_ConEdit.SetWindowText(str);					//���滻����ַ�����ʾ�ڱ༭����
	}
	if(find)											//�ж��ǲ��һ����滻
	{
		len = strStr.GetLength();						//���Ҫ�����ַ����ĳ���
	}
	else
	{
		CString left,right;							//�����ַ�������
		int num   = strStr.GetLength();			//��ò����ַ����ĳ���
		int strnum = str.GetLength();				//��ñ༭�����ı�����
		int index;									//�������ͱ���
		int ret = str.Find(strStr,0);          // �����������Ƿ��ܹ��ҵ�ƥ����
		if(ret < 0)							// ���������涼û��ƥ��
			return 1;
		if(!degree)									//�ж��Ƿ�Ϊ��һ���滻
			index = str.Find(strStr,nindex);		//��ò����ַ����ڱ༭���ı��е�λ��
 		else if(nindex-rindex >= 0)					//�ж���ʼ����λ���Ƿ�С��0
 			index = str.Find(strStr,nindex-rindex);//��ò����ַ����ڱ༭���ı��е�λ��
   		else
   		{
   			nindex = rindex;						//������ʼ����λ��
   			return 1;
   		}
		degree = TRUE;
		left = str.Left(index);						//����滻�ַ��������ַ���
		right = str.Right(strnum-index-num);		//����滻�ַ����Ҳ���ַ���
		repText = dlg->GetReplaceString();			//����滻�ַ���
		len = repText.GetLength();					//����滻�ַ�������
		rindex = len;
		str = left + repText + right;				//��ϳ��µ��ַ���
		m_ConEdit.SetWindowText(str);					//�ڱ༭������ʾ�µ��ַ���
	}
	int index = str.Find(strStr,nindex);				//��ò����ַ����ڱ༭���ı��е�λ��  �����䵼�������һ�β���(���滻��)Ϊ-1֮��+len��ҪС��len��
	m_ConEdit.SetSel(index,index+len);						//ѡ�в��һ��滻���ַ���
	nindex = index+len;									//������ʼ����λ�á�  ----- ������ע������Խ����һ�����ҵ���Ԫ�ء�����
	m_ConEdit.SetFocus();									//�༭���ý���

	return 0;
}


void C�ļ���׼�Ի���Dlg::OnBnClickedButton5()
{
	dlg = new CFindReplaceDialog;
	dlg->Create(FALSE, NULL);
	dlg->ShowWindow(SW_SHOW);
}


void C�ļ���׼�Ի���Dlg::OnBnClickedButton6()
{
	DWORD dwflags=PD_ALLPAGES | PD_NOPAGENUMS | PD_USEDEVMODECOPIES
		| PD_SELECTION | PD_HIDEPRINTTOFILE; 
	CPrintDialog dlg(FALSE, dwflags);
	if (dlg.DoModal() == IDOK)
	{
		CDC dc;
		dc.Attach(dlg.GetPrinterDC());
		printx = dc.GetDeviceCaps(LOGPIXELSX);
		printy = dc.GetDeviceCaps(LOGPIXELSY);
		ratex = (double)(printx)/screenx;
		ratey = (double)(printy)/screeny;
		DrawText(&dc, TRUE);
	}
}

void C�ļ���׼�Ի���Dlg::DrawText(CDC *pDC, BOOL isprinted)
{
	CFont font;
	if(!isprinted) //Ԥ��
	{
		ratex = 1;
		ratey = 1;
	}
	else //��ӡ
	{
		pDC->StartDoc("printinformation");
	}
	font.CreatePointFont(120,"����",pDC);

	for(int i=0;i<6;i++)
	{
		pDC->SelectObject(&font);
		pDC->TextOut(int(50*ratex),int((50+i*30)*ratey),str[i]);
	}
	if(isprinted)
	{
		pDC->EndDoc();
	}
}



void C�ļ���׼�Ի���Dlg::OnBnClickedButton7()
{
	CString ReturnPach;
	TCHAR szPath[_MAX_PATH];                       //����·������
	BROWSEINFO bi;                                  // BROWSEINFO�ṹ����
	bi.hwndOwner    = NULL;                          //HWND���
	bi.pidlRoot       = NULL;                          //Ĭ��ֵΪNULL
	bi.lpszTitle       = _T("�ļ�����Ի���");          //�Ի������
	bi.pszDisplayName = szPath;                          //ѡ���ļ���·��
	bi.ulFlags        = BIF_RETURNONLYFSDIRS;       //���
	bi.lpfn           = NULL;                          //Ĭ��ֵΪNULL
	bi.lParam         = NULL;                          //�ص���Ϣ
	LPITEMIDLIST pItemIDList = SHBrowseForFolder(&bi);  //��ʾ�ļ�����Ի���
	if(pItemIDList)
	{
		if(SHGetPathFromIDList(pItemIDList,szPath)) //�ж��Ƿ����ļ���·��
			ReturnPach = szPath;	
	}
	else
	{
		ReturnPach = ""; //�ļ���·��Ϊ��
	}
	m_ConSta.SetWindowText(ReturnPach);
}
