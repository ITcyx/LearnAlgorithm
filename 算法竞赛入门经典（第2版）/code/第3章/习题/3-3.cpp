#include <stdio.h>

int main()
{
	int T, i, n, j, x, y;
	int a[10];
	for (scanf("%d", &T); T > 0; --T)
	{
		scanf("%d", &n);
		for (i = 0; i < 10; ++i)
			a[i] = 0;
		for (j = 1; n / j; j *= 10)
		{
			x = n / (j * 10);
			y = n % (j * 10);
			for (i = 1; i < 10; ++i)
				a[i] += x * j;
			a[0] += (x - 1)*j;
			for (i = 0; i < y / j; ++i)
				a[i] += j;
			a[i] += (y % j) + 1;
		}
		for (i = 0; i < 9; ++i)
			printf("%d ", a[i]);
		printf("%d\n", a[9]);
	}
	return 0;
}