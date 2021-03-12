#include <iostream>

using namespace std;

int main()
{
	char a[1000];
	int k;
	while (cin >> a)
	{
		cin >> k;
		a[k] = '\0';
		cout << a << endl;
	}
	return 0;
}