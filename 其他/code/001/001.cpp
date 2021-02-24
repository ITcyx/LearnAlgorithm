#include <iostream>
#include <climits>

using namespace std;

int main()
{
	int n = 0, n2, i, j, c1, c2;
	short m[40001][101];
	int a[101];
	for (n = 0; cin >> a[n]; ++n)
	{}
	n2 = n * n;
	for (i = 0; i <= 2 * n2; ++i)
	{
		if (-a[0] <= i - 2 * n2)
			m[i][0] = -a[0];
		else
			m[i][0] = SHRT_MIN;
	}
	for (; i <= 4 * n2; ++i)
	{
		if (a[0] <= i - 2 * n2)
			m[i][0] = a[0];
		else
			m[i][0] = -a[0];
	}
	for (j = 1; j < n; ++j)
	{
		for (i = 0; i <= 4 * n2; ++i)
		{
			if (i + a[j] > 4 * n2)
				c1 = m[4 * n2][j - 1] - a[j];
			else if (m[i + a[j]][j - 1] == SHRT_MIN)
				c1 = SHRT_MIN;
			else
				c1 = m[i + a[j]][j - 1] - a[j];
			if (i - a[j] < 0 || m[i - a[j]][j - 1] == SHRT_MIN)
				c2 = SHRT_MIN;
			else
				c2 = m[i - a[j]][j - 1] + a[j];
			c1 > c2 ? m[i][j] = c1 : m[i][j] = c2;
		}
	}
	cout << m[3 * n2][n - 1] << endl;
	return 0;
}