class Solution
{
private:
	int table[128][2];
public:
	char firstUniqChar(string& s)
	{
		size_t i, m = 500000;
		for (i = 0; i < 128; ++i)
			table[i][0] = table[i][1] = 0;
		for (auto p = s.begin(); p != s.end(); ++p)
		{
			table[*p][0] = p - s.begin();
			++table[*p][1];
		}
		char c = 0;
		for (i = 0; i < 128; ++i)
			if (table[i][1] == 1 && table[i][0] < m)
			{
				c = i;
				m = table[i][0];
			}
		if (c)
			return c;
		return ' ';
	}
};