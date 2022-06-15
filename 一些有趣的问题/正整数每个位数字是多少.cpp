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


//因为是整数，所以必然有个位，所以至少可以进行一次取值操作，所以用do...while是更加合理的
//仔细考虑自己的和已有的标准的存在的差异  我们的是从高位到低位，下面的是从低位到高位
do
{
	d[n] = x % 10;
	x /= 10;
	n++;
}while(x!=0)


