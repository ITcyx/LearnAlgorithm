#include <iostream>
#include <string>

using namespace std;

int search(string* p, string const& a, int const& n)
{
	for (int i = 0; i < n; ++i)
		if (a == p[i])
			return i;
	return -1;
}

int main()
{
	int n, m, i, j, c;
	string p[100];
	int pn[100];
	string a;
	while (cin >> n)
	{
		for (i = 0; i < n; ++i)
			cin >> p[i];
		for (i = 0; i < n; ++i)
			pn[i] = 0;
		j = 0;
		cin >> m;
		for (i = 0; i < m; ++i)
		{
			cin >> a;
			c = search(p, a, n);
			if (c < 0)
				++j;
			else
				++pn[c];
		}
		for (i = 0; i < n; ++i)
			cout << p[i] << " : " << pn[i] << endl;
		cout << "Invalid : " << j << endl;
	}
	return 0;
}