#include <iostream>

using namespace std;

int main()
{
	int N;
	int a[100][100];
	int i, j, n = 100, ni = 0, nj = 1;
	a[0][0] = 1;
	for (j = 1; j < 100; ++j)
		a[0][j] = a[0][j - 1] + (++nj);
	for (i = 1; i < 100; ++i)
	{
		nj = ni;
		++ni;
		--n;
		for (j = 0; j < n; ++j)
			a[i][j] = a[i - 1][j] + (++nj);
	}
	while (cin >> N)
	{
		n = N;
		for (i = 0; i < N; ++i)
		{
			for (j = 0; j < n; ++j)
				cout << a[i][j] << " ";
			cout << endl;
			--n;
		}
	}
	return 0;
}