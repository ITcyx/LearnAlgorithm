#include <iostream>

using namespace std;

int main()
{
	size_t list[10001][2];
	size_t i, j, n, h, x, y;
	for (i = 0; i < 10001; ++i)
		list[i][0] = list[i][1] = 0;
	while (cin >> n >> h)
	{
		for (i = 1; i < n; ++i)
		{
			cin >> x >> y;
			list[x][0] = list[y][0];
			list[y][0] = x;
			list[x][1] = y;
			list[list[x][0]][1] = x;
		}
		cin >> j;
		if (j == h)
			h = list[h][0];
		else
			list[list[j][1]][0] = list[j][0];
		for (i = 0; i < n - 1; ++i)
		{
			cout << h << " ";
			h = list[h][0];
		}
		cout << endl;
	}
	return 0;
}