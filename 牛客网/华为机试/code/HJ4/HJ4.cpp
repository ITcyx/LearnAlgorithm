#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	int i, j, s;
	while (cin >> a)
	{
		s = a.length();
		for (i = 0; i < s; i += 8)
		{
			for (j = 0; j < 8; ++j)
				if (i + j < s)
					cout << a[i + j];
				else
					cout << '0';
			cout << endl;
		}
	}
	return 0;
}