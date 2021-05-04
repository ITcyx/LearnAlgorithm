class Solution
{
public:
	bool oneEditAway(string& first, string& second)
	{
		if (first.length() > second.length() + 1 || first.length() + 1 < second.length())
			return false;
		string::iterator f_p = first.begin(), s_p = second.begin();
		bool f = false;
		if (first.length() == second.length())
		{
			for (; f_p != first.end(); ++f_p)
			{
				if (*f_p != *s_p)
				{
					if (f)
						return false;
					f = true;
				}
				++s_p;
			}
			return true;
		}
		else if (first.length() < second.length())
		{
			for (; f_p != first.end(); ++f_p)
			{
				if (*f_p != *s_p)
				{
					if (f)
						return false;
					f = true;
					--f_p;
				}
				++s_p;
			}
			return true;
		}
		else
		{
			for (; f_p != first.end(); ++f_p)
			{
				if (*f_p != *s_p)
				{
					if (f)
						return false;
					f = true;
					--s_p;
				}
				++s_p;
			}
			return true;
		}
	}
};