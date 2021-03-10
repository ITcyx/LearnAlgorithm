class Solution
{
public:
	bool isUnique(string const& astr)
	{
		int h = 0;
		for (auto p = astr.begin(); p != astr.end(); ++p)
			if (h == (h | (1 << (*p - 'a'))))
				return false;
			else
				h |= (1 << (*p - 'a'));
		return true;
	}
};