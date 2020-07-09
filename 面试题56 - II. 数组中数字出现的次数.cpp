面试题56 - II. 数组中数字出现的次数
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
示例 1：
输入：nums = [3,4,3,3]
输出：4
//1.哈希表 O(N)S(N)
int singleNumber1(vector<int>& nums) 
{
	if(nums.size()==0)
		return 0;
	unordered_map<int,int>hash;
	for(int i=0;i<nums.size();i++)
	{
		hash[nums[i]]++;
	}
	for(auto i:hash)
	{
		if(i.second==1)//找到只出现了一次的
			return i.first;
	}
	return 0;
}
//2.排序
int singleNumber2(vector<int>& nums) 
{
	if(nums.size()==0)
		return 0;
	sort(nums.begin(), nums.end());
	int i=0;
	for(;i<nums.size()-2;i+=3)
	{
		if(nums[i]!=nums[i+2])
		{
			return nums[i];
		}
	}
	return nums[i];//单个元素在结尾
}
//3.位运算
int singleNumber(vector<int>& nums) 
{
	if(nums.size()==0)
		return 0;
	int b[32]={0};//存储所有数字每位2进制出现1的次数
	//遍历所有可能
	for(int i=0;i<nums.size();i++)
	{
		int flag=1;
		//unsigned int flag=1;力扣只支持无符号
		for(int j=0;j<32;j++)//32位
		{
			if(nums[i]&flag)//判断每一位是否为1
			{
				b[j]+=1;//保存出现1的次数
			}
			flag<<=1;//判断下一位
		}
	}
	//将b[32]中的二进制，转换为十进制
	int res=0;//保存最后的值
	for(int i=31;i>=0;i--)//从高到低位如0134，从0开始，0101
	{
		res<<=1;//先向左移动，
		//先加再移动 0，00，01，010，011，0110
		//先移动再加 00，01，010，0100，0101，所以选第二种
		res+=(b[i]%3);//数值出现3次，那么它的对应位二进制也是3次，所以%3，剩下的就是只出现一个的
	}
	return res;
}
int main()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(3);
	nums.push_back(3);
	cout<<singleNumber(nums);
}
