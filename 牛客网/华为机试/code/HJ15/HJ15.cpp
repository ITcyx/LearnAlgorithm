#include <iostream>

using namespace std;

int main()
{
	int n, i = 0;
	cin >> n;
	while (n)
	{
		n = n & (n - 1);
		++i;
	}
	cout << i;
	return 0;
}