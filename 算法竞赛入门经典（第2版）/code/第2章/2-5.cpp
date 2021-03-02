#include <stdio.h>

int main()
{
	int a, b, c;
	int i = 0;
	while (scanf("%d%d%d", &a, &b, &c) == 3)
	{
		if (a == 0 && b == 0 && c == 0)
			break;
		printf("Case %d: %.*f\n", ++i, c, a*1.0 / b);
	}
	return 0;
}