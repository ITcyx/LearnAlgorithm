class Solution
{
private:
	char buffer[10010];
public:
	bool isValid(string& s)
	{
		string::iterator p = s.begin();
		char *pb = buffer;
		while (p != s.end())
		{
			if (*p == ')' || *p == ']' || *p == '}')
			{
				if (pb == buffer)
					return false;
				if (*p > *(pb - 1) && *p - *(pb - 1) < 3)
					--pb;
				else
					return false;
			}
			else
			{
				*pb = *p;
				++pb;
			}
			++p;
		}
		return pb == buffer;
	}
};