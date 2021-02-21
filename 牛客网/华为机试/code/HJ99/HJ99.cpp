#include <iostream>

using namespace std;

int main()
{
	int n, i, b, c, a;
	while (cin >> n)
	{
		b = 10;
		c = 1;
		a = 0;
		if (n > 0)
			++a;
		if (n > 1)
			++a;
		for (i = 5; i <= n; i += 10)
		{
			if (i / b > 0)
			{
				b *= 10;
				++c;
			}
			if ((i*i) % b == i)
				++a;
			if (i < n && ((i + 1)*(i + 1)) % b == i + 1)
				++a;
		}
		cout << a << endl;
	}
	return 0;
}