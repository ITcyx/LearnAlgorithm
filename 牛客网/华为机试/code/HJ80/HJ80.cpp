#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool hash_add(int* hash_table, int const& n)
{
	size_t nj = n % 2011, ni = n % 2003, s;
	for (size_t i = 0; i < 2000; ++i)
	{
		s = (nj + ni * i) % 2000;
		if (hash_table[s] == n)
			return false;
		else if (hash_table[s] == INT_MAX)
		{
			hash_table[s] = n;
			return true;
		}
	}
	return false;
}

void qsort(vector<int> a, vector<int>::iterator const& i, vector<int>::iterator const& j)
{
	if (j - i <= 1)
		return;
	auto p = i;
	int t;
	for (auto s = i + 1; s != j; ++s)
		if (*s < *i)
		{
			++p;
			t = *s;
			*s = *p;
			*p = t;
		}
	t = *i;
	*i = *p;
	*p = t;
	qsort(a, i, p);
	qsort(a, p + 1, j);
}

void hash_reset(int* hash_table)
{
	for (size_t i = 0; i < 2000; ++i)
		hash_table[i] = INT_MAX;
}

int main()
{
	size_t i1, i2, i;
	int hash_table[2000];
	vector<int> a;
	vector<int>::iterator p;
	int c;
	while (cin >> i1)
	{
		hash_reset(hash_table);
		a.clear();
		for (i = 0; i < i1; ++i)
		{
			cin >> c;
			if (hash_add(hash_table, c))
				a.push_back(c);
		}
		cin >> i2;
		for (i = 0; i < i2; ++i)
		{
			cin >> c;
			if (hash_add(hash_table, c))
				a.push_back(c);
		}
		qsort(a, a.begin(), a.end());
		for (p = a.begin(); p != a.end(); ++p)
			cout << *p;
		cout << endl;
	}
	return 0;
}