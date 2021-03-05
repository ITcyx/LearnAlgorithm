#include <iostream>

using namespace std;

int main()
{
	int k[100][100], m, n, i, j;
	for (i = 1; i < 100; ++i)
		k[0][i] = k[1][i] = 1;
	for (j = 1; j < 100; ++j)
		k[j][1] = 1;
	for (j = 2; j < 100; ++j)
		for (i = 2; i < 100; ++i)
			if (j < i)
				k[j][i] = k[j][j];
			else
				k[j][i] = k[j][i - 1] + k[j - i][i];
	while (cin >> m >> n)
		cout << k[m][n] << endl;
	return 0;
}