#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	size_t i, m;
	short bt[26];
	string::iterator p;
	while (cin >> a)
	{
		for (i = 0; i < 26; ++i)
			bt[i] = 0;
		for (p = a.begin(); p != a.end(); ++p)
			++bt[*p - 'a'];
		m = SIZE_MAX;
		for (i = 0; i < 26; ++i)
			if (bt[i] != 0 && bt[i] < m)
				m = bt[i];
		for (p = a.begin(); p != a.end(); ++p)
			if (bt[*p - 'a'] != m)
				cout << *p;
		cout << endl;
	}
	return 0;
}