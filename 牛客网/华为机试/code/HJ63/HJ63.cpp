#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	int m, k, n;
	string::iterator p, q, mp;
	while (cin >> a)
	{
		cin >> k;
		m = 0;
		for (p = a.begin(); p != a.begin() + k; ++p)
			if (*p == 'G' || *p == 'C')
				++m;
		q = a.begin();
		n = m;
		mp = a.begin();
		for (; p != a.end(); ++p)
		{
			if (*q == 'G' || *q == 'C')
				--n;
			++q;
			if (*p == 'G' || *p == 'C')
				++n;
			if (n > m)
			{
				m = n;
				mp = q;
			}
		}
		for (p = mp; p != mp + k; ++p)
			cout << *p;
		cout << endl;
	}
	return 0;
}