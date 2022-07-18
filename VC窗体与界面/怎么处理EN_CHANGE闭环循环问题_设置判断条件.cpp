处理两个编辑框控件的EN_CHANGE事件，代码如下。
void CChangeEditDlg::OnChangeEdit1() 
{
      CString str1,str2;
      m_Edit1.GetWindowText(str1);                                 //获得编辑框1中的数据
      m_Edit2.GetWindowText(str2);                                 //获得编辑框2中的数据
      if(str1 == str2)                                                         //如果两个控件中数据相同
            return;
      else                                                                         //如果不相同
            m_Edit2.SetWindowText(str1);                           //将获得的数据设置为编辑框2的显示数据
}
 
void CChangeEditDlg::OnChangeEdit2() 
{
      CString str1,str2;
      m_Edit1.GetWindowText(str1);                                 //获得编辑框1中的数据
      m_Edit2.GetWindowText(str2);                                 //获得编辑框2中的数据
      if(str1 == str2)                                                         //如果两个控件中数据相同
            return;
      else                                                                         //如果不相同
            m_Edit1.SetWindowText(str2);                           //将获得的数据设置为编辑框1的显示数据
}


// 可以知道如果不在EN_CHANGE中设置判定条件的话，就会形成EN_CHANGE闭环，导致无限调用
// 只有设置条件让这个环断开才能避免这个问题