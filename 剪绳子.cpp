# include <iostream>
using namespace std;
# include<stdio.h>
# include<string.h>
#include <vector>
# include <string>
# include <stack>
# include<deque>
# include<stdint.h>
# include<limits.h>
# include<math.h>
#include <unordered_map>
#include<algorithm>
/*剑指 Offer 14- I. 剪绳子
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
示例 1：
输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
示例 2:
输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
2 <= n <= 58
*/
//1.递归，自顶向下，所以时间复杂度很高
int cuttingRope1(int n) 
{
	if(n==2)
		return 1;
	int res=-1;
	for(int i=2;i<n;i++)
	{
		res= max(res,max(i*(n-i),i*cuttingRope1(n-i)));//不剪了；从i位置剪，剩下的不剪了；从i位置剪，剩下的继续递归剪
		//从这三种情况中选最大值，res保存最大值，最后返回。
	}
	return res;
}
//2.每次把值保存起来
int dp(int n,vector<int> temp)
{
	if(n==2)
		return 1;
	if(temp[n]!=0)//如果数组中有直接返回
		return temp[n];
	int res=-1;
	for(int i=2;i<n;i++)
	{
		res= max(res,max(i*(n-i),i*dp(n-i,temp)));
		
	}
	temp[n]=res;//每次把结果保存到数组中
	return res;
}
int cuttingRope2(int n) 
{
	if (n==2)
		return 1;
	vector<int> temp(n+1,0);
	return dp(n,temp);
}

//动态规划，自底向上，先得到dp[2]，dp[3]
int cuttingRope(int n) 
{
	vector<int> dp(n+1,0);
	dp[2]=1;
	for(int i=3;i<=n;i++)//分别求dp[3]表示绳子长度为3时的最大乘积
	{
		for(int j=1;j<i;j++)//对长度为3的绳子进行切割
		{
			dp[i]=max(dp[i],max(j*(i-j),j*dp[i-j]));
		}
	}
	return dp[n];
}
int main()
{
	 cout<<cuttingRope(10); 
}
