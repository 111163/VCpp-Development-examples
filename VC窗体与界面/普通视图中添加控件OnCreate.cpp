//应该在视图的OnCreate消息处理函数中做创建工作


int C在视图上添加控件View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rect(50,50,200,200);
	m_List.Create(WS_CHILD|WS_CLIPSIBLINGS|WS_EX_TOOLWINDOW|WS_BORDER, rect, this, 1234);
	m_List.MoveWindow(rect);
	m_List.ShowWindow(SW_SHOW);
	m_List.AddString("既不回头，何必不忘。");
	m_List.AddString("既然无缘，何需誓言。");
	m_List.AddString("今日种种，似水无痕。");
	m_List.AddString("明夕何夕，君已陌路。");

	return 0;
}
