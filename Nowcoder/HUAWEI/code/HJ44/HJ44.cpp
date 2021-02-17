#include <iostream>

using namespace std;

bool check(int a[9][9], int i, int j)
{
	int m;
	for (m = 0; m < 9; ++m)
	{
		if (m != i && a[m][j] == a[i][j])
			return false;
		if (m != j && a[i][m] == a[i][j])
			return false;
	}
	int p = (i / 3) * 3, q = (j / 3) * 3, n;
	for (m = 0; m < 3; ++m)
		for (n = 0; n < 3; ++n)
			if ((p + m != i || q + n != j) && a[i][j] == a[p + m][q + n])
				return false;
	return true;
}


bool dfs(int a[9][9], int i, int j)
{
	if (j < 8)
	{
		if (a[i][j] != 0)
			return dfs(a, i, j + 1);
		for (int n = 1; n < 10; ++n)
		{
			a[i][j] = n;
			if (check(a, i, j) && dfs(a, i, j + 1))
				return true;
		}
		a[i][j] = 0;
		return false;
	}
	else if (i < 8)
	{
		if (a[i][j] != 0)
			return dfs(a, i + 1, 0);
		for (int n = 1; n < 10; ++n)
		{
			a[i][j] = n;
			if (check(a, i, j) && dfs(a, i + 1, 0))
				return true;
		}
		a[i][j] = 0;
		return false;
	}
	else
	{
		if (a[i][j] != 0)
			return true;
		for (int n = 1; n < 10; ++n)
		{
			a[i][j] = n;
			if (check(a, i, j))
				return true;
		}
		a[i][j] = 0;
		return false;
	}
	return true;
}

int main()
{
	int a[9][9];
	int i, j;
	for (j = 0; j < 9; ++j)
		for (i = 0; i < 9; ++i)
			cin >> a[i][j];
	dfs(a, 0, 0);
	for (j = 0; j < 9; ++j)
	{
		for (i = 0; i < 9; ++i)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}