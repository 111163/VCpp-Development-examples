num����Ķ�λ�ڱ��˵��������һ���ID
void C����ʷ��Ϣ�Ĳ˵�Dlg::On32771()
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