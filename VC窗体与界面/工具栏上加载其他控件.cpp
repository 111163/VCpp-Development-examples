	RECT rect;
	//������Ͽ�Ŀ�ȣ��ĸ���������Ϊ�ؼ��ڹ������е������š�ID�š���񡢿�� 
	m_wndToolBar.SetButtonInfo(10, 32787, TBBS_SEPARATOR, 150 );  // �����ID�����Զ������õģ���Ϊ����ȷ�Ĵ���������Ϣ
	//�õ���Ͽ��λ��										// ����������Ҫ�࿴���ĵ��������TBBS_SEPARATOR�Ļ�������150��nStyle��TBBS_SEPARATOR��ʱ��iImage��ָ���Ŀ�ȣ�������ͼƬ�ı��
	m_wndToolBar.GetItemRect(10, &rect); 
	//������Ͽ�������߶� 
	rect.bottom += 100;
	//������Ͽ��ĸ���������Ϊ���ڷ����Ͽ�λ�á������ڡ�ID�� 
	m_combobox.Create(CBS_DROPDOWN|WS_VISIBLE|WS_TABSTOP|CBS_AUTOHSCROLL,rect, &m_wndToolBar,32787);
	//����Ͽ��м����ַ��� 
	m_combobox.AddString("��һ����¼"); 
	m_combobox.AddString("�ڶ�����¼"); 
	//ѡ�е�1����¼
	m_combobox.SetCurSel(0);