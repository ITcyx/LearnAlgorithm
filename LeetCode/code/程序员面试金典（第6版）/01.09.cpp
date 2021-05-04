class Solution
{
public:
	bool isFlipedString(string& s1, string& s2)
	{
		if (s1.length() != s2.length())
			return false;
		if (s1.length() == 0)
			return true;
		string::iterator p1, p2, t = s2.begin();
		while (true)
		{
			p1 = s1.begin();
			for (p2 = t; p2 != s2.end(); ++p2)
				if (*p1 == *p2)
				{
					t = p2 + 1;
					break;
				}
			if (p2 == s2.end())
				return false;
			++p1;
			for (++p2; p2 != s2.end(); ++p2)
			{
				if (*p1 != *p2)
					break;
				++p1;
			}
			if (p2 != s2.end())
				continue;
			for (p2 = s2.begin(); p1 != s1.end(); ++p1)
			{
				if (*p1 != *p2)
					break;
				++p2;
			}
			if (p1 != s1.end())
				continue;
			return true;
		}
	}
};