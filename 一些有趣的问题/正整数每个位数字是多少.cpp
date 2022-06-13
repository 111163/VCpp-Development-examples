//正整数每位的数字是多少
int dev(int num, int aa[])
{
	int n = 1;
	int i = 0;
	while(num / n )
	{
		aa[i++]=(num % (10 * n))/n;
		n *= 10;	
	}
	return i;
}