
剑指 Offer 49. 丑数
我们把只包含因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
示例:
输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  1 是丑数。n 不超过1690。
//1.时间复杂度过高
int nthUglyNumber1(int n)
{
	int temp[1230]={0};
	temp[1]=1;
	int index=2;
	for(int i=2;index<=n;i++)
	{
		if(i%2==0)
		{
			int a=i/2;
			for(int j=1;j<index;j++)
			{
				if(a==temp[j])
				{
					temp[index]=i;
					index++;
					break;
				}
			}
			continue;
		}
		if(i%3==0)
		{
			int b=i/3;
			for(int j=1;j<index;j++)
			{
				if(b==temp[j])
				{
					temp[index]=i;
					index++;
					break;
				}
			}
			continue;
		}
		if(i%5==0)
		{
			int c=i/5;
			for(int j=1;j<index;j++)
			{
				if(c==temp[j])
				{
					temp[index]=i;
					index++;
					break;
				}
			}
			continue;
		}
	}
	return temp[n];
}
//2.三个指针对数组进行操作
int nthUglyNumber(int n)
{
	if(n==0)
		return 0;
	int a=0;
	int b=0;
	int c=0;
	vector<int> dp(n,0);
	dp[0]=1;
	for(int i=1;i<n;i++)
	{
		int temp=min(dp[a]*2,min(dp[b]*3,dp[c]*5));
		if(temp==dp[a]*2)
			a++;
		if(temp==dp[b]*3)
			b++;
		if(temp==dp[c]*5)
			c++;
		dp[i]=temp;
	}
	return dp[n-1];
}
int main()
{
	cout<<nthUglyNumber(10);
}
