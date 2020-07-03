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
/*��ָ Offer 14- I. ������
����һ������Ϊ n �����ӣ�������Ӽ����������ȵ� m �Σ�m��n����������n>1����m>1����
ÿ�����ӵĳ��ȼ�Ϊ k[0],k[1]...k[m-1] ������ k[0]*k[1]*...*k[m-1] ���ܵ����˻��Ƕ��٣�
���磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���ʱ�õ������˻���18��
ʾ�� 1��
����: 2
���: 1
����: 2 = 1 + 1, 1 �� 1 = 1
ʾ�� 2:
����: 10
���: 36
����: 10 = 3 + 3 + 4, 3 �� 3 �� 4 = 36
2 <= n <= 58
*/
//1.�ݹ飬�Զ����£�����ʱ�临�ӶȺܸ�
int cuttingRope1(int n) 
{
	if(n==2)
		return 1;
	int res=-1;
	for(int i=2;i<n;i++)
	{
		res= max(res,max(i*(n-i),i*cuttingRope1(n-i)));//�����ˣ���iλ�ü���ʣ�µĲ����ˣ���iλ�ü���ʣ�µļ����ݹ��
		//�������������ѡ���ֵ��res�������ֵ����󷵻ء�
	}
	return res;
}
//2.ÿ�ΰ�ֵ��������
int dp(int n,vector<int> temp)
{
	if(n==2)
		return 1;
	if(temp[n]!=0)//�����������ֱ�ӷ���
		return temp[n];
	int res=-1;
	for(int i=2;i<n;i++)
	{
		res= max(res,max(i*(n-i),i*dp(n-i,temp)));
		
	}
	temp[n]=res;//ÿ�ΰѽ�����浽������
	return res;
}
int cuttingRope2(int n) 
{
	if (n==2)
		return 1;
	vector<int> temp(n+1,0);
	return dp(n,temp);
}

//��̬�滮���Ե����ϣ��ȵõ�dp[2]��dp[3]
int cuttingRope(int n) 
{
	vector<int> dp(n+1,0);
	dp[2]=1;
	for(int i=3;i<=n;i++)//�ֱ���dp[3]��ʾ���ӳ���Ϊ3ʱ�����˻�
	{
		for(int j=1;j<i;j++)//�Գ���Ϊ3�����ӽ����и�
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
