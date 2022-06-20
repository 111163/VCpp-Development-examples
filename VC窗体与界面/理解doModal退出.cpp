它和你点按钮是没有关系的，关键是你的ID 和系统预先定好的是一致的（当然你也可以设置为不一致），如果你没有写关于这个ID 的控件的消息响应的话，它就会根据ID 在命令消息中查找的到到的是调用哪个预置的响应函数来响应

源码位于 dlgcore.cpp文件中
void CDialog::EndDialog(int nResult)
{
	ASSERT(::IsWindow(m_hWnd));

	if (m_nFlags & (WF_MODALLOOP|WF_CONTINUEMODAL))
		EndModalLoop(nResult);

	::EndDialog(m_hWnd, nResult);
}

void CDialog::OnOK()
{
	if (!UpdateData(TRUE))
	{
		TRACE(traceAppMsg, 0, "UpdateData failed during dialog termination.\n");
		// the UpdateData routine will set focus to correct item
		return;
	}
	EndDialog(IDOK);
}

void CDialog::OnCancel()
{
	EndDialog(IDCANCEL);
}


那么了解它的意义有什么用呢？就是说返回的是EndDialog设定的值，而不是某个控件的ID
你大可以自己调用EndDialog传回一个你定制的值
通过不同的值，就知道了到底是点击了那个按钮导致的退出，以及对下一步的工作进行指导
并且应该知道是底层封装的::::EndDialog(m_hWnd, nResult);让你的模态对话框退出的
