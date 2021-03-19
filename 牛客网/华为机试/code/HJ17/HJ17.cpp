#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	string::iterator p;
	int f, m, x, y;
	size_t i;
	while (cin >> a)
	{
		x = y = 0;
		for (p = a.begin(); p != a.end(); ++p)
		{
			f = 0;
			if (*p == 'A')
				f = 1;
			else if (*p == 'S')
				f = 2;
			else if (*p == 'D')
				f = 3;
			else if (*p == 'W')
				f = 4;
			else
			{
				if (*p == ';')
					continue;
				while (p != a.end() && *p != ';')
					++p;
				if (p == a.end())
					break;
				continue;
			}
			i = m = 0;
			for (++p; p != a.end() && *p != ';'; ++p)
			{
				++i;
				if (i > 2)
					break;
				if (*p >= '0'&&*p <= '9')
				{
					m *= 10;
					m += (*p - '0');
				}
				else
					break;
			}
			if (p == a.end())
				break;
			if (i > 2 || *p != ';')
			{
				while (p != a.end() && *p != ';')
					++p;
				if (p == a.end())
					break;
				continue;
			}
			if (f == 1)
				x -= m;
			else if (f == 2)
				y -= m;
			else if (f == 3)
				x += m;
			else
				y += m;
		}
		cout << x << "," << y << endl;
	}
	return 0;
}