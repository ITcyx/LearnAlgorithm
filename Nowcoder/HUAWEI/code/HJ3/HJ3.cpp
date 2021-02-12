#include <iostream>

using namespace std;

int main()
{
	int N, i;
	while (cin >> N)
	{
		bool flag[1001] = { false };
		++N;
		while (--N)
		{
			cin >> i;
			flag[i] = true;
		}
		for (i = 0; i < 1000; ++i)
			if (flag[i])
				cout << i << endl;
	}
	return 0;
}