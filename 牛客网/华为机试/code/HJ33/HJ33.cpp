#include <iostream>

using namespace std;

int main()
{
	unsigned int ip[4], a;
	int i;
	char p;
	while (cin >> ip[0] >> p >> ip[1] >> p >> ip[2] >> p >> ip[3])
	{
		for (i = 0; i < 4; ++i)
		{
			a <<= 8;
			a |= ip[i];
		}
		cout << a << endl;
		cin >> a;
		ip[0] = a >> 24;
		ip[1] = (a << 8 >> 24);
		ip[2] = (a << 16 >> 24);
		ip[3] = (a << 24 >> 24);
		cout << ip[0] << '.' << ip[1] << '.' << ip[2] << '.' << ip[3] << endl;
	}
	return 0;
}