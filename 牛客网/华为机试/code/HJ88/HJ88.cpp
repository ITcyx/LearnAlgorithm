#include <iostream>
#include <string>

using namespace std;

void print_card(string& a, string::iterator& p)
{
	if (p == a.begin())
	{
		for (; *p != '-'; ++p)
			cout << *p;
		cout << endl;
	}
	else
	{
		for (; p != a.end(); ++p)
			cout << *p;
		cout << endl;
	}
}

bool level_compare(string::iterator& a1_p, string::iterator& a2_p)
{
	size_t a1_v, a2_v;
	if (*a1_p >= '3'&&*a1_p <= '9')
		a1_v = *a1_p - '3';
	else if (*(a1_p + 1) == 'o')
		a1_v = 13;
	else if (*(a1_p + 1) == 'O')
		a1_v = 14;
	else
		switch (*a1_p)
		{
		case 'J':
			a1_v = 8;
			break;
		case 'Q':
			a1_v = 9;
			break;
		case 'K':
			a1_v = 10;
			break;
		case 'A':
			a1_v = 11;
			break;
		case '2':
			a1_v = 12;
			break;
		}
	if (*a2_p >= '3'&&*a2_p <= '9')
		a2_v = *a2_p - '3';
	else if (*(a2_p + 1) == 'o')
		a2_v = 13;
	else if (*(a2_p + 1) == 'O')
		a2_v = 14;
	else
		switch (*a2_p)
		{
		case 'J':
			a2_v = 8;
			break;
		case 'Q':
			a2_v = 9;
			break;
		case 'K':
			a2_v = 10;
			break;
		case 'A':
			a2_v = 11;
			break;
		case '2':
			a2_v = 12;
			break;
		}
	return a1_v > a2_v;
}

int main()
{
	string a;
	string::iterator a1_p, a2_p, t;
	size_t a1_f, a2_f;
	while (getline(cin, a))
	{
		a1_p = a.begin();
		a1_f = a2_f = 0;
		for (a2_p = a.begin(); *a2_p != '-'; ++a2_p)
		{
			if (*a1_p != '0'&&*a1_p != ' ')
				++a1_f;
			++a1_p;
		}
		for (++a1_p; a1_p != a.end(); ++a1_p)
			if (*a1_p != '0'&&*a1_p != ' ')
				++a2_f;
		if (a1_f == 10 || a2_f == 10)
		{
			cout << "joker JOKER" << endl;
			continue;
		}
		a1_p = a.begin();
		++a2_p;
		if (*(a1_p + 1) == 'o' || *(a1_p + 1) == 'O')
			a1_f = 1;
		if (*(a2_p + 1) == 'o' || *(a2_p + 1) == 'O')
			a2_f = 1;
		if (a1_f == a2_f)
			if (level_compare(a1_p, a2_p))
				print_card(a, a1_p);
			else
				print_card(a, a2_p);
		else if (a1_f == 4)
			print_card(a, a1_p);
		else if (a2_f == 4)
			print_card(a, a2_p);
		else
			cout << "ERROR" << endl;
	}
	return 0;
}