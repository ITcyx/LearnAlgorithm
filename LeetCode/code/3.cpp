class Solution
{
public:
	int lengthOfLongestSubstring(string const& s)
	{
		int ch[128] = {};
		for (int i = 0; i < 128; ++i)
			ch[i] = -1;
		int m = 0, f = -1, t;
		for (auto p = s.begin(); p != s.end(); ++p)
		{
			if (ch[*p] == -1)
			{
				if (f == -1)
				{
					ch[*p] = p - s.begin();
					++m;
				}
				else
				{
					t = p - s.begin();
					ch[*p] = t;
					if (t - f > m)
						m = t - f;
				}
			}
			else
			{
				if (f == -1)
				{
					f = ch[*p];
					ch[*p] = p - s.begin();
				}
				else
				{
					if (f < ch[*p])
						f = ch[*p];
					t = p - s.begin();
					ch[*p] = t;
					if (t - f > m)
						m = t - f;
				}
			}
		}
		return m;
	}
};