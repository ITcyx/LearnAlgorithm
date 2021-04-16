#include <stdio.h>

int main()
{
	int table[100050], i, n, t;
	for (i = 0; i < 100050; ++i)
		table[i] = 0;
	for (i = 1; i < 100000; ++i)
	{
		n = t = i;
		while (t > 0)
		{
			n += t % 10;
			t /= 10;
		}
		if (table[n] == 0)
			table[n] = i;
		else if (table[n] > i)
			table[n] = i;
	}
	for (scanf("%d", &i); i; --i)
	{
		scanf("%d", &n);
		printf("%d\n", table[n]);
	}
	return 0;
}