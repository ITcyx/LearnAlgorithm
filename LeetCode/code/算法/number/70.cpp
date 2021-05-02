class Solution
{
private:
	int buffer[100000];
public:
	int climbStairs(int n)
	{
		if (n < 2)
			return 1;
		buffer[0] = 1;
		buffer[1] = 1;
		for (size_t i = 2; i <= n; ++i)
			buffer[i] = buffer[i - 1] + buffer[i - 2];
		return buffer[n];
	}
};