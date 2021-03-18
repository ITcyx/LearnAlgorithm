#include <iostream>
#include <string>

using namespace std;

int main()
{
	bool t1[128], t2[128];
	string a, b;
	size_t i;
	string::iterator p;
	while (cin >> a >> b)
	{
		for (i = 0; i < 128; ++i)
			t1[i] = t2[i] = false;
		for (p = a.begin(); p != a.end(); ++p)
			t1[*p] = true;
		for (p = b.begin(); p != b.end(); ++p)
			t2[*p] = true;
		for (i = 0; i < 128; ++i)
			if (t1[i])
				if (!t2[i])
				{
					cout << "false" << endl;
					break;
				}
		if (i == 128)
			cout << "true" << endl;
	}
	return 0;
}