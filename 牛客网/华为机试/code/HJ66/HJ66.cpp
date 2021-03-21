#include <iostream>
#include <string>

using namespace std;

bool mate_str(string const& op, string const& str)
{
	string::const_iterator str_p = str.begin(), op_p = op.begin();
	while (op_p != op.end() && str_p != str.end())
	{
		if (*str_p == *op_p)
		{
			++op_p;
			++str_p;
		}
		else
			return false;
	}
	if (op_p == op.end())
		return true;
	return false;
}

size_t splite(string& a, string& op1, string& op2)
{
	string::iterator p;
	for (p = a.begin(); p != a.end(); ++p)
		if (*p != ' ')
			break;
	if (p == a.end())
		return 3;
	char b[15];
	size_t i = 1;
	b[0] = *p;
	for (++p; p != a.end(); ++p)
	{
		if (*p == ' ' || i > 14)
			break;
		b[i] = *p;
		++i;
	}
	if (i > 14)
		return 3;
	b[i] = '\0';
	op1 = b;
	for (; p != a.end(); ++p)
		if (*p != ' ')
			break;
	if (p == a.end())
		return 1;
	b[0] = *p;
	i = 1;
	for (++p; p != a.end(); ++p)
	{
		if (*p == ' ' || i > 14)
			break;
		b[i] = *p;
		++i;
	}
	if (i > 14)
		return 3;
	b[i] = '\0';
	op2 = b;
	for (; p != a.end(); ++p)
		if (*p != ' ')
			break;
	if (p == a.end())
		return 2;
	return 3;
}

size_t mate(string& a)
{
	static string const str[7] = { "reset","board","add","delete","reboot","backplane","abort" };
	string op1, op2;
	size_t i = splite(a, op1, op2);
	if (i == 3)
		return 6;
	if (i == 1)
	{
		if (mate_str(op1, str[0]))
			return 0;
		return 6;
	}
	string::iterator op1_p = op1.begin(), op2_p = op2.begin();
	if (*op1_p == 'r')
	{
		if (mate_str(op1, str[0]))
		{
			if (mate_str(op2, str[1]))
				return 1;
			return 7;
		}
		if (mate_str(op1, str[4]) && mate_str(op2, str[5]))
			return 4;
		return 6;
	}
	if (*op1_p == 'b')
	{
		if (mate_str(op1, str[1]))
		{
			if (mate_str(op2, str[2]))
				return 2;
			if (mate_str(op2, str[3]))
				return 3;
			return 6;
		}
		if (mate_str(op1, str[5]) && mate_str(op2, str[6]))
			return 5;
		return 6;
	}
	return 6;
}

int main()
{
	string a;
	string const b[7] = { "reset what","board fault","where to add","no board at all","impossible","install first","unknown command" };
	while (getline(cin, a))
		cout << b[mate(a)] << endl;
	return 0;
}