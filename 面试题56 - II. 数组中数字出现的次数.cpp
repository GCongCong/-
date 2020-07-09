������56 - II. ���������ֳ��ֵĴ���
��һ������ nums �г�һ������ֻ����һ��֮�⣬�������ֶ����������Ρ����ҳ��Ǹ�ֻ����һ�ε����֡�
ʾ�� 1��
���룺nums = [3,4,3,3]
�����4
//1.��ϣ�� O(N)S(N)
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
		if(i.second==1)//�ҵ�ֻ������һ�ε�
			return i.first;
	}
	return 0;
}
//2.����
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
	return nums[i];//����Ԫ���ڽ�β
}
//3.λ����
int singleNumber(vector<int>& nums) 
{
	if(nums.size()==0)
		return 0;
	int b[32]={0};//�洢��������ÿλ2���Ƴ���1�Ĵ���
	//�������п���
	for(int i=0;i<nums.size();i++)
	{
		int flag=1;
		//unsigned int flag=1;����ֻ֧���޷���
		for(int j=0;j<32;j++)//32λ
		{
			if(nums[i]&flag)//�ж�ÿһλ�Ƿ�Ϊ1
			{
				b[j]+=1;//�������1�Ĵ���
			}
			flag<<=1;//�ж���һλ
		}
	}
	//��b[32]�еĶ����ƣ�ת��Ϊʮ����
	int res=0;//��������ֵ
	for(int i=31;i>=0;i--)//�Ӹߵ���λ��0134����0��ʼ��0101
	{
		res<<=1;//�������ƶ���
		//�ȼ����ƶ� 0��00��01��010��011��0110
		//���ƶ��ټ� 00��01��010��0100��0101������ѡ�ڶ���
		res+=(b[i]%3);//��ֵ����3�Σ���ô���Ķ�Ӧλ������Ҳ��3�Σ�����%3��ʣ�µľ���ֻ����һ����
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
