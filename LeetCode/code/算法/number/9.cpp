class Solution
{
public:
	bool isPalindrome(int const& x)
	{
		if (x < 0)
			return false;
		long long a = 0;
		int b = x;
		while (b)
		{
			a *= 10;
			a += b % 10;
			b /= 10;
		}
		if (a == x)
			return true;
		return false;
	}
};