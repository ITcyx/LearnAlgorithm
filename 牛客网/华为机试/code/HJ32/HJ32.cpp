#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	char char_table[10000];
	string::iterator a_p;
	size_t ah[10000], ah_s, right, char_table_t, i, t, mid;
	char_table[0] = '$';
	char_table[1] = '#';
	while (cin >> a)
	{
		char_table_t = 1;
		for (a_p = a.begin(); a_p != a.end(); ++a_p)
		{
			char_table[++char_table_t] = *a_p;
			char_table[++char_table_t] = '#';
		}
		char_table[++char_table_t] = '^';
		ah_s = a.length() * 2 + 1;
		mid = 0;
		right = 0;
		for (i = 0; i < ah_s; ++i)
		{
			if (i < right)
				ah[i] = right - i < ah[2 * mid - i] ? right - i : ah[2 * mid - i];
			else
				ah[i] = 0;
			while (char_table[i + ah[i] + 2] == char_table[i - ah[i]])
				++ah[i];
			if (i + ah[i] > right)
			{
				right = i + ah[i];
				mid = i;
			}
		}
		t = 0;
		for (i = 0; i < ah_s; ++i)
			if (ah[i] > t)
				t = ah[i];
		cout << t << endl;
	}
	return 0;
}