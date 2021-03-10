#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a[1000], c;
	char b[25], p;
	int i = -1, bi = -1;
	getline(cin, c);
	for (auto p = c.begin(); p != c.end(); ++p)
	{
		if ((*p >= 'a'&&*p <= 'z') || (*p >= 'A'&&*p <= 'Z'))
			b[++bi] = *p;
		else if (bi > -1)
		{
			b[++bi] = '\0';
			a[++i] = b;
			bi = -1;
		}
	}
	if (bi > -1)
	{
		b[++bi] = '\0';
		a[++i] = b;
		bi = -1;
	}
	++i;
	while (i > 1)
		cout << a[--i] << " ";
	cout << a[--i] << endl;
	return 0;
}