#include <stdio.h>

int main()
{
	int answer[1010], guess[1010], table_a[10], table_g[10];
	int len, game_count = 0, i, t, A, B;
	while (scanf("%d", &len) == 1 && len)
	{
		printf("Game %d:\n", ++game_count);
		for (i = 1; i < 10; ++i)
			table_a[i] = 0;
		for (i = 0; i < len; ++i)
		{
			scanf("%d", &t);
			answer[i] = t;
			++table_a[t];
		}
		while (true)
		{
			for (i = 1; i < 10; ++i)
				table_g[i] = 0;
			for (i = 0; i < len; ++i)
			{
				scanf("%d", &t);
				guess[i] = t;
				++table_g[t];
			}
			if (guess[0] == 0)
				break;
			A = B = 0;
			for (i = 1; i < 10; ++i)
				if (table_a[i] < table_g[i])
					table_g[i] = table_a[i];
			for(i=0;i<len;++i)
				if (answer[i] == guess[i])
				{
					--table_g[answer[i]];
					++A;
				}
			for (i = 1; i < 10; ++i)
				B += table_a[i] < table_g[i] ? table_a[i] : table_g[i];
			printf("    (%d,%d)\n", A, B);
		}
	}
	return 0;
}