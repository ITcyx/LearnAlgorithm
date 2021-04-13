#include <stdio.h>

int main()
{
	char t1[] = "1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./";
	char t2[] = "`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.";
	char table[128], c;
	int i;
	for (i = 0; i < 128; ++i)
		table[i] = i;
	for (i = 0; i < 44; ++i)
		table[t1[i]] = t2[i];
	while ((c = getchar()) != EOF)
		printf("%c", table[c]);
	return 0;
}