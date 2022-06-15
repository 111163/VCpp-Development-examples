void combin(int *a,int *b,int *c,int n,int m)
{
	int *p1,*p2,*p3;
	p1=a,p2=b,p3=c;

	while (p1<a+n)  *p3++=*p1++;
	while (p2<b+m) *p3++=*p2++
}