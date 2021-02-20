#include <iostream>

using namespace std;

int main()
{
	int m, i;
	while (cin >> m)
	{
		for (i = m * m - m + 1; i < m*m + m - 1; i += 2)
			cout << i << "+";
		cout << i << endl;
	}
	return 0;
}