void C��������ʽ�˵�Dlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	CMenu m_Menu;
	m_Menu.LoadMenu(IDR_MENU1);
	CMenu* pMenu = m_Menu.GetSubMenu(0); // �õ��˵����� �� �����Ǳ����Ҫ��

	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1);
	CBrush m_BKBrush;
	m_BKBrush.CreatePatternBrush(&bmp);

	MENUINFO mnInfo;
	memset(&mnInfo, 0,sizeof(MENUINFO));
	mnInfo.cbSize = sizeof(MENUINFO);
	mnInfo.fMask = MIM_BACKGROUND;
	mnInfo.hbrBack = m_BKBrush;
//	::SetMenuInfo(pMenu->m_hMenu, &mnInfo);   ��VC6.0��û�з�װ���������Ҫֱ�ӵ���
	pMenu->SetMenuInfo(&mnInfo);   // ���ñ���λͼ





	CBitmap            m_BmpList[3];
	for(int i=0; i<3; i++)
	{
		m_BmpList[i].LoadBitmap(IDB_BITMAP2 + i);                       //���ز˵���λͼ
	}
	for (int i = 0; i <2 ;++i)
	{
		pMenu->SetMenuItemBitmaps(i, MF_BYPOSITION, 
			&m_BmpList[i], &m_BmpList[i]);
	}
	pMenu->SetMenuItemBitmaps(3, MF_BYPOSITION, 
		&m_BmpList[2], &m_BmpList[2]);       // ��������ͼ��

	
	// ��Ȼ��������������������ʱ��Ϳ��Լ��ص�ͼ��
	// BOOL AppendMenu( UINT nFlags, UINT nIDNewItem = 0, LPCTSTR lpszNewItem = NULL );
	// BOOL AppendMenu( UINT nFlags, UINT nIDNewItem, const CBitmap* pBmp );

	// BOOL InsertMenu( UINT nPosition, UINT nFlags, UINT nIDNewItem = 0, LPCTSTR lpszNewItem = NULL );
	// BOOL InsertMenu( UINT nPosition, UINT nFlags, UINT nIDNewItem, const CBitmap* pBmp );



	

	CRect rect;                          
	ClientToScreen(&point);
	rect.top = point.x;
	rect.left = point.y;
	pMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_LEFTBUTTON|TPM_VERTICAL, // �����Ҽ�(���)�˵�
		rect.top, rect.left, this, &rect);
	pMenu->DestroyMenu();  // ����Ӧ����ôд����ֹ�ڴ�й©
	CDialogEx::OnRButtonUp(nFlags, point);
}