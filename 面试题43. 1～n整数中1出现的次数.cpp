������43. 1��n������1���ֵĴ���
����һ������ n ����1��n��n��������ʮ���Ʊ�ʾ��1���ֵĴ��������磬����12��1��12��Щ�����а���1 ��������1��10��11��12��1һ��������5�Ρ�
ʾ�� 1��
���룺n = 12
�����5
ʾ�� 2��
���룺n = 13
�����6
���ƣ�1 <= n < 2^31

//1.ѭ�������ⷨ
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
//2.��ѧ����
int countDigitOne(int n)
{
	int high=n/10;
	int cur=n%10;
	int low=0;
	long digit=1;//1410065408Ϊnʱ�����
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
