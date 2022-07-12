// LevelStatic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�Ի澲̬�ı�.h"
#include "LevelStatic.h"


// CLevelStatic

IMPLEMENT_DYNAMIC(CLevelStatic, CStatic)

CLevelStatic::CLevelStatic()
{
	m_TextMargin = 2;
}

CLevelStatic::~CLevelStatic()
{
}


BEGIN_MESSAGE_MAP(CLevelStatic, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CLevelStatic ��Ϣ�������




void CLevelStatic::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CStatic::OnPaint()
	CRect   rectWnd; 
	CString cstrText; 
	UINT    uFormat;  
	GetWindowText(cstrText);                                 //��þ�̬�ı��ؼ�����ʾ�ı�
	dc.SelectObject(GetFont());                               //ѡ�е�ǰ�ؼ�����
	CSize size = dc.GetTextExtent(cstrText);                    //�����ı��Ŀ�Ⱥ͸߶�
	DWORD    dwStyle = GetStyle();                           //��ȡ�ؼ����
	GetWindowRect (rectWnd);                        //��ô�������
	uFormat = DT_TOP;
	if ( dwStyle & SS_NOPREFIX )
		uFormat |= DT_NOPREFIX;
	//�����ı������
	dc.Draw3dRect(0, rectWnd.Height()/2,(rectWnd.Width()-size.cx)/2-m_TextMargin
		, 2, ::GetSysColor(COLOR_3DSHADOW),::GetSysColor(COLOR_3DHIGHLIGHT) );
	dc.SetBkMode(TRANSPARENT);
	//�����ı�
	dc.DrawText(cstrText,CRect((rectWnd.Width()-size.cx)/2,0,(rectWnd.Width()-size.cx)/2
		+size.cx,size.cy),DT_LEFT|DT_SINGLELINE|DT_VCENTER );
	//�����ı��ұ���
	dc.Draw3dRect((rectWnd.Width()-size.cx)/2+size.cx , rectWnd.Height()/2
		,(rectWnd.Width()-size.cx)/2-m_TextMargin, 2, ::GetSysColor(COLOR_3DSHADOW),
		::GetSysColor(COLOR_3DHIGHLIGHT) );  

}
