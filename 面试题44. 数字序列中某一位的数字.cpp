������44. ����������ĳһλ������
������0123456789101112131415���ĸ�ʽ���л���һ���ַ������С�����������У���5λ�����±�0��ʼ��������5����13λ��1����19λ��4���ȵȡ�
��дһ���������������nλ��Ӧ�����֡�
���룺n = 3
�����3
ʾ�� 2��
���룺n = 11
�����0

//��λ��10�ͱ�ʾ2����λ.int�����
//�ҹ���
int findNthDigit(int n) 
{
	long long start=1;//���濪ʼ������
	long long  count=9;//����1λ��2λ���ȵ��ܹ�����λ��
	long long digit=1;//��ʾn�Ǽ�λ��
	while(n>count)//��ʾ��nλ��λ�ķ�Χ��
	{
		n-=count;//���ж�n�������ĸ���λ
		digit+=1;//nλ��
		start*=10;//��ʼλ��
		count=start*digit*9;//�õ�2����λ�����ַ�Χ
	}
	long long pos=n%digit;
	long long num=0;
	if(pos==0)//��14%2==0
	{
		num=start+(n/digit)-1;
	}
	else//��13%2==1
		num=start+(n/digit);
	//�ж������ֵĵڼ�λ���õ����
	 if(pos==0)
		 return num%10;
	 else
	 {
		 while(pos<digit)
		 {
			 digit--;
			 num/=10;
		 }
        return num%10;
	 }
	 return 0;
}
int main()
{
	cout<<findNthDigit(10); 
}
