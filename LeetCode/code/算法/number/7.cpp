class Solution
{
public:
	int reverse(int& x)
	{
		int y = 0;
		while (x)
		{
			if (y > 214748364 || y < -214748364)
				return 0;
			else if (y == 214748364 || y == -214748364)
				if (x % 10 > 7 || x % 10 < -8)
					return 0;
			y *= 10;
			y += x % 10;
			x /= 10;
		}
		return y;
	}
};