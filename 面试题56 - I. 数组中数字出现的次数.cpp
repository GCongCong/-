面试题56 - I. 数组中数字出现的次数
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
示例 1：
输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
2 <= nums.length <= 10000

//2.位运算
vector<int> singleNumbers(vector<int>& nums) 
{
	if(nums.size()==0)
		return nums;
	int sum=nums[0];//记录整体⊕结果
	for(int i=1;i<nums.size();i++)
	{
		sum^=nums[i];
	}
	int flag=1;//划分标准
	while((flag&sum)==0)//找到这两个数字首先出现不一样的地方
	{
		flag=flag<<1;
	}
	int fir=0;
	int sed=0;
	for(int i=0;i<nums.size();i++)
	{
		if(nums[i]&flag)//和flag&为1的分为一组，这样肯定将两个元素分为了两组
		{
			fir^=nums[i];
		}
		else
		{
			sed^=nums[i];
		}
	}
	nums.clear();
	nums.push_back(fir);
	nums.push_back(sed);
	return nums;
}
//快慢指针O(N^2)时间复杂度不符合
vector<int> singleNumbers1(vector<int>& nums) 
{
	if(nums.size()==0)
		return nums;
	int low=0;
	int fast=1;
	int count=(nums.size()-2)/2;//算出有几对其他数字
	int fir=-1;
	int sed=-1;
	while(low<nums.size()-1)//到倒数第二位即可，因为fast指向最后一位，可以进行比较
	{
		if(nums[fast]==nums[low] ||fast==nums.size()-1||nums[low]==-1)//找到重复数字，到达数组末尾，指向已经判断重复的数字
		{
			if(nums[fast]==nums[low])
			{
				count--;
				nums[low]=-1;
				nums[fast]=-1;

			}
			low++;
			fast=low+1;
			continue;
		}
		if(count==0)//表示已经找到所有偶数数字了
		{
			break;
		}
		fast++;
	}
	for(int i=0;i<nums.size();i++)
	{
		if(nums[i]==-1)
			continue;
		if(fir==-1)//将不为-1的数值给这两个变量，
		{
			fir=nums[i];
		}
		else//表示fir已经保存了第一个数字
		{
			sed=nums[i];
		}
	}
	nums.clear();
	nums.push_back(fir);
	nums.push_back(sed);
	return nums;
}
int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(2);
	nums=singleNumbers(nums);
	for(int i=0;i<nums.size();i++)
	{
		cout<<nums[i]<<" ";
	}
}
