#include <stdio.h>

int main()
{
	int n, i, ji, m, jm;
	char cs[105];
	bool f;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", cs);
		m = 0;
		f = false;
		for (i = 1; cs[i]; ++i)
		{
			if (cs[i] < cs[m])
			{
				m = i;
				continue;
			}
			else if (cs[i] > cs[m])
				continue;
			jm = m + 1;
			for (ji = i + 1; i != ji; ++ji)
			{
				if (cs[ji] == '\0')
				{
					f = true;
					ji = 0;
				}
				if (cs[jm] == '\0')
					jm = 0;
				if (cs[ji] < cs[jm])
				{
					m = i;
					break;
				}
				else if (cs[ji] > cs[jm])
					break;
				++jm;
			}
			if (f)
				break;
			if (m == i)
				i = ji - 1;
			else
				i = ji;
		}
		for (i = m; cs[i]; ++i)
			printf("%c", cs[i]);
		for (i = 0; i < m; ++i)
			printf("%c", cs[i]);
		printf("\n");
	}
	return 0;
}