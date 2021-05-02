class Solution
{
private:
	char b1[100000];
	char b2[100000];
public:
	string countAndSay(int& n)
	{
		b1[0] = '1';
		b1[1] = '\0';
		int c;
		size_t i1 = 1, i2, i;
		while (n > 1)
		{
			i2 = 0;
			c = 1;
			for (i = 1; i <= i1; ++i)
			{
				if (b1[i] == b1[i - 1])
					++c;
				else
				{
					b2[i2] = c + '0';
					++i2;
					b2[i2] = b1[i - 1];
					++i2;
					c = 1;
				}
			}
			b2[i2] = '\0';
			--n;
			if (n == 1)
				return b2;
			i1 = 0;
			c = 1;
			for (i = 1; i <= i2; ++i)
			{
				if (b2[i] == b2[i - 1])
					++c;
				else
				{
					b1[i1] = c + '0';
					++i1;
					b1[i1] = b2[i - 1];
					++i1;
					c = 1;
				}
			}
			b1[i1] = '\0';
			--n;
		}
		return b1;
	}
};