#include <iostream>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 1)
			cout << 1 << endl;
		else if (n < 4)
			cout << n - 1 << endl;
		else
		{
			int a = 1, b = 1, c;
			while (n - 4)
			{
				c = a;
				a = a + b;
				b = c;
				--n;
			}
			cout << 2 * a + b << endl;
		}
	}
	return 0;
}