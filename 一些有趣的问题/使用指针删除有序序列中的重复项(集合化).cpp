//ע�ⷵ��ֵn�Ǻ���Ҫ��һ������
int  deleteElement(int b[],int n) 
{
	int *p,*q,*p1;
	int c;
	for(p=b;p<b+n;p++) 
	{                 /*��������b��ÿ��Ԫ��*/
		q=p+1;
		c=0;                                  /*ͳ����ͬԪ�ظ���*/
		while (*q==*p && q<b+n) q++,c++;    /*��ͬԪ�ر�Ȼ����*/
		if (q<=b+n)
		{
			for (p1=p+1;q<b+n;p1++,q++)       /*ɾ��c��Ԫ��*/
				*p1=*q;
			n-=c;                            /*Ԫ�ظ�������c*/
		}
	}
	return n;
}


//ʹ�����ṩ�����������ظ���λ��(����λ�ã�����ʵ��λ��)��������������ɾ������
int deleteElement(int b[],int n,int i,int len) 
{                      /*�β�Ϊ������*/
      int *p,*q;
      if (i<1 && i+len >n)  return 0;
      for (q=b+i,p=b+i+len;q<b+n;p++,q++)
            *q=*p;
      return n-len;
}