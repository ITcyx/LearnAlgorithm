#include <iostream>
#include <string>

using namespace std;

void qs(int* d, int i, int j)
{
	if (j - i <= 1)
		return;
	int p = i;
	int c;
	for (int s = i + 1; s < j; ++s)
		if (d[s] > d[i])
		{
			c = d[s];
			d[s] = d[p + 1];
			d[p + 1] = c;
			++p;
		}
	c = d[i];
	d[i] = d[p];
	d[p] = c;
	qs(d, i, p);
	qs(d, p + 1, j);
}

int main()
{
	int N, i, j, c, t;
	string a;
	int d[26];
	while (cin >> N)
	{
		for (i = 0; i < N; ++i)
		{
			cin >> a;
			for (j = 0; j < 26; ++j)
				d[j] = 0;
			for (j = 0; j < a.length(); ++j)
				if (a[j] <= 'Z')
					++d[a[j] - 'A'];
				else
					++d[a[j] - 'a'];
			t = 0;
			for (j = 0; j < 26; ++j)
				if (d[j] != 0)
				{
					d[t] = d[j];
					++t;
				}
			qs(d, 0, t);
			c = 0;
			for (j = 26; j > 26 - t; --j)
				c += j * d[26 - j];
			cout << c << endl;
		}
	}
	return 0;
}