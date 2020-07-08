������16. ��ֵ�������η�
ʵ�ֺ���double Power(double base, int exponent)����base��exponent�η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣
ʾ�� 1:
����: 2.00000, 10
���: 1024.00000
ʾ�� 2:
����: 2.10000, 3
���: 9.26100
ʾ�� 3:
����: 2.00000, -2
���: 0.25000
����: 2^-2 = 1/2^2 = 1/4 = 0.25
˵��:
-100.0 < x < 100.0
n �� 32 λ�з�������������ֵ��Χ�� [?231, 231 ? 1] ��
//1.ʱ�临�Ӷȹ���
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
//2.���������㣬������λ���㣬3^3=3^2*3^1,�������ǿ��Բ��ϼ���x��ƽ������Ϊ������ż���������
double myPow2(double x, int n) 
{
	if(x==1 || n==0)
		return 1;
	long num=n;//int�������������long�洢��Ϊ�з������α����ķ�Χ��-2147483648    2147483647����-2147483648ȡ����ֵʱ����2147483647�ͻᱨ�������ȶԸ�������ǿ������ת����
	double res=1;
	if(n<0)
	{
		num=-num;
		x=1/x;
	}
	while(num!=0)
	{
		if(num%2==1)//����
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
		if((num&1)==1)//����������������ж�������������һ����0λ����1
		{
			res*=x;
		}
		x*=x;
		num=num>>1;//���ƾ���/2�ĺ���
	}
	return res;
}
int main()
{
	double sum=myPow(2.00000,10);
	printf("%f",sum);
}
