//注意返回值n是很重要的一个参数
int  deleteElement(int b[],int n) 
{
	int *p,*q,*p1;
	int c;
	for(p=b;p<b+n;p++) 
	{                 /*访问数组b中每个元素*/
		q=p+1;
		c=0;                                  /*统计相同元素个数*/
		while (*q==*p && q<b+n) q++,c++;    /*相同元素必然相邻*/
		if (q<=b+n)
		{
			for (p1=p+1;q<b+n;p1++,q++)       /*删除c个元素*/
				*p1=*q;
			n-=c;                            /*元素个数减少c*/
		}
	}
	return n;
}