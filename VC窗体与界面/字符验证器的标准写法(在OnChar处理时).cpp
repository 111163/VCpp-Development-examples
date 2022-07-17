void CEditChar::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nChar == 8 || nChar == ' ')
	{
		CEdit::OnChar(nChar, nRepCnt, nFlags);
		return;
	}
	if ((nChar < 'a' || nChar > 'z')&&(nChar < 'A' || nChar > 'Z') )
	{
		nChar = 0;
	}
	else
		CEdit::OnChar(nChar, nRepCnt, nFlags);
}

// 有实际写法有好多种，但你以后就只需这样规范
// 当然也可以在PreTranslateMessage中做处理