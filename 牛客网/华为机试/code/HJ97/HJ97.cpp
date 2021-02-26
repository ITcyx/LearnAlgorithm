#include <iostream>

using namespace std;

int main()
{
	int n, c, i, a, b, d;
	while (cin >> n)
	{
		c = 0;
		d = 0;
		b = 0;
		for (i = 0; i < n; ++i)
		{
			cin >> a;
			if (a < 0)
			{
				++c;
				continue;
			}
			if (a != 0)
			{
				b += a;
				++d;
			}
		}
		printf("%d %.1f\n", c, double(b) / d);
	}
	return 0;
}