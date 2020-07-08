面试题43. 1～n整数中1出现的次数
输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。
示例 1：
输入：n = 12
输出：5
示例 2：
输入：n = 13
输出：6
限制：1 <= n < 2^31

//1.循环暴力解法
int countDigitOne1(int n) 
{
	int count=0;
	for(int i=1;i<=n;i++)
	{
		int temp=i;
		while(temp!=0)
		{
			int num=temp%10;
			if(num==1)
			{
				count++;
			}
			temp/=10;
		}
	}
	return count;
}
//2.数学规律
int countDigitOne(int n)
{
	int high=n/10;
	int cur=n%10;
	int low=0;
	long digit=1;//1410065408为n时会溢出
	int res=0;
	while(low!=n)
	{
		if(cur==0)
		{
			res+=(high*digit);
		}
		if(cur==1)
		{
			res+=(high*digit+low+1);
		}
		if(cur>1)
		{
			res+=(high+1)*digit;
		}
		low+=cur*digit;
		cur=high%10;
		high/=10;
		digit*=10;
	}
	return res;
}
int main()
{
	cout<<countDigitOne(13); 
}
