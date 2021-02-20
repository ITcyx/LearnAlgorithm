#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b;
	string *ap, *bp;
	int a1, b1, c, i, t, g;
	char p[10001];
	while (cin >> a >> b)
	{
		if (a.length() > b.length())
		{
			ap = &a;
			bp = &b;
		}
		else
		{
			ap = &b;
			bp = &a;
		}
		g = ap->length() - bp->length();
		p[ap->length()] = '\0';
		c = 0;
		for (i = bp->length() - 1; i > -1; --i)
		{
			t = (*ap)[i + g] - '0' + (*bp)[i] - '0' + c;
			if (t < 10)
			{
				c = 0;
				p[i + g] = '0' + t;
			}
			else
			{
				c = 1;
				p[i + g] = '0' + (t % 10);
			}
		}
		for (i = g - 1; i > -1; --i)
		{
			t = (*ap)[i] - '0' + c;
			if (t < 10)
			{
				c = 0;
				p[i] = '0' + t;
			}
			else
			{
				c = 1;
				p[i] = '0' + (t % 10);
			}
		}
		if (c)
			cout << '1' << p << endl;
		else
			cout << p << endl;
	}
	return 0;
}