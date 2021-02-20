#include <iostream>

using namespace std;

int main()
{
	int n;
	int b[100];
	int ba[100];
	int i, a, j;
	while (cin >> n)
	{
		for (i = 0; i < n; ++i)
			cin >> b[i];
		ba[n - 1] = 1;
		for (i = n - 2; i > -1; --i)
		{
			a = 1;
			for (j = i + 1; j < n; ++j)
				if (b[j] > b[i] && ba[j] + 1 > a)
					a = ba[j] + 1;
			ba[i] = a;
		}
		a = 1;
		for (i = 0; i < n; ++i)
			if (ba[i] > a)
				a = ba[i];
		cout << a << endl;
	}
	return 0;
}