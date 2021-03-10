class Solution
{
public:
	int myAtoi(string& s)
	{
		string::iterator p;
		bool f = false;
		for (p = s.begin(); p != s.end(); ++p)
			if (*p == ' ')
				continue;
			else if (*p >= '0'&&*p <= '9')
				break;
			else if (*p == '-')
			{
				f = true;
				++p;
				break;
			}
			else if (*p == '+')
			{
				++p;
				break;
			}
			else
				return 0;
		int n = 0;
		if (f)
			for (; p != s.end(); ++p)
				if (*p >= '0'&&*p <= '9')
				{
					if (n < -214748364)
						return -2147483648;
					else if (n == -214748364 && *p >= '8')
						return -2147483648;
					n *= 10;
					n -= *p - '0';
				}
				else
					return n;
		else
			for (; p != s.end(); ++p)
				if (*p >= '0'&&*p <= '9')
				{
					if (n > 214748364)
						return 2147483647;
					else if (n == 214748364 && *p >= '7')
						return 2147483647;
					n *= 10;
					n += *p - '0';
				}
				else
					return n;
		return n;
	}
};