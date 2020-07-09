������56 - I. ���������ֳ��ֵĴ���
һ���������� nums �����������֮�⣬�������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��
ʾ�� 1��
���룺nums = [4,1,4,6]
�����[1,6] �� [6,1]
2 <= nums.length <= 10000

//2.λ����
vector<int> singleNumbers(vector<int>& nums) 
{
	if(nums.size()==0)
		return nums;
	int sum=nums[0];//��¼���娒���
	for(int i=1;i<nums.size();i++)
	{
		sum^=nums[i];
	}
	int flag=1;//���ֱ�׼
	while((flag&sum)==0)//�ҵ��������������ȳ��ֲ�һ���ĵط�
	{
		flag=flag<<1;
	}
	int fir=0;
	int sed=0;
	for(int i=0;i<nums.size();i++)
	{
		if(nums[i]&flag)//��flag&Ϊ1�ķ�Ϊһ�飬�����϶�������Ԫ�ط�Ϊ������
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
//����ָ��O(N^2)ʱ�临�ӶȲ�����
vector<int> singleNumbers1(vector<int>& nums) 
{
	if(nums.size()==0)
		return nums;
	int low=0;
	int fast=1;
	int count=(nums.size()-2)/2;//����м�����������
	int fir=-1;
	int sed=-1;
	while(low<nums.size()-1)//�������ڶ�λ���ɣ���Ϊfastָ�����һλ�����Խ��бȽ�
	{
		if(nums[fast]==nums[low] ||fast==nums.size()-1||nums[low]==-1)//�ҵ��ظ����֣���������ĩβ��ָ���Ѿ��ж��ظ�������
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
		if(count==0)//��ʾ�Ѿ��ҵ�����ż��������
		{
			break;
		}
		fast++;
	}
	for(int i=0;i<nums.size();i++)
	{
		if(nums[i]==-1)
			continue;
		if(fir==-1)//����Ϊ-1����ֵ��������������
		{
			fir=nums[i];
		}
		else//��ʾfir�Ѿ������˵�һ������
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
