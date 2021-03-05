class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		auto const ci = nums.end() - 1;
		auto const cj = nums.end();
		auto i = nums.begin(), j = nums.begin();
		for (; i != ci; ++i)
			for (j = i + 1; j != cj; ++j)
				if ((*i) + (*j) == target)
				{
					vector<int>a;
					a.push_back(i - nums.begin());
					a.push_back(j - nums.begin());
					return move(a);
				}
		vector<int>a;
		a.push_back(i - nums.begin());
		a.push_back(j - nums.begin());
		return move(a);
	}
};