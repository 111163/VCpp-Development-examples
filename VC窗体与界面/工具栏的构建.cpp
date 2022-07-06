// ���ĵ���������������������ܵ�OnCreate��
// �����Ҫ��������ͣ����������OnCreate��ͷ��EnableDock(CBRS_ALIGN_ANY);
// ��Ź��������������¼���:1.����������(�����������)2.������ͼ���б�3.���ù�������ÿһ��İ�ť��񲢳�ʼ��4.���ñ���
// 5.���ù�����ͼ���б� 6.���ù�������ͣ����ʽ7.���ÿ�ܵ�ͣ����ʽ8.����λ��ȷ����ͣ��




int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
      if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
            return -1;
      //����������
      if (!m_ToolBar.Create(this, WS_CHILD | WS_VISIBLE | CBRS_SIZE_FIXED |
            CBRS_TOP | CBRS_TOOLTIPS, AFX_IDW_TOOLBAR))
      {
            TRACE0("Failed to create toolbar\n");
            return FALSE;
      }
      m_imagelist.Create(24,24,ILC_COLOR32|ILC_MASK,0,0);                             //����ͼ���б�
      CString strpath;
      HICON hicon;
      //����������ͼ��
      for(int j=1;j<10;j++)
      {
            strpath.Format(".\\res\\toolbar\\%02d.ico",j);
            hicon = (HICON)::LoadImage(NULL,strpath,IMAGE_ICON,32,32,LR_LOADFROMFILE);
            m_imagelist.Add(hicon);
      }
      m_ToolBar.SetButtons(NULL,6);                                                                   //���ù�������ť
      UINT nStyle;
      //���ù������װ�ť״̬
      m_ToolBar.SetButtonInfo(0,ID_POINTER,TBBS_CHECKGROUP|TBBS_GROUP,0);
      nStyle = m_ToolBar.GetButtonStyle(0);                                                          //��ȡ��������ť��״̬
      nStyle &= ~TBBS_WRAPPED;                                                                    //���ù�������ť�Ƿ�������ʾ
      m_ToolBar.SetButtonStyle(0, nStyle);                                                                   //���ù�������ť��ʽ
      m_ToolBar.SetButtonInfo(1,ID_PEN,TBBS_CHECKGROUP,1);
      nStyle = m_ToolBar.GetButtonStyle(1);
      nStyle &= ~TBBS_WRAPPED;
      m_ToolBar.SetButtonStyle(1, nStyle);
      m_ToolBar.SetButtonInfo(2,ID_RECTANGLE,TBBS_CHECKGROUP,2);
      nStyle = m_ToolBar.GetButtonStyle(2);
      nStyle |= TBBS_WRAPPED;
      m_ToolBar.SetButtonStyle(2, nStyle);
      m_ToolBar.SetButtonInfo(3,ID_PARALLE,TBBS_CHECKGROUP,3);
      nStyle = m_ToolBar.GetButtonStyle(3);
      nStyle &= ~TBBS_WRAPPED;
      m_ToolBar.SetButtonStyle(3, nStyle);
      m_ToolBar.SetButtonInfo(4,ID_ROUND,TBBS_CHECKGROUP,4);
      nStyle = m_ToolBar.GetButtonStyle(4);
      nStyle &= ~TBBS_WRAPPED;
      m_ToolBar.SetButtonStyle(4, nStyle);
      m_ToolBar.SetButtonInfo(5,ID_ROUNDRECT,TBBS_CHECKGROUP,5);
      nStyle = m_ToolBar.GetButtonStyle(5);
      nStyle |= TBBS_WRAPPED;
      m_ToolBar.SetButtonStyle(5, nStyle);                                                                   //���ù�������ť
      m_ToolBar.Invalidate();                                                                         //ˢ�¹�����
      m_ToolBar.GetParentFrame()->RecalcLayout();                                             //���¼������ڴ��岼��
      m_ToolBar.GetToolBarCtrl().SetButtonSize(CSize(31,32));                                      //���ù�������ť�Ĵ�С
      m_ToolBar.GetToolBarCtrl().SetImageList(&m_imagelist);                                      //���ù�����ͼ���б�
      m_ToolBar.EnableDocking(0);                                                                      //���ù�������ͣ����ʽ
      EnableDocking(0);                                                                                //���ÿ�ܵ�ͣ����ʽ
      m_ToolBar.SetWindowText("������");
      GetWindowRect(&m_rcFloat);
      CPoint point(m_rcFloat.left+100,m_rcFloat.top+100);                                     //���㹤������ʾλ��
      FloatControlBar(&m_ToolBar,point,CBRS_ALIGN_LEFT);                              //�����������и�����ʾ
      return 0;
}