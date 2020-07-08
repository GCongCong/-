面试题16. 数值的整数次方
实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。
示例 1:
输入: 2.00000, 10
输出: 1024.00000
示例 2:
输入: 2.10000, 3
输出: 9.26100
示例 3:
输入: 2.00000, -2
输出: 0.25000
解释: 2^-2 = 1/2^2 = 1/4 = 0.25
说明:
-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [?231, 231 ? 1] 。
//1.时间复杂度过高
double myPow1(double x, int n) 
{
	if(x==1 || n==0)
		return 1;
	double sum=1;
	int flag=0;
	if(n<0)
	{
		flag=1;
		n*=-1;
	}
	for(int i=0;i<n;i++)
	{
		sum*=x;
	}
	if(flag)
	{
		return 1/sum;
	}
	return sum;
}
//2.快速幂运算，不引入位运算，3^3=3^2*3^1,所以我们可以不断计算x的平方，分为奇数，偶数两种情况
double myPow2(double x, int n) 
{
	if(x==1 || n==0)
		return 1;
	long num=n;//int会溢出，所以用long存储因为有符号整形变量的范围是-2147483648    2147483647；当-2147483648取绝对值时大于2147483647就会报错，所以先对负数进行强制类型转换。
	double res=1;
	if(n<0)
	{
		num=-num;
		x=1/x;
	}
	while(num!=0)
	{
		if(num%2==1)//奇数
		{
			res*=x;
		}
		x*=x;
		num/=2;
	}
	return res;
}
double myPow(double x, int n) 
{
	if(x==1 || n==0)
		return 1;
	long num=n;
	double res=1;
	if(n<0)
	{
		num=-num;
		x=1/x;
	}
	while(num!=0)
	{
		if((num&1)==1)//奇数，与运算可以判断奇数，奇数它一定在0位上有1
		{
			res*=x;
		}
		x*=x;
		num=num>>1;//右移就是/2的含义
	}
	return res;
}
int main()
{
	double sum=myPow(2.00000,10);
	printf("%f",sum);
}
