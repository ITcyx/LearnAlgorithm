#include <iostream>
#include <string>

using namespace std;

struct error_log
{
	string name;
	int line;
	int count;
};

struct error_last_num
{
	bool flag;
	int errorid;
};

inline bool is_same_error(string const& n, int const& l, error_log const& e)
{
	return e.name == n && e.line == l;
}

inline bool is_same_error(error_log const& left, error_log const& right)
{
	return left.name == right.name&&left.line == left.line;
}

int hash_string(string const& fn)
{
	int i = 0, j = 0;
	for (auto p = fn.begin(); p != fn.end(); ++p)
	{
		++j;
		i += j * (*p);
	}
	return i;
}

int hash_add(bool hash_table[2000], error_log hash_error[2000], error_last_num lastnum[2000], string const& fn, int const& line_num, int const& last_number)
{
	int n = hash_string(fn);
	int nj = n % 2281, ni = n % 881;
	for (int i = 0; i < 2000; ++i)
	{
		n = (nj + i * ni) % 2000;
		if (!hash_table[n])
		{
			hash_table[n] = true;
			hash_error[n].name = fn;
			hash_error[n].line = line_num;
			hash_error[n].count = 1;
			lastnum[last_number].flag = true;
			lastnum[last_number].errorid = n;
			break;
		}
		else if (is_same_error(fn, line_num, hash_error[n]))
		{
			++hash_error[n].count;
			break;
		}
	}
	return n;
}

int main()
{
	bool hash_table[2000];
	error_log hash_error[2000];
	error_last_num lastnum[2000];
	int i, j, n, last_f = 0, last8_id[8], last8_f = 0;
	string a;
	string::reverse_iterator pa;
	char rb[16];
	char ab[17];
	for (i = 0; i < 2000; ++i)
	{
		hash_table[i] = false;
		lastnum[i].flag = false;
	}
	while (cin >> a)
	{
		cin >> n;
		i = 0;
		for (pa = a.rbegin(); pa != a.rend(); ++pa)
		{
			if (i > 15)
				break;
			if (*pa == '\\')
				break;
			rb[i] = *pa;
			++i;
		}
		for (j = 0; j < i; ++j)
			ab[j] = rb[i - j - 1];
		ab[i] = '\0';
		a = ab;
		hash_add(hash_table, hash_error, lastnum, a, n, last_f);
		++last_f;
	}
	
	while (last8_f<8 && last_f>0)
		if (lastnum[--last_f].flag)
		{
			last8_id[last8_f] = lastnum[last_f].errorid;
			++last8_f;
		}
	while (last8_f > 0)
	{
		--last8_f;
		cout << hash_error[last8_id[last8_f]].name << " " << hash_error[last8_id[last8_f]].line << " " << hash_error[last8_id[last8_f]].count << endl;
	}
	return 0;
}