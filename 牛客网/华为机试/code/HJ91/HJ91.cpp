#include <iostream>

using namespace std;

int main()
{
	int n, m, i, j, a, t;
	while (cin >> n >> m)
	{
		a = 1;
		j = m + n;
		m > n ? i = n : i = m;
		for (t = 0; t < i; ++t)
		{
			a *= j - t;
			a /= t + 1;
		}
		cout << a << endl;
	}
	return 0;
}