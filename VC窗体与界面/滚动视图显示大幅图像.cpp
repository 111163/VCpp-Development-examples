������ͼ��ʾ���ͼ��
// Cʹ�ù�����ͼ��ʾͼ��View ����

void Cʹ�ù�����ͼ��ʾͼ��View::OnDraw(CDC* pDC)
{
	Cʹ�ù�����ͼ��ʾͼ��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CBitmap m_Bitmip;
	m_Bitmip.LoadBitmap(IDB_BITMAP1);

	CDC memDc;
	memDc.CreateCompatibleDC(pDC); // �����ڴ�DC�ͻ���������
	memDc.SelectObject(&m_Bitmip); // ���û�ͼ����

	BITMAP m_Bmp;
	m_Bitmip.GetBitmap(&m_Bmp);
	int x = m_Bmp.bmWidth;
	int y = m_Bmp.bmHeight;

	//CRect rect;
	//GetClientRect(rect);

	pDC->BitBlt(0,0,x,y,&memDc, 0,0,SRCCOPY);
	memDc.DeleteDC();
}

void Cʹ�ù�����ͼ��ʾͼ��View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �������ͼ�ĺϼƴ�С
	sizeTotal.cx = 2000;    //  �����ܷ���ͼ��Ĵ�С
	sizeTotal.cy = 1500;
	SetScrollSizes(MM_TEXT, sizeTotal);
}