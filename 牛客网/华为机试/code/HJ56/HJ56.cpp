#include <iostream>

using namespace std;

int main()
{
	int n, c, i, d;
	while (cin >> n)
	{
		c = 0;
		while (n > 1)
		{
			d = 1;
			for (i = 2; i*i <= n; ++i)
				if (n%i == 0)
				{
					if (i*i == n)
						d += i;
					else
						d = d + i + n / i;
				}
			if (d == n)
				++c;
			--n;
		}
		cout << c << endl;
	}
	return 0;
}