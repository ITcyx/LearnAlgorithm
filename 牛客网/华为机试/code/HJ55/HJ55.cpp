#include <iostream>

using namespace std;

int main()
{
	int N;
	int i, c, j;
	while (cin >> N)
	{
		c = 0;
		for (i = 7; i <= N; ++i)
		{
			if (i % 7 == 0)
			{
				++c;
				continue;
			}
			j = 1;
			while (i / j)
			{
				if ((i / j) % 10 == 7)
				{
					++c;
					break;
				}
				j *= 10;
			}
		}
		cout << c << endl;
	}
	return 0;
}