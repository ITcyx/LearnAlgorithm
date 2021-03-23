#include <iostream>

using namespace std;

int main()
{
	int a[100][100], b[100][100], c[100][100], r;
	size_t x, y, z, i, j, t;
	while (cin >> x >> y >> z)
	{
		for (i = 0; i < x; ++i)
			for (j = 0; j < y; ++j)
				cin >> a[i][j];
		for (i = 0; i < y; ++i)
			for (j = 0; j < z; ++j)
				cin >> b[i][j];
		for (i = 0; i < x; ++i)
			for (j = 0; j < z; ++j)
			{
				r = 0;
				for (t = 0; t < y; ++t)
					r += a[i][t] * b[t][j];
				c[i][j] = r;
			}
		for (i = 0; i < x; ++i)
		{
			for (j = 0; j < z; ++j)
				cout << c[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}