class Solution
{
private:
	size_t char_count[128];

public:
	bool canPermutePalindrome(string const& s)
	{
		size_t i;
		for (i = 0; i < 128; ++i)
			char_count[i] = 0;
		for (auto p = s.begin(); p != s.end(); ++p)
			++char_count[*p];
		bool f = true;
		for (i = 0; i < 128; ++i)
			if (char_count[i] % 2)
				if (f)
					f = false;
				else
					return false;
		return true;
	}
};