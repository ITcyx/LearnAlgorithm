#include <iostream>

using namespace std;

int main()
{
	int a, b, c, i, j;
	cin >> i >> j;
	a = i;
	b = j;
	if (b > a)
	{
		c = a;
		a = b;
		b = c;
	}
	while (a%b)
	{
		c = a % b;
		a = c;
		if (b > a)
		{
			c = a;
			a = b;
			b = c;
		}
	}
	cout << i / b * j;
	return 0;
}