#include <iostream>

using namespace std;

int main()
{
	bool table[120000];
	bool* table_pi = table;
	bool* const table_pj = table + 120000;
	size_t i, j, n, m[10], x[10], t, bs_c;
	bool* bs[10000];
	bool** bs_pi;
	bool** bs_pj;
	*table_pi = true;
	for (++table_pi; table_pi != table_pj; ++table_pi)
		*table_pi = false;
	bs[0] = table;
	bs_c = 1;
	while (cin >> n)
	{
		bs_pj = bs + bs_c;
		for (bs_pi = bs + 1; bs_pi != bs_pj; ++bs_pi)
			**bs_pi = false;
		bs_c = 1;
		for (i = 0; i < n; ++i)
			cin >> m[i];
		for (j = 0; j < n; ++j)
			cin >> x[j];
		for (i = 0; i < n; ++i)
		{
			bs_pj = bs + bs_c;
			for (j = 1; j <= x[i]; ++j)
			{
				t = j * m[i];
				for (bs_pi = bs; bs_pi != bs_pj; ++bs_pi)
					if (!*(*bs_pi + t))
					{
						table_pi = *bs_pi + t;
						*table_pi = true;
						bs[bs_c] = table_pi;
						++bs_c;
					}
			}
		}
		cout << bs_c << endl;
	}
	return 0;
}