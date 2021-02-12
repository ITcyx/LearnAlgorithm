#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	getline(cin, a);
	char b, B;
	cin >> b;
	if (b < 'a')
		B = b + 32;
	else
		B = b - 32;
	int i, j = 0, s = a.length();
	for (i = 0; i < s; ++i)
		if (a[i] == b || a[i] == B)
			++j;
	cout << j;
	return 0;
}