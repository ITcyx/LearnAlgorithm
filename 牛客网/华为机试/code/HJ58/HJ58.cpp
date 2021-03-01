#include <iostream>

using namespace std;

void qs(int b[1000], int const& i, int const& j)
{
	if (j - i <= 1)
		return;
	int p = i, c;
	for (int s = i + 1; s < j; ++s)
		if (b[s] < b[i])
		{
			++p;
			c = b[s];
			b[s] = b[p];
			b[p] = c;
		}
	c = b[p];
	b[p] = b[i];
	b[i] = c;
	qs(b, i, p);
	qs(b, p + 1, j);
}

int main()
{
	int n, k, i;
	int b[1000];
	while (cin >> n >> k)
	{
		for (i = 0; i<n&&cin >> b[i]; ++i) {}
		qs(b, 0, n);
		for (i = 0; i < k&&cout << b[i] << " "; ++i) {}
		cout << endl;
	}
	return 0;
}