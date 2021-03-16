#include <iostream>

using namespace std;

void qsort_up(int* a, size_t const& i, size_t const& j)
{
	if (j - i <= 1)
		return;
	size_t p = i;
	int t;
	for (size_t s = i + 1; s < j; ++s)
		if (a[s] < a[i])
		{
			++p;
			t = a[s];
			a[s] = a[p];
			a[p] = t;
		}
	t = a[i];
	a[i] = a[p];
	a[p] = t;
	qsort_up(a, i, p);
	qsort_up(a, p + 1, j);
}

void qsort_down(int* a, size_t const& i, size_t const& j)
{
	if (j - i <= 1)
		return;
	size_t p = i;
	int t;
	for (size_t s = i + 1; s < j; ++s)
		if (a[s] > a[i])
		{
			++p;
			t = a[s];
			a[s] = a[p];
			a[p] = t;
		}
	t = a[i];
	a[i] = a[p];
	a[p] = t;
	qsort_down(a, i, p);
	qsort_down(a, p + 1, j);
}

int main()
{
	size_t n;
	int a[1000];
	size_t i;
	int f;
	while (cin >> n)
	{
		for (i = 0; i < n; ++i)
			cin >> a[i];
		cin >> f;
		if (f)
			qsort_down(a, 0, n);
		else
			qsort_up(a, 0, n);
		for (i = 0; i < n - 1; ++i)
			cout << a[i] << " ";
		cout << a[i] << endl;
	}
	return 0;
}