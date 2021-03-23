class Solution
{
private:
	unsigned char h1[128], h2[128];
public:
	bool CheckPermutation(string& s1, string& s2)
	{
		if (s1.size() != s2.size())
			return false;
		string::iterator p1 = s1.begin(), p2 = s2.begin();
		size_t i;
		for (i = 0; i < 128; ++i)
			h1[i] = h2[i] = 0;
		while (p1 != s1.end())
		{
			++h1[*p1];
			++h2[*p2];
			++p1;
			++p2;
		}
		for (i = 0; i < 128; ++i)
			if (h1[i] != h2[i])
				return false;
		return true;
	}
};