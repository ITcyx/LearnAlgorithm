#include <iostream>

using namespace std;

int main()
{
	int ip[4], i;
	char p;
	while (cin >> ip[0] >> p >> ip[1] >> p >> ip[2] >> p >> ip[3])
	{
		for (i = 0; i < 4; ++i)
			if (ip[i] > 255 || ip[i] < 0)
			{
				cout << "NO" << endl;
				break;
			}
		if (i == 4)
			cout << "YES" << endl;
	}
	return 0;
}