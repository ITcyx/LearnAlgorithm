#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b;
	int i, j;
	while (cin >> a >> b)
	{
		j = a.length();
		for (i = 0; i < j; ++i)
		{
			if (a[i] == '9')
				a[i] = '0';
			else if (a[i] == 'z')
				a[i] = 'A';
			else if (a[i] == 'Z')
				a[i] = 'a';
			else if (a[i] < '9')
				++a[i];
			else if (a[i] < 'Z')
				a[i] += 33;
			else
				a[i] -= 31;
		}
		j = b.length();
		for (i = 0; i < j; ++i)
		{
			if (b[i] == '0')
				b[i] = '9';
			else if (b[i] == 'A')
				b[i] = 'z';
			else if (b[i] == 'a')
				b[i] = 'Z';
			else if (b[i] <= '9')
				--b[i];
			else if (b[i] <= 'Z')
				b[i] += 31;
			else
				b[i] -= 33;
		}
		cout << a << endl << b << endl;
	}
	return 0;
}