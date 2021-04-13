#include <stdio.h>

int main()
{
	bool f = true;
	int c;
	while ((c = getchar()) != EOF)
		if (c == '"')
		{
			printf("%s", f ? "``" : "''");
			f = !f;
		}
		else
			printf("%c", c);
	return 0;
}