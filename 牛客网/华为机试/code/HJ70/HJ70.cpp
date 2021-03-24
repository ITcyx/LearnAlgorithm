#include <iostream>
#include <string>

using namespace std;

int main()
{
	size_t n, t, i, c;
	size_t mh_x[50], mh_y[50];
	size_t buffer[100], buffer_s;
	string ma;
	string::iterator ma_p;
	while (cin >> n)
	{
		for (i = 0; i < n; ++i)
			cin >> mh_x[i] >> mh_y[i];
		cin >> ma;
		t = 0;
		buffer_s = 0;
		c = 0;
		for (ma_p = ma.begin(); ma_p != ma.end(); ++ma_p)
		{
			if (*ma_p == '(')
				continue;
			if (*ma_p == ')')
			{
				if (buffer_s == 2)
					continue;
				c += buffer[buffer_s - 4] * buffer[buffer_s - 1] * buffer[buffer_s - 3];
				buffer[buffer_s - 3] = buffer[buffer_s - 1];
				buffer_s -= 2;
				continue;
			}
			buffer[buffer_s] = mh_x[t];
			buffer[buffer_s + 1] = mh_y[t];
			buffer_s += 2;
			++t;
		}
		cout << c << endl;
	}
	return 0;
}