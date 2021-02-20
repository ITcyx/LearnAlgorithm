#include <iostream>

using namespace std;

bool prime(int const& a)
{
	for (int i = 3; i*i <= a; i += 2)
		if (a%i == 0)
			return false;
	return true;
}

int main()
{
	int n, i, h;
	while (cin >> n)
	{
		if (n == 4)
			cout << 2 << endl << 2 << endl;
		h = n / 2;
		if (h % 2 == 0)
			for (i = 1; true; i += 2)
			{
				if (prime(h - i) && prime(h + i))
				{
					cout << h - i << endl << h + i << endl;
					break;
				}
			}
		else
			for (i = 0; true; i += 2)
				if (prime(h - i) && prime(h + i))
				{
					cout << h - i << endl << h + i << endl;
					break;
				}
	}
	return 0;
}