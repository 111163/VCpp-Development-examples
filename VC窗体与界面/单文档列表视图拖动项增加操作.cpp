下面通过实例在视图窗口中实现数据拖动，程序设置步骤如下：
（1）创建一个单文档应用程序，在应用程序向导第6步中将视图的基类改为CListView。
（2）在视图类的头文件中声明变量，代码如下。
      int               m_ItmIndex;                                                 //列表项索引
      CImageList*      m_pDrgImg;                                                  //拖动图像列表
      BOOL         m_Drag;                                                       //是否拖动
（3）在视图类的OnInitialUpdate函数中为视图添加数据信息，代码如下。
void CDragViewView::OnInitialUpdate()
{
      CListView::OnInitialUpdate();
      CListCtrl* pListCtl=&GetListCtrl();
      pListCtl->ModifyStyle(0L,LVS_REPORT);
      pListCtl->SetExtendedStyle(LVS_EX_FLATSB                        //扁平风格显示滚动条
            |LVS_EX_FULLROWSELECT                                           //允许整行选中
            |LVS_EX_HEADERDRAGDROP                                   //允许整列拖动
            |LVS_EX_ONECLICKACTIVATE                                  //单击选中项
            |LVS_EX_GRIDLINES);                                                 //画出网格线
      //设置列标题及列宽
      pListCtl->InsertColumn(0,"员工编号",LVCFMT_LEFT,100);
      pListCtl->InsertColumn(1,"员工姓名",LVCFMT_LEFT,100);
      pListCtl->InsertColumn(2,"文化程度",LVCFMT_LEFT,100);
      pListCtl->InsertItem(0,"0001");                                               //插入第0行
      pListCtl->SetItemText(0,1,"赵一");                                                 //向第0行第1列插入数据
      pListCtl->SetItemText(0,2,"专科");                                                 //向第0行第2列插入数据
      pListCtl->InsertItem(1,"0002");                                               //插入第1行
      pListCtl->SetItemText(1,1,"钱二");                                                 //向第1行第1列插入数据
      pListCtl->SetItemText(1,2,"本科");                                                 //向第1行第2列插入数据
      pListCtl->InsertItem(2,"0003");                                               //插入第2行
      pListCtl->SetItemText(2,1,"孙三");                                                 //向第2行第1列插入数据
      pListCtl->SetItemText(2,2,"研究生");                                             //向第2行第2列插入数据
}
（4）处理视图类的LVN_BEGINDRAG消息，在该消息的处理函数中开始拖动，代码如下。
void CDragViewView::OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult) 
{
      NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
      POINT pt;                                                                      //声明POINT对象
      m_ItmIndex  = ((NM_LISTVIEW *)pNMHDR)->iItem;                  //获得节点索引
      m_pDrgImg  = GetListCtrl().CreateDragImage(m_ItmIndex,&pt);    //创建拖动图像列表
      m_pDrgImg->BeginDrag(0,pt);                                                //开始拖动
      m_pDrgImg->DragEnter(this,pt);                                      //禁止视图更新
      m_Drag = TRUE;                                                            //拖动中
      *pResult = 0;
}
（5）处理视图类的WM_MOUSEMOVE消息，在该消息的处理函数中随着鼠标的移动位置更新拖动图像的位置，代码如下。
void CDragViewView::OnMouseMove(UINT nFlags, CPoint point) 
{
      if(m_Drag)                                                              //判断是否在拖动中
      {
            CPoint pt;                                                                 //声明Cpoint对象
            pt.x = point.x;                                                           //设置拖动图像左上角横坐标
            pt.y = point.y + (m_ItmIndex + 1) * 15;                             //设置拖动图像左上角纵坐标
            m_pDrgImg->DragMove(pt);                                            //一定拖动图像
      }
      CListView::OnMouseMove(nFlags, point);
}
（6）处理视图类的WM_LBUTTONUP消息，在该消息的处理函数中结束拖动，并将拖动的数据添加到视图中，代码如下。
void CDragViewView::OnLButtonUp(UINT nFlags, CPoint point) 
{
      if(m_Drag)                                                              //判断是否在拖动中
      {
            m_pDrgImg->EndDrag();                                                 //结束拖动
            m_Drag = FALSE;                                                    //设置为不拖动
            char name[256];                                                 //声明字符数组
            LV_ITEM lvi;                                                           //声明LV_ITEM结构变量
            CString subitem[3];                                                   //声明字符串数组
            for(int i=2;i>=0;i--)                                                    //循环获得数据
            {
                  ZeroMemory(&lvi,sizeof(LV_ITEM));                                 //整理内存控件
                  lvi.iItem       = m_ItmIndex;                                         //设置行
                  lvi.iSubItem = i;                                           //设置列
                  lvi.mask            = LVIF_IMAGE | LVIF_TEXT;                  //标志
                  lvi.pszText   = name;                                     //列表项内容
                  lvi.cchTextMax  = 255;                                        //文本最大值
                  GetListCtrl().GetItem(&lvi);                                        //获得节点
                  subitem[i].Format("%s",name);                                    //设置显示文本
            }
            GetListCtrl().InsertItem(&lvi);                                           //插入行
            GetListCtrl().SetItemText(m_ItmIndex,1,subitem[1]);                 //插入列
            GetListCtrl().SetItemText(m_ItmIndex,2,subitem[2]);                 //插入列
      }
      CListView::OnLButtonUp(nFlags, point);
}