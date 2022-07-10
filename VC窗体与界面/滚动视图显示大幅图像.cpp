滚动视图显示大幅图像
// C使用滚动视图显示图像View 绘制

void C使用滚动视图显示图像View::OnDraw(CDC* pDC)
{
	C使用滚动视图显示图像Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CBitmap m_Bitmip;
	m_Bitmip.LoadBitmap(IDB_BITMAP1);

	CDC memDc;
	memDc.CreateCompatibleDC(pDC); // 关联内存DC和环境上下文
	memDc.SelectObject(&m_Bitmip); // 设置绘图对象

	BITMAP m_Bmp;
	m_Bitmip.GetBitmap(&m_Bmp);
	int x = m_Bmp.bmWidth;
	int y = m_Bmp.bmHeight;

	//CRect rect;
	//GetClientRect(rect);

	pDC->BitBlt(0,0,x,y,&memDc, 0,0,SRCCOPY);
	memDc.DeleteDC();
}

void C使用滚动视图显示图像View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = 2000;    //  期望能放下图像的大小
	sizeTotal.cy = 1500;
	SetScrollSizes(MM_TEXT, sizeTotal);
}