#include <iostream>
#include <string>

using namespace std;

int score(string const& a)
{
	bool f[6] = {};
	int n = 0;
	for (int i = 0; i < a.length(); ++i)
	{
		if (a[i] >= 'A'&&a[i] <= 'Z')
			f[0] = true;
		else if (a[i] >= 'a'&&a[i] <= 'z')
			f[1] = true;
		else if (a[i] >= '0'&&a[i] <= '9'&&f[2])
			f[3] = true;
		else if (a[i] >= '0'&&a[i] <= '9')
			f[2] = true;
		else if (f[4])
			f[5] = true;
		else
			f[4] = true;
	}
	if (f[0] && f[1])
		n += 20;
	else if (f[0] || f[1])
		n += 10;
	if (f[3])
		n += 20;
	else if (f[2])
		n += 10;
	if (f[5])
		n += 25;
	else if (f[4])
		n += 10;
	if (f[0] && f[1] && f[2] && f[4])
		n += 5;
	else if ((f[0] || f[1]) && f[2] && f[4])
		n += 3;
	else if ((f[0] || f[1]) && f[2])
		n += 2;
	if (a.length() <= 4)
		n += 5;
	else if (a.length() <= 7)
		n += 10;
	else
		n += 25;
	return n;
}

int main()
{
	string a;
	int n;
	while (cin >> a)
	{
		n = score(a);
		if (n >= 90)
			cout << "VERY_SECURE" << endl;
		else if (n >= 80)
			cout << "SECURE" << endl;
		else if (n >= 70)
			cout << "VERY_STRONG" << endl;
		else if (n >= 60)
			cout << "STRONG" << endl;
		else if (n >= 50)
			cout << "AVERAGE" << endl;
		else if (n >= 25)
			cout << "WEAK" << endl;
		else
			cout << "VERY_WEAK" << endl;
	}
	return 0;
}