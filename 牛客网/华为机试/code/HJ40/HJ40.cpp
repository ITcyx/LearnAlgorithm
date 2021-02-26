#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	int i, n;
	int p[4];
	while (getline(cin, a))
	{
		n = a.length();
		for (i = 0; i < 4; ++i)
			p[i] = 0;
		for (i = 0; i < n; ++i)
		{
			if ((a[i] >= 'A'&&a[i] <= 'Z') || (a[i] >= 'a'&&a[i] <= 'z'))
				++p[0];
			else if (a[i] == ' ')
				++p[1];
			else if (a[i] >= '0'&&a[i] <= '9')
				++p[2];
			else
				++p[3];
		}
		for (i = 0; i < 4; ++i)
			cout << p[i] << endl;
	}
	return 0;
}