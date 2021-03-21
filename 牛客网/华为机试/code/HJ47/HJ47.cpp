#include <iostream>

using namespace std;

int main()
{
	int m, n, M, N, A, B, i, j;
	while (cin >> m >> n)
	{
		cin >> M >> A;
		cout << M << " " << A << endl;
		for (i = 1; i < m; ++i)
		{
			cin >> N >> B;
			if (M == N)
				continue;
			for (j = 1; j < N - M; ++j)
				cout << M + j << " " << A + (B - A) / (N - M)*j << endl;
			cout << N << " " << B << endl;
			M = N;
			A = B;
		}
	}
	return 0;
}