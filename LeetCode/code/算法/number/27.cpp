class Solution
{
public:
	int removeElement(vector<int>& nums, int& val)
	{
		vector<int>::iterator p = nums.begin(), q = nums.begin();
		int c = 0;
		while (q != nums.end())
		{
			if (val != *q)
			{
				*p = *q;
				++p;
				++c;
			}
			++q;
		}
		return c;
	}
};