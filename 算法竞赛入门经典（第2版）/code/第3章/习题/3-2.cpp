#include <stdio.h>

int main()
{
	int n, i;
	char s[100];
	double a, t, c;
	for (scanf("%d", &n); n > 0; --n)
	{
		scanf("%s", s);
		a = 0;
		for (i = 0; s[i]; ++i)
		{
			if (s[i] == 'C')
				t = 12.01;
			else if (s[i] == 'H')
				t = 1.008;
			else if (s[i] == 'O')
				t = 16.00;
			else
				t = 14.01;
			if (s[i + 1] >= '0'&&s[i + 1] <= '9')
				if (s[i + 2] >= '0'&&s[i + 2] <= '9')
				{
					c = (s[i + 1] - '0') * 10 + (s[i + 2] - '0');
					i += 2;
				}
				else
				{
					c = s[i + 1] - '0';
					++i;
				}
			else
				c = 1;
			a += t * c;
		}
		printf("%.3f\n", a);
	}
	return 0;
}