#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	int c;
	while (a%b != 0)
	{
		if (a > b)
		{
			c = b;
			b = a % b;
			a = c;
		}
		else
		{
			c = a;
			a = b;
			b = c;
		}
	}
	return b;
}

int main()
{
	int n1, n2, t, k;
	char g;
	while (cin >> n1 >> g >> n2)
	{
		t = gcd(n1, n2);
		n1 /= t;
		n2 /= t;
		while (n1 != 1)
		{
			k = n2 / n1 + 1;
			cout << "1/" << k << '+';
			n1 *= k;
			n1 -= n2;
			n2 *= k;
			t = gcd(n1, n2);
			n1 /= t;
			n2 /= t;
		}
		cout << n1 << '/' << n2 << endl;
	}
	return 0;
}