class Solution
{
public:
	int titleToNumber(string& columnTitle)
	{
		int table[128];
		size_t i;
		for (i = 'A'; i <= 'Z'; ++i)
			table[i] = i - 'A' + 1;
		int a = 0;
		long long c = 1;
		for (auto p = columnTitle.rbegin(); p != columnTitle.rend(); ++p)
		{
			a += c * table[*p];
			c *= 26;
		}
		return a;
	}
};