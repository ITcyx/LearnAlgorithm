#include <iostream>
#include <string>

using namespace std;

inline bool is_alpha(char const& c)
{
	if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))
		return true;
	return false;
}

inline bool is_small(char const& left, char const& right)
{
	int l, r;
	if (left >= 'a'&&left <= 'z')
		l = left - 'a';
	else
		l = left - 'A';
	if (right >= 'a'&&right <= 'z')
		r = right - 'a';
	else
		r = right - 'A';
	return l < r ? true : false;
}

void bs(string& a, int c[1000], int const& n)
{
	if (n <= 1)
		return;
	int i, j;
	char t;
	for (i = 0; i < n; ++i)
		for (j = n - 1; j > i; --j)
			if (is_small(a[c[j]], a[c[j - 1]]))
			{
				t = a[c[j]];
				a[c[j]] = a[c[j - 1]];
				a[c[j - 1]] = t;
			}
}

int main()
{
	string a;
	int c[1000], n, i;
	while (getline(cin, a))
	{
		n = 0;
		for (i = 0; i < a.length(); ++i)
			if (is_alpha(a[i]))
			{
				c[n] = i;
				++n;
			}
		bs(a, c, n);
		cout << a << endl;
	}
	return 0;
}