#include <iostream>
#include <string>

using namespace std;

int main()
{
	bool fa[26], fb[26];
	int f[26], i, n;
	string a, b;
	while (cin >> a >> b)
	{
		n = 0;
		for (i = 0; i < 26; ++i)
		{
			fa[i] = true;
			fb[i] = true;
		}
		for (i = 0; i < a.length(); ++i)
			if (a[i] <= 'Z'&&fa[a[i] - 'A'])
			{
				fa[a[i] - 'A'] = false;
				fb[a[i] - 'A'] = false;
				f[n] = a[i] - 'A';
				++n;
			}
			else if (fa[a[i] - 'a'])
			{
				fa[a[i] - 'a'] = false;
				fb[a[i] - 'a'] = false;
				f[n] = a[i] - 'a';
				++n;
			}
		for (i = 0; i < 26; ++i)
			if (fb[i])
			{
				f[n] = i;
				++n;
			}
		for (i = 0; i < b.length(); ++i)
			if (b[i] <= 'Z')
				b[i] = 'A' + f[b[i] - 'A'];
			else
				b[i] = 'a' + f[b[i] - 'a'];
		cout << b << endl;
	}
	return 0;
}