#include <iostream>
#include <string>

using namespace std;

void qs(string a[1000], int i, int j)
{
	if (j - i <= 1)
		return;
	int p = i;
	string c;
	for (int s = i + 1; s < j; ++s)
		if (a[s] < a[i])
		{
			++p;
			c = move(a[p]);
			a[p] = move(a[s]);
			a[s] = move(c);
		}
	c = move(a[p]);
	a[p] = move(a[i]);
	a[i] = move(c);
	qs(a, i, p);
	qs(a, p + 1, j);
}

int main()
{
	string a[1000];
	int n, i;
	cin >> n;
	for (i = 0; i < n; ++i)
		cin >> a[i];
	qs(a, 0, n);
	for (i = 0; i < n; ++i)
		cout << a[i] << endl;
	return 0;
}