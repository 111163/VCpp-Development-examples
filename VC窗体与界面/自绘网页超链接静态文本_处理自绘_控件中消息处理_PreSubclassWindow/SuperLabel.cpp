// SuperLabel.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�Ի���ҳ�����Ӿ�̬�ı�.h"
#include "SuperLabel.h"
#include "Resource.h"


// CSuperLabel

IMPLEMENT_DYNAMIC(CSuperLabel, CStatic)

CSuperLabel::CSuperLabel()
{

}

CSuperLabel::~CSuperLabel()
{
}


BEGIN_MESSAGE_MAP(CSuperLabel, CStatic)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// CSuperLabel ��Ϣ�������




void CSuperLabel::PreSubclassWindow()
{
	// TODO: �ڴ����ר�ô����/����û���
	GetWindowText(m_ConnectStr);
	CFont* pFont = GetFont();

	pFont->GetLogFont(&lfont);
	lfont.lfUnderline =TRUE;
	m_Font.CreateFontIndirect(&lfont);
	CStatic::PreSubclassWindow();
}


void CSuperLabel::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CStatic::OnPaint()
	CDC* pDC = GetDC();

	CString text;
	GetWindowText(text);

	if (m_ConnectStr.IsEmpty())
		m_ConnectStr = text;

	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(RGB(0,0,255));


	pDC->SelectObject(&m_Font);
	pDC->TextOut(0,0,text);

}


void CSuperLabel::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ShellExecute(m_hWnd,NULL,m_ConnectStr,NULL,NULL,SW_SHOW);		
	CStatic::OnLButtonDown(nFlags, point);
}


void CSuperLabel::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
	CStatic::OnMouseMove(nFlags, point);
}
