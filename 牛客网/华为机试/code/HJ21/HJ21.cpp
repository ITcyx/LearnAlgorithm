#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	int i;
	char f1[] = "22233344455566677778889999";
	char f2[] = "bcdefghijklmnopqrstuvwxyza";
	while (cin >> a)
	{
		for (i = 0; i < a.length(); ++i)
		{
			if (a[i] >= 'a'&&a[i] <= 'z')
				a[i] = f1[a[i] - 'a'];
			else if (a[i] >= 'A'&&a[i] <= 'Z')
				a[i] = f2[a[i] - 'A'];
		}
		cout << a << endl;
	}
	return 0;
}