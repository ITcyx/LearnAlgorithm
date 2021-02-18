#include <iostream>
#include <string>

using namespace std;

void qs(string& a, int i, int j)
{
	if (j - i <= 1)
		return;
	int c, p = i;
	for (int s = i + 1; s < j; ++s)
		if (a[s] < a[i])
		{
			c = a[s];
			a[s] = a[p + 1];
			a[p + 1] = c;
			++p;
		}
	c = a[i];
	a[i] = a[p];
	a[p] = c;
	qs(a, i, p);
	qs(a, p + 1, j);
}

int main()
{
	string a;
	while (cin >> a)
	{
		qs(a, 0, a.length());
		cout << a << endl;
	}
	return 0;
}