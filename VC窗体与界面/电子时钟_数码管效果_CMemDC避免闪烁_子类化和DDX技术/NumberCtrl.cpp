// NumberCtrl.cpp : 实现文件
//

#include "stdafx.h"
#include "电子时钟.h"
#include "NumberCtrl.h"


// CNumberCtrl

IMPLEMENT_DYNAMIC(CNumberCtrl, CStatic)

CNumberCtrl::CNumberCtrl()
{
	m_csText = "";
	m_nNumberWidth = 26;
	m_nNumberHeight = 34;
	m_nNumberLen = 8;
}

CNumberCtrl::~CNumberCtrl()
{
}


BEGIN_MESSAGE_MAP(CNumberCtrl, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CNumberCtrl 消息处理程序




void CNumberCtrl::OnPaint() 
{
	CPaintDC dc(this);
	CRect clientRC;
	GetClientRect(clientRC);							//获取窗口客户区域
	CMemDC memDC1(dc, clientRC);					//定义内存画布    CMemDC类避免频繁绘图闪烁现象

	SetWindowText("");
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP2);					//加载位图
	CDC tmpDC;
	tmpDC.CreateCompatibleDC(&dc);					//创建一个兼容的设备上下文
	tmpDC.SelectObject(&bmp);							//选中位图对象
	BITMAP bInfo;									//定义位图信息
	bmp.GetBitmap(&bInfo);							//获取位图信息
	int nbmpWidth = bInfo.bmWidth;						//获取位图宽度
	int nbmpHeight = bInfo.bmHeight;						//获取位图高度
	int nLen = m_csText.GetLength();						//获取文本长度
	CDC& memDC = memDC1.GetDC();
	for (int i=0; i<m_nNumberLen; i++)					//这里绘制的是 :
	{
		memDC.BitBlt((i)*m_nNumberWidth, 0, m_nNumberWidth, nbmpHeight, 
			&tmpDC, 10*m_nNumberWidth, 0, SRCCOPY);
	}
	if (nLen>0 && nLen<=m_nNumberLen)					//判断数字是否合法
	{
		for (int n=0; n<nLen; n++)          
		{
			char ch = m_csText[nLen-n-1];  
			if (ch == ':' ) // 这里实际上是透明
			{
				memDC.BitBlt((m_nNumberLen-10)*m_nNumberWidth, 0, m_nNumberWidth,
					nbmpHeight, &tmpDC, m_nNumberWidth, 0, SRCCOPY);
			}
			else
			{
				int nCh = atoi(&ch);
				//绘制数字位图
				memDC.BitBlt((m_nNumberLen-n-1)*m_nNumberWidth, 0, m_nNumberWidth,
					nbmpHeight, &tmpDC, (nCh)*m_nNumberWidth, 0, SRCCOPY);
			}
		}
	}
	bmp.DeleteObject();								//删除位图对象
	tmpDC.DeleteDC();
}

void CNumberCtrl::SetText(LPCTSTR text)
{
	m_csText = text;
	RedrawWindow();
}

LPTSTR CNumberCtrl::GetText()
{
	return m_csText.GetBuffer(0);
}

void CNumberCtrl::SubClassCtrl(UINT uID, CWnd *pParent)
{
	SubclassDlgItem(uID, pParent);						//子类化对象
	CRect winRC;
	GetWindowRect(winRC);							//获取窗口区域
	ScreenToClient(winRC);
	MapWindowPoints(pParent,winRC);					//将窗口坐标映射到父窗口中
	winRC.right = winRC.left+m_nNumberLen*m_nNumberWidth;//设置窗口宽度
	winRC.bottom = winRC.top+m_nNumberHeight;			//设置窗口高度
	MoveWindow(winRC);								//设置控件显示的位置
}
