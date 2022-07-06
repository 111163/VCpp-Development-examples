	RECT rect;
	//设置组合框的宽度，四个参数依次为控件在工具条中的索引号、ID号、风格、宽度 
	m_wndToolBar.SetButtonInfo(10, 32787, TBBS_SEPARATOR, 150 );  // 这里的ID号是自定义设置的，是为了正确的处理命令消息
	//得到组合框的位置										// 风格这个参数要多看看文档，如果是TBBS_SEPARATOR的话，后面150；nStyle是TBBS_SEPARATOR的时候，iImage是指它的宽度，而不是图片的编号
	m_wndToolBar.GetItemRect(10, &rect); 
	//设置组合框的下拉高度 
	rect.bottom += 100;
	//创建组合框，四个参数依次为窗口风格、组合框位置、父窗口、ID号 
	m_combobox.Create(CBS_DROPDOWN|WS_VISIBLE|WS_TABSTOP|CBS_AUTOHSCROLL,rect, &m_wndToolBar,32787);
	//在组合框中加入字符串 
	m_combobox.AddString("第一条记录"); 
	m_combobox.AddString("第二条记录"); 
	//选中第1条记录
	m_combobox.SetCurSel(0);