class Solution
{
private:
	char buffer[10010];

public:
	string addBinary(string& a, string& b)
	{
		char *pb = buffer + (a.size() > b.size() ? a.size() : b.size());
		*(pb + 1) = '\0';
		string::reverse_iterator ap = a.rbegin(), bp = b.rbegin();
		bool f = false;
		while (ap != a.rend() && bp != b.rend())
		{
			if (*ap == '1'^*bp == '1'^f)
			{
				*pb = '1';
				if (*ap == '0')
					f = false;
			}
			else
			{
				*pb = '0';
				if (*ap == '1' || *bp == '1')
					f = true;
			}
			--pb;
			++ap;
			++bp;
		}
		while (ap != a.rend())
		{
			if (*ap == '1'^f)
			{
				*pb = '1';
				if (f)
					f = false;
			}
			else
				*pb = '0';
			--pb;
			++ap;
		}
		while (bp != b.rend())
		{
			if (*bp == '1'^f)
			{
				*pb = '1';
				if (f)
					f = false;
			}
			else
				*pb = '0';
			--pb;
			++bp;
		}
		if (f)
		{
			*pb = '1';
			--pb;
		}
		return ++pb;
	}
};