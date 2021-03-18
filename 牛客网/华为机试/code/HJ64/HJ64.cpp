#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	string::iterator p;
	int n, c, k;
	while (cin >> n)
	{
		c = k = 1;
		cin >> a;
		if (n > 4)
		{
			for (p = a.begin(); p != a.end(); ++p)
				if (*p == 'U')
				{
					if (k == 1)
					{
						c = n - 3;
						k = n;
					}
					else if (k == c)
					{
						--c;
						--k;
					}
					else
						--k;
				}
				else
				{
					if (k == n)
						c = k = 1;
					else if (k == c + 3)
					{
						++c;
						++k;
					}
					else
						++k;
				}
			cout << c << " " << c + 1 << " " << c + 2 << " " << c + 3 << endl;
			cout << k << endl;
		}
		else
		{
			for (p = a.begin(); p != a.end(); ++p)
				if (*p == 'U')
				{
					if (k == 1)
						k = n;
					else
						--k;
				}
				else
				{
					if (k == n)
						k = 1;
					else
						++k;
				}
			for (c = 1; c <= n; ++c)
				cout << c << " ";
			cout << endl << k << endl;
		}
	}
	return 0;
}