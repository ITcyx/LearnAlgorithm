class Solution
{
private:
	bool t[100000] = {};
public:
	int findRepeatNumber(vector<int>& nums)
	{
		for (auto p = nums.begin(); p != nums.end(); ++p)
		{
			if (t[*p])
				return *p;
			t[*p] = true;
		}
		return -1;
	}
};