#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a, i, j;
	unsigned int ip[3];
	char p;
	bool flag;
	while (cin >> a)
	{
		flag = true;
		if (a > 255 || a < 0)
			a = 1;
		ip[0] = (unsigned char)(a);
		for (i = 0; i < 3; ++i)
		{
			cin >> p;
			cin >> a;
			if (a > 255 || a < 0)
				a = 1;
			ip[0] <<= 8;
			ip[0] += (unsigned char)(a);
		}
		if (ip[0] == (unsigned int)(0xFFFFFFFF) || ip[0] == 0 || (ip[0] | (ip[0] - 1)) != (unsigned int)(0xFFFFFFFF))
			flag = false;
		for (j = 1; j < 3; ++j)
		{
			cin >> a;
			if (a > 255 || a < 0)
				flag = false;
			ip[j] = (unsigned char)(a);
			for (i = 0; i < 3; ++i)
			{
				cin >> p;
				cin >> a;
				if (a > 255 || a < 0)
					flag = false;
				ip[j] <<= 8;
				ip[j] += (unsigned char)(a);
			}
		}
		if (!flag)
			cout << 1 << endl;
		else if ((ip[0] & ip[1]) == (ip[0] & ip[2]))
			cout << 0 << endl;
		else
			cout << 2 << endl;
	}
	return 0;
}