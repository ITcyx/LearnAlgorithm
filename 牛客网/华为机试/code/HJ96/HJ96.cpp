#include <iostream>
#include <string>

using namespace std;

int main()
{
	char b[100];
	string a;
	int i, j;
	bool f;
	while (cin >> a)
	{
		j = 0;
		f = true;
		for (i = 0; i < a.length(); ++i)
		{
			if (a[i] >= '0'&&a[i] <= '9'&&f)
			{
				b[j] = '*';
				++j;
				b[j] = a[i];
				++j;
				f = false;
			}
			else if (a[i] >= '0'&&a[i] <= '9')
			{
				b[j] = a[i];
				++j;
			}
			else if (!f)
			{
				b[j] = '*';
				++j;
				b[j] = a[i];
				++j;
				f = true;
			}
			else
			{
				b[j] = a[i];
				++j;
			}
		}
		if (!f)
		{
			b[j] = '*';
			++j;
		}
		b[j] = '\0';
		cout << b << endl;
	}
	return 0;
}