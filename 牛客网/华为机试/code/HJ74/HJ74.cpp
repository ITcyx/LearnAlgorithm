#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	getline(cin, a);
	int n = 0, i, j;
	char bf[100][100];
	for (i = 0; i < a.length(); ++i)
	{
		if (a[i] == ' ')
			continue;
		j = 0;
		if (a[i] == '\"')
			for (++i; i < a.length(); ++i)
			{
				if (a[i] == '\"')
					break;
				bf[n][j] = a[i];
				++j;
			}
		else
			for (; i < a.length(); ++i)
			{
				if (a[i] == ' ')
					break;
				bf[n][j] = a[i];
				++j;
			}
		bf[n][j] = '\0';
		++n;
	}
	cout << n << endl;
	for (i = 0; i < n; ++i)
		cout << bf[i] << endl;
	return 0;
}