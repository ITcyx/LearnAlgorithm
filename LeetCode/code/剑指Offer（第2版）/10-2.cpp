class Solution
{
public:
	int numWays(int& n)
	{
		int i = 1, j = 1, t;
		while (n)
		{
			t = i;
			i = j;
			j = (t + j) % 1000000007;
			--n;
		}
		return i;
	}
};