模式对话框和非模式对话框可以看得见的区别是:是否可以操作父窗口


本质原因是:
建模态对话框时，系统会首先将此模态窗口的父窗口disable掉。然后这些API内部会新启动和运行一个消息泵的循环，另外这些API会要求传入一个对话框窗口过程，从新启动的消息循环得到的消息会派发到这个窗口过程。也就是说这个模态对话框有一个单独的消息循环和窗口过程，不同于主线程的消息循环和窗口过程。在用户点击OK、Cancel或者Close按钮之前，程序一直运行在模态对话框的消息循环里，当点击了这些按钮后退出此循环，创建函数返回，重新回到主线程的消息循环里，这时父窗口就可以响应了。
创建非模态对话框时，在这些API内部不会重新启动消息循环，而是创建了非模态对话框之后就立刻返回，此对话框使用主线程的消息循环，此时运行在主消息循环中，从用户角度来看，父窗口也是可以响应的。


基于上面的原因，造成了一个结果就是非模式对话框必须重写OnOK,OnCancel,PostNcDestroy
OnOK和OnCanCel调用DestroyWindow函数来销毁窗口
PostNcDestroy先调用父类的 CDialogEx::PostNcDestroy();然后 delete this;销毁本身类

void dlgNoModal::OnOK()
{
	DestroyWindow();
}


void dlgNoModal::OnCancel()
{
	DestroyWindow();
}

void dlgNoModal::PostNcDestroy()
{
	CDialogEx::PostNcDestroy();
	delete this;
}