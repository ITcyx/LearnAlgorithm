#include <iostream>
#include <string>

using namespace std;

int main()
{
	bool h[128] = {};
	string a;
	int n = 0;
	cin >> a;
	int m = a.length();
	for (int i = 0; i < m; ++i)
		if (!h[int(a[i])])
		{
			++n;
			h[int(a[i])] = true;
		}
	cout << n << endl;
	return 0;
}