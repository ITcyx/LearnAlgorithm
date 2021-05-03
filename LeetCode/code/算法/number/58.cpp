class Solution
{
public:
	int lengthOfLastWord(string& s)
	{
		string::iterator pi = s.begin(), pj = s.begin();
		for (string::iterator p = s.begin(); p != s.end(); ++p)
			if (*p != ' ')
			{
				for (pj = p + 1; pj != s.end() && *pj != ' '; ++pj)
				{
				}
				pi = p;
				p = pj - 1;
			}
		return pj - pi;
	}
};