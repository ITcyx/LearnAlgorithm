#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> a[101];
	vector<string>::iterator p;
	string b;
	size_t n, f, c;
	int i;
	while (cin >> n)
	{
		cin >> f;
		for (i = 0; i < 101; ++i)
			a[i].clear();
		for (i = 0; i < n; ++i)
		{
			cin >> b >> c;
			a[c].push_back(move(b));
		}
		if (f)
			for (i = 0; i < 101; ++i)
				for (p = a[i].begin(); p != a[i].end(); ++p)
					cout << *p << " " << i << endl;
		else
			for (i = 100; i > -1; --i)
				for (p = a[i].begin(); p != a[i].end(); ++p)
					cout << *p << " " << i << endl;
	}
	return 0;
}