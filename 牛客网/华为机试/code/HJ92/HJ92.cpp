#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	string::iterator i, j, mp[500];
	size_t m, c, t;
	while (cin >> a)
	{
		m = 0;
		c = 0;
		for (i = a.begin(); i != a.end(); ++i)
			if (*i >= '0'&&*i <= '9')
			{
				for (j = i + 1; j != a.end(); ++j)
					if (*j<'0' || *j>'9')
						break;
				if (j - i > m)
				{
					m = j - i;
					mp[0] = i;
					c = 0;
				}
				else if (j - i == m)
					mp[++c] = i;
				if (j == a.end())
					break;
			}
		for (t = 0; t <= c; ++t)
			for (i = mp[t]; i != mp[t] + m; ++i)
				cout << *i;
		cout << "," << m << endl;
	}
	return 0;
}