void C创建弹出式菜单Dlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	CMenu m_Menu;
	m_Menu.LoadMenu(IDR_MENU1);
	CMenu* pMenu = m_Menu.GetSubMenu(0); // 得到菜单项句柄 ★ 这里是必须必要的

	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1);
	CBrush m_BKBrush;
	m_BKBrush.CreatePatternBrush(&bmp);

	MENUINFO mnInfo;
	memset(&mnInfo, 0,sizeof(MENUINFO));
	mnInfo.cbSize = sizeof(MENUINFO);
	mnInfo.fMask = MIM_BACKGROUND;
	mnInfo.hbrBack = m_BKBrush;
//	::SetMenuInfo(pMenu->m_hMenu, &mnInfo);   在VC6.0中没有封装这个函数，要直接调用
	pMenu->SetMenuInfo(&mnInfo);   // 设置背景位图





	CBitmap            m_BmpList[3];
	for(int i=0; i<3; i++)
	{
		m_BmpList[i].LoadBitmap(IDB_BITMAP2 + i);                       //加载菜单项位图
	}
	for (int i = 0; i <2 ;++i)
	{
		pMenu->SetMenuItemBitmaps(i, MF_BYPOSITION, 
			&m_BmpList[i], &m_BmpList[i]);
	}
	pMenu->SetMenuItemBitmaps(3, MF_BYPOSITION, 
		&m_BmpList[2], &m_BmpList[2]);       // 设置子项图标

	
	// 当然本身添加子项或插入子项的时候就可以加载到图标
	// BOOL AppendMenu( UINT nFlags, UINT nIDNewItem = 0, LPCTSTR lpszNewItem = NULL );
	// BOOL AppendMenu( UINT nFlags, UINT nIDNewItem, const CBitmap* pBmp );

	// BOOL InsertMenu( UINT nPosition, UINT nFlags, UINT nIDNewItem = 0, LPCTSTR lpszNewItem = NULL );
	// BOOL InsertMenu( UINT nPosition, UINT nFlags, UINT nIDNewItem, const CBitmap* pBmp );



	

	CRect rect;                          
	ClientToScreen(&point);
	rect.top = point.x;
	rect.left = point.y;
	pMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_LEFTBUTTON|TPM_VERTICAL, // 弹出右键(快捷)菜单
		rect.top, rect.left, this, &rect);
	pMenu->DestroyMenu();  // 这里应该这么写，防止内存泄漏
	CDialogEx::OnRButtonUp(nFlags, point);
}