#include <iostream>

using namespace std;

int main()
{
	int n, c;
	while (cin >> n)
	{
		c = 0;
		while (n)
		{
			n = n & (n - 1);
			++c;
		}
		cout << c << endl;
	}
	return 0;
}