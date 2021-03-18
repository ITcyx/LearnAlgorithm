class Solution
{
private:
	unsigned short ct[128];

public:
	int romanToInt(string& s)
	{
		ct['I'] = 1;
		ct['V'] = 5;
		ct['X'] = 10;
		ct['L'] = 50;
		ct['C'] = 100;
		ct['D'] = 500;
		ct['M'] = 1000;
		int c = 0;
		for (auto p = s.begin(); p != s.end(); ++p)
		{
			if (*p == 'I')
			{
				if ((p + 1) == s.end())
				{
					c += 1;
					break;
				}
				if (*(p + 1) == 'V' || *(p + 1) == 'X')
					c -= 1;
				else
					c += 1;
			}
			else if (*p == 'X')
			{
				if ((p + 1) == s.end())
				{
					c += 10;
					break;
				}
				if (*(p + 1) == 'L' || *(p + 1) == 'C')
					c -= 10;
				else
					c += 10;
			}
			else if (*p == 'C')
			{
				if ((p + 1) == s.end())
				{
					c += 100;
					break;
				}
				if (*(p + 1) == 'D' || *(p + 1) == 'M')
					c -= 100;
				else
					c += 100;
			}
			else
				c += ct[*p];
		}
		return c;
	}
};