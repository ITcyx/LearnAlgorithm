#include <iostream>

using namespace std;

int main()
{
	int a;
	cin >> a;
	bool b[10] = {};
	int c = 0, d;
	while (a != 0)
	{
		d = a % 10;
		if (!b[d])
		{
			c *= 10;
			c += d;
			b[d] = true;
		}
		a /= 10;
	}
	cout << c;
	return 0;
}