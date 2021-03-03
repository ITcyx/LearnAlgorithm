#include <iostream>
#include <string>

using namespace std;

bool check(string const& a, unsigned char* ip)
{
	int i = 0, c = 0;
	bool f = true, fm = false;
	auto p = a.begin();
	for (; p != a.end(); ++p)
	{
		if (*p == '.'&&f)
			return false;
		if (*p == '.')
		{
			if (c > 255)
				return false;
			ip[i] = c;
			++i;
			f = true;
			c = 0;
			continue;
		}
		if (*p == '~')
			if (f)
				return false;
			else
			{
				if (c > 255)
					return false;
				if (i == 4)
					return false;
				ip[i] = c;
				break;
			}
		c *= 10;
		c += *p - '0';
		f = false;
	}
	f = true;
	c = 0;
	i = 0;
	for (++p; p != a.end(); ++p)
	{
		if (*p == '.'&&f)
			return false;
		if (*p == '.')
		{
			if (c > 255)
				return false;
			if (c > 0 && ((c - 1) | c) != 255)
				return false;
			if (i == 0 && c == 0)
				return false;
			if (fm&&c != 0)
				return false;
			if (c < 255)
				fm = true;
			f = true;
			c = 0;
			++i;
			continue;
		}
		c *= 10;
		c += *p - '0';
		f = false;
	}
	if (f)
		return false;
	if (c > 255)
		return false;
	if (c > 0 && ((c - 1) | c) != 255)
		return false;
	if (fm&&c != 0)
		return false;
	if (c < 255)
		fm = true;
	if (!fm)
		return false;
	return true;
}

int main()
{
	int i, c[7];
	unsigned char ip[4];
	for (i = 0; i < 7; ++i)
		c[i] = 0;
	string a;
	while (cin >> a)
	{
		if (check(a, ip))
		{
			if (ip[0] >= 1 && ip[0] <= 126)
				++c[0];
			else if (ip[0] >= 128 && ip[0] <= 191)
				++c[1];
			else if (ip[0] >= 192 && ip[0] <= 223)
				++c[2];
			else if (ip[0] >= 224 && ip[0] <= 239)
				++c[3];
			else if (ip[0] >= 240 && ip[0] <= 255)
				++c[4];
			if (ip[0] == 10 || (ip[0] == 172 && ip[1] >= 16 && ip[1] <= 31) || (ip[0] == 192 && ip[1] == 168))
				++c[6];
		}
		else
			++c[5];
	}
	for (i = 0; i < 6; ++i)
		cout << c[i] << " ";
	cout << c[i] << endl;
	return 0;
}