//Ӧ������ͼ��OnCreate��Ϣ������������������


int C����ͼ����ӿؼ�View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rect(50,50,200,200);
	m_List.Create(WS_CHILD|WS_CLIPSIBLINGS|WS_EX_TOOLWINDOW|WS_BORDER, rect, this, 1234);
	m_List.MoveWindow(rect);
	m_List.ShowWindow(SW_SHOW);
	m_List.AddString("�Ȳ���ͷ���αز�����");
	m_List.AddString("��Ȼ��Ե���������ԡ�");
	m_List.AddString("�������֣���ˮ�޺ۡ�");
	m_List.AddString("��Ϧ��Ϧ������İ·��");

	return 0;
}
