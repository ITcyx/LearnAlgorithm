#include <iostream>
#include <string>

using namespace std;

int main()
{
	string password;
	string::iterator p;
	size_t bc, sc, nc, ec, i, j, c;
	bool tc[100][100];
	while (cin >> password)
	{
		if (password.length() < 9)
		{
			cout << "NG" << endl;
			continue;
		}
		bc = sc = nc = ec = 0;
		for (p = password.begin(); p != password.end(); ++p)
		{
			if (*p >= 'A'&&*p <= 'Z')
				bc = 1;
			else if (*p >= 'a'&&*p <= 'z')
				sc = 1;
			else if (*p >= '0'&&*p <= '9')
				nc = 1;
			else
				ec = 1;
			if (bc + sc + nc + ec > 2)
				break;
		}
		if (p == password.end())
		{
			cout << "NG" << endl;
			continue;
		}
		for (i = 0; i < password.length(); ++i)
			for (j = i + 1; j < password.length(); ++j)
				tc[i][j] = (password[i] == password[j]);
		c = password.length() - 2;
		for (i = 0; i < c; ++i)
		{
			for (j = i + 1; j < c; ++j)
				if (tc[i][j] && tc[i + 1][j + 1] && tc[i + 2][j + 2])
					break;
			if (j < c)
				break;
		}
		if (i < c || j < c)
		{
			cout << "NG" << endl;
			continue;
		}
		cout << "OK" << endl;
	}
	return 0;
}