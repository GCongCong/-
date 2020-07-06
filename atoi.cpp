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

/*剑指 Offer 67. 把字符串转换成整数
写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。
首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。
注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。
在任何情况下，若函数不能进行有效的转换时，请返回 0。
说明：
假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [?231,  231 ? 1]。如果数值超过这个范围，请返回  INT_MAX (231 ? 1) 或 INT_MIN (?231) 。
输入: "42"
输出: 42
示例 2:
输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
	 输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 
     因此返回 INT_MIN (?231) 。
*/
//42---》temp=4;res=0*10+4=4--》temp=2;res=4*10+2=42
int strToInt(string str) 
{
	if(str.size()==0)
		return 0;
	int res=0;//保存每次的结果
	int temp=0;//保存每个字符转换为整数
	//去除开头的空格
	int index=0;
	while(str[index]==' ')
		index++;
	bool flag=false;//标识负数，true为负数
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
	cout<<"处理正数： "<<strToInt("42") <<endl;
	cout<<"处理空格和负数："<<strToInt("   -42") <<endl;
	cout<<"中间遇到非法字符停止转换： "<<strToInt("4193 with words") <<endl;
	cout<<"函数不能进行有效的转换时："<<strToInt("words and 987") <<endl;
	cout<<"处理上溢出： "<<strToInt("2147483648") <<endl;
	cout<<"处理下溢出： "<<strToInt("-91283472332") <<endl;
}
