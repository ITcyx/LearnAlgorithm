#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	getline(cin, a);
	int c = a.length();
	char t;
	for (int i = 0; i < c / 2; ++i)
	{
		t = a[i];
		a[i] = a[c - i - 1];
		a[c - i - 1] = t;
	}
	cout << a;
	return 0;
}