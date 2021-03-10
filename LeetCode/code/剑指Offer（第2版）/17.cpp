class Solution
{
public:
	vector<int> printNumbers(int& n)
	{
		size_t i = 1;
		while (n)
		{
			i *= 10;
			--n;
		}
		vector<int> a(--i);
		for (auto p = a.rbegin(); p != a.rend(); ++p)
		{
			*p = i;
			--i;
		}
		return move(a);
	}
};