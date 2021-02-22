#include <iostream>

using namespace std;

int main()
{
	int m, n, i, j;
	while (cin >> m >> n)
	{
		cout << 0 << endl;
		cin >> i >> j;
		if (i >= m || i < 0 || j >= n || j < 0)
		{
			cout << -1 << endl;
			cin >> i >> j;
		}
		else
		{
			cin >> i >> j;
			if (i >= m || i < 0 || j >= n || j < 0)
				cout << -1 << endl;
			else
				cout << 0 << endl;
		}
		cin >> i;
		if (m == 9 || i >= m || i < 0)
			cout << -1 << endl;
		else
			cout << 0 << endl;
		cin >> j;
		if (n == 9 || j >= n || j < 0)
			cout << -1 << endl;
		else
			cout << 0 << endl;
		cin >> i >> j;
		if (i >= m || i < 0 || j >= n || j < 0)
			cout << -1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}