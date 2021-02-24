#include <iostream>

using namespace std;

int main()
{
	int n, m, c;
	while (cin >> n)
	{
		m = 0;
		while (n)
		{
			c = 0;
			while (n & 1)
			{
				++c;
				n >>= 1;
			}
			if (c > m)
				m = c;
			n >>= 1;
		}
		cout << m << endl;
	}
	return 0;
}