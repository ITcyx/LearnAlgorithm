#include <stdio.h>

int main()
{
	int i = 0, a, b, c, n;
	while (scanf("%d%d%d", &a, &b, &c) == 3)
	{
		printf("Case %d: ", ++i);
		n = (70 * a + 21 * b + 15 * c) % 105;
		if (n < 10 || n>100)
			printf("No answer\n");
		else
			printf("%d\n", n);
	}
	return 0;
}