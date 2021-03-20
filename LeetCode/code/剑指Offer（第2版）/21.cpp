class Solution
{
public:
	vector<int> exchange(vector<int>& nums)
	{
		vector<int>::iterator p = nums.begin();
		int t;
		for (auto i = nums.begin(); i != nums.end(); ++i)
			if (*i % 2)
			{
				t = *i;
				*i = *p;
				*p = t;
				++p;
			}
		return move(nums);
	}
};