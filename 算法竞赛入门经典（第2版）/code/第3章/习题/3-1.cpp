#include<stdio.h>

int main()
{
	int T, i, j = 0, p = 0;
	char s[80];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		j = 0, p = 0;
		for (i = 0; s[i]; ++i)
			if (s[i] == 'O')
				p += ++j;
			else
				j = 0;
		printf("%d\n", p);
	}
	return 0;
}