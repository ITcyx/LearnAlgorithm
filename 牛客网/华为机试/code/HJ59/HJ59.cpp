#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	size_t hash_c[128][2];
	size_t i, p;
	while (cin >> a)
	{
		for (i = 0; i < 128; ++i)
			hash_c[i][0] = hash_c[i][1] = 0;
		for (i = 0; i < a.size(); ++i)
		{
			++hash_c[a[i]][0];
			hash_c[a[i]][1] = i;
		}
		p = SIZE_MAX;
		for (i = 0; i < 128; ++i)
			if (hash_c[i][0] == 1 && hash_c[i][1] < p)
				p = hash_c[i][1];
		if (p == SIZE_MAX)
			cout << -1 << endl;
		else
			cout << a[p] << endl;
	}
	return 0;
}