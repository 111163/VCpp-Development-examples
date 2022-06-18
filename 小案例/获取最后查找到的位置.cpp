// 我们可能要问了到底什么时候用Find，什么时候用++直接比较呢？
// 如果查找的是字符的话，就用==直接比较
// 而如果不确定要查找的到底是几个字符的话用Find函数比较好(当然Find的内部实现还是++比较)

void CGetStringLastPosDlg::OnGet() 
{
      CString strtxt,strchar,strres;
      GetDlgItem(IDC_TEXT)->GetWindowText(strtxt);
      GetDlgItem(IDC_CHAR)->GetWindowText(strchar);
      int pos=strtxt.Find(strchar);
      int leftpos=0,tmp;
      if(pos<0)
      {
            MessageBox("没有找到指定字符");
            return;
      }
      while(pos>=0)
      {
            if(IsDBCSLeadByte(strtxt.GetAt(pos)))
            {
                  strtxt=strtxt.Right(strtxt.GetLength()-pos-2);
                  leftpos+=(pos+2);
                  tmp=leftpos-2;
            }
            else
            {
                  strtxt=strtxt.Right(strtxt.GetLength()-pos-1);  // 这里取右边，就是查找到的串的右边
                  leftpos+=(pos+1);				  // 这个参数就是下一次开始的位置
                  tmp=leftpos-1;				  // 这个参数是出现要查找目标的开始位置
            }               					  // 如果将tmp保存起来就是要目标的所有开始位置
            pos=strtxt.Find(strchar);
            if(pos<0)
            {
                  strres.Format("最后一次出现的位置：%d",tmp);
                  MessageBox(strres,"结果",MB_OK);
            }
      }
}

