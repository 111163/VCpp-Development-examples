����ͨ��ʵ������ͼ������ʵ�������϶����������ò������£�
��1������һ�����ĵ�Ӧ�ó�����Ӧ�ó����򵼵�6���н���ͼ�Ļ����ΪCListView��
��2������ͼ���ͷ�ļ��������������������¡�
      int               m_ItmIndex;                                                 //�б�������
      CImageList*      m_pDrgImg;                                                  //�϶�ͼ���б�
      BOOL         m_Drag;                                                       //�Ƿ��϶�
��3������ͼ���OnInitialUpdate������Ϊ��ͼ���������Ϣ���������¡�
void CDragViewView::OnInitialUpdate()
{
      CListView::OnInitialUpdate();
      CListCtrl* pListCtl=&GetListCtrl();
      pListCtl->ModifyStyle(0L,LVS_REPORT);
      pListCtl->SetExtendedStyle(LVS_EX_FLATSB                        //��ƽ�����ʾ������
            |LVS_EX_FULLROWSELECT                                           //��������ѡ��
            |LVS_EX_HEADERDRAGDROP                                   //���������϶�
            |LVS_EX_ONECLICKACTIVATE                                  //����ѡ����
            |LVS_EX_GRIDLINES);                                                 //����������
      //�����б��⼰�п�
      pListCtl->InsertColumn(0,"Ա�����",LVCFMT_LEFT,100);
      pListCtl->InsertColumn(1,"Ա������",LVCFMT_LEFT,100);
      pListCtl->InsertColumn(2,"�Ļ��̶�",LVCFMT_LEFT,100);
      pListCtl->InsertItem(0,"0001");                                               //�����0��
      pListCtl->SetItemText(0,1,"��һ");                                                 //���0�е�1�в�������
      pListCtl->SetItemText(0,2,"ר��");                                                 //���0�е�2�в�������
      pListCtl->InsertItem(1,"0002");                                               //�����1��
      pListCtl->SetItemText(1,1,"Ǯ��");                                                 //���1�е�1�в�������
      pListCtl->SetItemText(1,2,"����");                                                 //���1�е�2�в�������
      pListCtl->InsertItem(2,"0003");                                               //�����2��
      pListCtl->SetItemText(2,1,"����");                                                 //���2�е�1�в�������
      pListCtl->SetItemText(2,2,"�о���");                                             //���2�е�2�в�������
}
��4��������ͼ���LVN_BEGINDRAG��Ϣ���ڸ���Ϣ�Ĵ������п�ʼ�϶����������¡�
void CDragViewView::OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult) 
{
      NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
      POINT pt;                                                                      //����POINT����
      m_ItmIndex  = ((NM_LISTVIEW *)pNMHDR)->iItem;                  //��ýڵ�����
      m_pDrgImg  = GetListCtrl().CreateDragImage(m_ItmIndex,&pt);    //�����϶�ͼ���б�
      m_pDrgImg->BeginDrag(0,pt);                                                //��ʼ�϶�
      m_pDrgImg->DragEnter(this,pt);                                      //��ֹ��ͼ����
      m_Drag = TRUE;                                                            //�϶���
      *pResult = 0;
}
��5��������ͼ���WM_MOUSEMOVE��Ϣ���ڸ���Ϣ�Ĵ����������������ƶ�λ�ø����϶�ͼ���λ�ã��������¡�
void CDragViewView::OnMouseMove(UINT nFlags, CPoint point) 
{
      if(m_Drag)                                                              //�ж��Ƿ����϶���
      {
            CPoint pt;                                                                 //����Cpoint����
            pt.x = point.x;                                                           //�����϶�ͼ�����ϽǺ�����
            pt.y = point.y + (m_ItmIndex + 1) * 15;                             //�����϶�ͼ�����Ͻ�������
            m_pDrgImg->DragMove(pt);                                            //һ���϶�ͼ��
      }
      CListView::OnMouseMove(nFlags, point);
}
��6��������ͼ���WM_LBUTTONUP��Ϣ���ڸ���Ϣ�Ĵ������н����϶��������϶���������ӵ���ͼ�У��������¡�
void CDragViewView::OnLButtonUp(UINT nFlags, CPoint point) 
{
      if(m_Drag)                                                              //�ж��Ƿ����϶���
      {
            m_pDrgImg->EndDrag();                                                 //�����϶�
            m_Drag = FALSE;                                                    //����Ϊ���϶�
            char name[256];                                                 //�����ַ�����
            LV_ITEM lvi;                                                           //����LV_ITEM�ṹ����
            CString subitem[3];                                                   //�����ַ�������
            for(int i=2;i>=0;i--)                                                    //ѭ���������
            {
                  ZeroMemory(&lvi,sizeof(LV_ITEM));                                 //�����ڴ�ؼ�
                  lvi.iItem       = m_ItmIndex;                                         //������
                  lvi.iSubItem = i;                                           //������
                  lvi.mask            = LVIF_IMAGE | LVIF_TEXT;                  //��־
                  lvi.pszText   = name;                                     //�б�������
                  lvi.cchTextMax  = 255;                                        //�ı����ֵ
                  GetListCtrl().GetItem(&lvi);                                        //��ýڵ�
                  subitem[i].Format("%s",name);                                    //������ʾ�ı�
            }
            GetListCtrl().InsertItem(&lvi);                                           //������
            GetListCtrl().SetItemText(m_ItmIndex,1,subitem[1]);                 //������
            GetListCtrl().SetItemText(m_ItmIndex,2,subitem[2]);                 //������
      }
      CListView::OnLButtonUp(nFlags, point);
}