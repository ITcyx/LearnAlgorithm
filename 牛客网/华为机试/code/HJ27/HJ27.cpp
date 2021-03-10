#include <iostream>
#include <string>

using namespace std;

bool is_bro(int h[52], string& t)
{
	int h2[52], i;
	for (i = 0; i < 52; ++i)
		h2[i] = 0;
	for (i = 0; i < t.length(); ++i)
		if (t[i] <= 'Z')
			++h2[t[i] - 'A'];
		else
			++h2[t[i] - 'a' + 26];
	for (i = 0; i < 52; ++i)
		if (h[i] != h2[i])
			return false;
	return true;
}

void qs(string c[1000], int const& i, int const& j)
{
	if (j - i <= 1)
		return;
	int p = i;
	string tmp;
	for(int s=i+1;s<j;++s)
		if (c[s] < c[i])
		{
			++p;
			tmp = move(c[p]);
			c[p] = move(c[s]);
			c[s] = move(tmp);
		}
	tmp = move(c[p]);
	c[p] = move(c[i]);
	c[i] = move(tmp);
	qs(c, i, p);
	qs(c, p + 1, j);
}

int main()
{
	int m, n, i, k, h[52];
	string a, b[1000], c[1000];
	while (cin >> n)
	{
		for (i = 0; i < n; ++i)
			cin >> b[i];
		cin >> a;
		cin >> k;
		m = 0;
		for (i = 0; i < 52; ++i)
			h[i] = 0;
		for (i = 0; i < a.length(); ++i)
			if (a[i] <= 'Z')
				++h[a[i] - 'A'];
			else
				++h[a[i] - 'a' + 26];
		for (i = 0; i < n; ++i)
			if (a != b[i] && a.size() == b[i].size() && is_bro(h, b[i]))
			{
				c[m] = move(b[i]);
				++m;
			}
		cout << m << endl;
		if (k <= m)
		{
			qs(c, 0, m);
			cout << c[k-1] << endl;
		}
	}
	return 0;
}