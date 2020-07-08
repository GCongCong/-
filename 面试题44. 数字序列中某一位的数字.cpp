面试题44. 数字序列中某一位的数字
数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
请写一个函数，求任意第n位对应的数字。
输入：n = 3
输出：3
示例 2：
输入：n = 11
输出：0

//数位：10就表示2个数位.int会溢出
//找规律
int findNthDigit(int n) 
{
	long long start=1;//保存开始的数字
	long long  count=9;//保存1位，2位数等等总共的数位，
	long long digit=1;//表示n是几位数
	while(n>count)//表示在n位数位的范围中
	{
		n-=count;//先判断n存在于哪个数位
		digit+=1;//n位数
		start*=10;//起始位置
		count=start*digit*9;//得到2个数位的数字范围
	}
	long long pos=n%digit;
	long long num=0;
	if(pos==0)//如14%2==0
	{
		num=start+(n/digit)-1;
	}
	else//如13%2==1
		num=start+(n/digit);
	//判断在数字的第几位，得到结果
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
