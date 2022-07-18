num最初的定位在本菜单栏的最后一项的ID
void C带历史信息的菜单Dlg::On32771()
{
	CString strText;
	CFileDialog m_File(TRUE, NULL, NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, "All Files(*.*)|*.*|", AfxGetMainWnd());
	if (m_File.DoModal() == IDOK)
	{
		strText = m_File.GetPathName();
	}
	CMenu* m_pMenu = m_Menu.GetSubMenu(0);
	m_pMenu->InsertMenu(2, MF_BYPOSITION, num, strText);
	num++;
}