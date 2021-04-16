#include <stdio.h>
#include <string.h>

int main()
{
	char table[128];
	int i, j;
	for (i = 0; i < 128; ++i)
		table[i] = 0;
	table['A'] = 'A';
	table['E'] = '3';
	table['H'] = 'H';
	table['I'] = 'I';
	table['J'] = 'L';
	table['L'] = 'J';
	table['M'] = 'M';
	table['O'] = 'O';
	table['S'] = '2';
	table['T'] = 'T';
	table['U'] = 'U';
	table['V'] = 'V';
	table['W'] = 'W';
	table['X'] = 'X';
	table['Y'] = 'Y';
	table['Z'] = '5';
	table['1'] = '1';
	table['2'] = 'S';
	table['3'] = 'E';
	table['5'] = 'Z';
	table['8'] = '8';
	char string_buffer[200];
	int len;
	bool fp, fm;
	while (scanf("%s", string_buffer) == 1)
	{
		len = strlen(string_buffer);
		j = len - 1;
		i = 0;
		fp = fm = true;
		while (fp || fm)
		{
			if (fp&&string_buffer[i] != string_buffer[j])
				fp = false;
			if (fm&&string_buffer[i] != table[string_buffer[j]])
				fm = false;
			++i;
			--j;
			if (i > j)
				break;
		}
		if (fp&&fm)
			printf("%s -- is a mirrored palindrome.\n\n", string_buffer);
		else if (fp)
			printf("%s -- is a regular palindrome.\n\n", string_buffer);
		else if (fm)
			printf("%s -- is a mirrored string.\n\n", string_buffer);
		else
			printf("%s -- is not a palindrome.\n\n", string_buffer);
	}
	return 0;
}