#include <stdio.h>

int main()
{
	int n, m, c = 0;
	long long i;
	double a;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (n == 0 && m == 0)
			break;
		a = 0;
		for (i = n; i <= m; ++i)
			a += 1.0 / (i*i);
		printf("Case %d: %.5f\n", ++c, a);
	}
	return 0;
}