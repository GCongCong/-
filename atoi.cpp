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

/*��ָ Offer 67. ���ַ���ת��������
дһ������ StrToInt��ʵ�ְ��ַ���ת��������������ܡ�����ʹ�� atoi �����������ƵĿ⺯����
���ȣ��ú����������Ҫ�������õĿ�ͷ�ո��ַ���ֱ��Ѱ�ҵ���һ���ǿո���ַ�Ϊֹ��
������Ѱ�ҵ��ĵ�һ���ǿ��ַ�Ϊ�����߸���ʱ���򽫸÷�����֮���澡���ܶ���������������������Ϊ�������������ţ������һ���ǿ��ַ������֣���ֱ�ӽ�����֮�������������ַ�����������γ�������
���ַ���������Ч����������֮��Ҳ���ܻ���ڶ�����ַ�����Щ�ַ����Ա����ԣ����Ƕ��ں�����Ӧ�����Ӱ�졣
ע�⣺������ַ����еĵ�һ���ǿո��ַ�����һ����Ч�����ַ����ַ���Ϊ�ջ��ַ����������հ��ַ�ʱ������ĺ�������Ҫ����ת����
���κ�����£����������ܽ�����Ч��ת��ʱ���뷵�� 0��
˵����
�������ǵĻ���ֻ�ܴ洢 32 λ��С���з�����������ô����ֵ��ΧΪ [?231,  231 ? 1]�������ֵ���������Χ���뷵��  INT_MAX (231 ? 1) �� INT_MIN (?231) ��
����: "42"
���: 42
ʾ�� 2:
����: "   -42"
���: -42
����: ��һ���ǿհ��ַ�Ϊ '-', ����һ�����š�
     ���Ǿ����ܽ���������������������ֵ�����������������õ� -42 ��
	 ����: "-91283472332"
���: -2147483648
����: ���� "-91283472332" ���� 32 λ�з���������Χ�� 
     ��˷��� INT_MIN (?231) ��
*/
//42---��temp=4;res=0*10+4=4--��temp=2;res=4*10+2=42
int strToInt(string str) 
{
	if(str.size()==0)
		return 0;
	int res=0;//����ÿ�εĽ��
	int temp=0;//����ÿ���ַ�ת��Ϊ����
	//ȥ����ͷ�Ŀո�
	int index=0;
	while(str[index]==' ')
		index++;
	bool flag=false;//��ʶ������trueΪ����
	if(str[index]=='-' ||str[index]=='+' )
	{
		if(str[index]=='-')
		{
			flag=true;
		}
		index++;
	}
	for(;index<str.size();index++)
	{
		if(isdigit(str[index]))
		{
			temp=str[index]-'0';
			if (res > INT_MAX / 10 || (res == INT_MAX/10 && temp > 7)) 
			{
                if(flag)
					return INT_MIN;
				else
					return INT_MAX;
            }
			res=res*10+temp;
		}
		else
			break;
	}
	if(flag)
		res=0-res;
	return res;
}
int main()
{
	cout<<"���������� "<<strToInt("42") <<endl;
	cout<<"����ո�͸�����"<<strToInt("   -42") <<endl;
	cout<<"�м������Ƿ��ַ�ֹͣת���� "<<strToInt("4193 with words") <<endl;
	cout<<"�������ܽ�����Ч��ת��ʱ��"<<strToInt("words and 987") <<endl;
	cout<<"����������� "<<strToInt("2147483648") <<endl;
	cout<<"����������� "<<strToInt("-91283472332") <<endl;
}
