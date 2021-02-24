#include <iostream>

using namespace std;

int main()
{
	int y, m, d, t, i;
	int dt[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	while (cin >> y >> m >> d)
	{
		if (y % 100 == 0)
		{
			if (y % 400 == 0)
				dt[1] = 29;
			else
				dt[1] = 28;
		}
		else if (y % 4 == 0)
			dt[1] = 29;
		else
			dt[1] = 28;
		t = 0;
		for (i = 0; i < m - 1; ++i)
			t += dt[i];
		cout << t + d << endl;
	}
	return 0;
}