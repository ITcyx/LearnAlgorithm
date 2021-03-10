class Solution
{
public:
	int fib(int& n)
	{
		int a = 0;
		int b = 1;
		int c;
		while (n)
		{
			c = a;
			a = b;
			b = (b + c) % 1000000007;
			--n;
		}
		return a;
	}
};