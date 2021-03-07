#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, n = "VWXYZABCDEFGHIJKLMNOPQRSTU";
	string::iterator p;
	while (getline(cin, a))
	{
		if (a == "ENDOFINPUT")
			break;
		getline(cin, a);
		for (p = a.begin(); p != a.end(); ++p)
			if (*p >= 'A'&&*p <= 'Z')
				*p = n[*p - 'A'];
		cout << a << endl;
		getline(cin, a);
	}
	return 0;
}