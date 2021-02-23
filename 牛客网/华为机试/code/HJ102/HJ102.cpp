#include <iostream>
#include <string>

using namespace std;

int main()
{
	int b[36], i, j, m, n;
	char bc[37];
	string a;
	bool f;
	while (cin >> a)
	{
		for (i = 0; i < 36; ++i)
			b[i] = 0;
		for (i = 0; i < a.length(); ++i)
			if (a[i] <= '9')
				++b[a[i] - '0'];
			else
				++b[a[i] - 'a' + 10];
		j = 0;
		f = true;
		while (f)
		{
			m = 0;
			f = false;
			for (i = 0; i < 36; ++i)
				if (b[i] > m)
				{
					f = true;
					m = b[i];
					n = i;
				}
			if (f)
			{
				if (n < 10)
					bc[j] = '0' + n;
				else
					bc[j] = 'a' + (n - 10);
				++j;
				b[n] = 0;
			}
		}
		bc[j] = '\0';
		cout << bc << endl;
	}
	return 0;
}