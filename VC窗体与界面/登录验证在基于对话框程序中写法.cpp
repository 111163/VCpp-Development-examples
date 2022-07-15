1.写在主窗体的OnInitDialog方法中，代码如下:
     CLogin dlg;              //定义登录窗体类变量
      if(dlg.DoModal() != IDOK)   //模式显示登录窗体
      {
            OnOK();                  //返回值不为IDOK关闭主窗体
      }
      return TRUE;

2.登录窗体的显示也不一定写在主窗体的OnInitDialog方法中，也可以写在应用程序类的InitInstance方法中，但必须在主窗体显示前，代码如下：
      CShowLoginDlg dlg;
      m_pMainWnd = &dlg;
 
      CLogin dlg;  //定义登录窗体类变量
      if(dlg.DoModal() == IDOK)  //模式显示登录窗体
      {
            int nResponse = dlg.DoModal();      //显示主窗体
      }


// 正确的处理一下IDOK和IDCANCEL   ---就是在这两个按钮中做验证和调用父类CDialog::方法从而退出