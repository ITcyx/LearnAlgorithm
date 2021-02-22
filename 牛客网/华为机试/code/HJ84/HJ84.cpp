#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	int i, c;
	while (getline(cin, a))
	{
		c = 0;
		for (i = 0; i < a.length(); ++i)
			if (a[i] >= 'A'&&a[i] <= 'Z')
				++c;
		cout << c << endl;
	}
	return 0;
}