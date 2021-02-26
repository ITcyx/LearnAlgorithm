#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	int i, s, b;
	while (cin >> a)
	{
		b = 0;
		s = a.length();
		for (i = 2; i < s; ++i)
		{
			b <<= 4;
			if (a[i] <= '9')
				b += a[i] - '0';
			else
				b += (a[i] - 'A') + 10;
		}
		cout << b << endl;
	}
	return 0;
}