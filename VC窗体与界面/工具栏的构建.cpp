// 单文档工具栏构建发生在主框架的OnCreate中
// 如果想要可以悬浮停靠，必须在OnCreate开头有EnableDock(CBRS_ALIGN_ANY);
// 大概构建工具栏有以下几步:1.创建工具栏(包括基本风格)2.工具栏图标列表3.设置工具栏中每一项的按钮风格并初始化4.设置标题
// 5.设置工具栏图标列表 6.设置工具栏的停靠方式7.设置框架的停靠方式8.进行位置确定和停靠




int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
      if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
            return -1;
      //创建工具栏
      if (!m_ToolBar.Create(this, WS_CHILD | WS_VISIBLE | CBRS_SIZE_FIXED |
            CBRS_TOP | CBRS_TOOLTIPS, AFX_IDW_TOOLBAR))
      {
            TRACE0("Failed to create toolbar\n");
            return FALSE;
      }
      m_imagelist.Create(24,24,ILC_COLOR32|ILC_MASK,0,0);                             //创建图像列表
      CString strpath;
      HICON hicon;
      //向类表中添加图像
      for(int j=1;j<10;j++)
      {
            strpath.Format(".\\res\\toolbar\\%02d.ico",j);
            hicon = (HICON)::LoadImage(NULL,strpath,IMAGE_ICON,32,32,LR_LOADFROMFILE);
            m_imagelist.Add(hicon);
      }
      m_ToolBar.SetButtons(NULL,6);                                                                   //设置工具栏按钮
      UINT nStyle;
      //设置工具栏首按钮状态
      m_ToolBar.SetButtonInfo(0,ID_POINTER,TBBS_CHECKGROUP|TBBS_GROUP,0);
      nStyle = m_ToolBar.GetButtonStyle(0);                                                          //获取工具栏按钮的状态
      nStyle &= ~TBBS_WRAPPED;                                                                    //设置工具栏按钮是否另行显示
      m_ToolBar.SetButtonStyle(0, nStyle);                                                                   //设置工具栏按钮样式
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
      m_ToolBar.SetButtonStyle(5, nStyle);                                                                   //设置工具栏按钮
      m_ToolBar.Invalidate();                                                                         //刷新工具栏
      m_ToolBar.GetParentFrame()->RecalcLayout();                                             //重新计算框架内窗体布局
      m_ToolBar.GetToolBarCtrl().SetButtonSize(CSize(31,32));                                      //设置工具栏按钮的大小
      m_ToolBar.GetToolBarCtrl().SetImageList(&m_imagelist);                                      //设置工具栏图标列表
      m_ToolBar.EnableDocking(0);                                                                      //设置工具栏的停靠方式
      EnableDocking(0);                                                                                //设置框架的停靠方式
      m_ToolBar.SetWindowText("工具栏");
      GetWindowRect(&m_rcFloat);
      CPoint point(m_rcFloat.left+100,m_rcFloat.top+100);                                     //计算工具栏显示位置
      FloatControlBar(&m_ToolBar,point,CBRS_ALIGN_LEFT);                              //将工具栏进行浮动显示
      return 0;
}