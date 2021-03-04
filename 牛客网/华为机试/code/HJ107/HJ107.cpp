#include <iostream>

using namespace std;

inline double&& cubic(double const& a)
{
	return move(a*a*a);
}

int main()
{
	double a, c;
	int im, in = 0, ic;
	double dn[11] = { 0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,0 };
	cin >> a;
	if (a < 0)
	{
		cout << '-';
		a = -a;
	}
	if (a == 0 || a == 1)
	{
		cout << a << ".0" << endl;
		return 0;
	}
	im = a;
	while (im - in > 1)
	{
		ic = (im + in) / 2.0;
		c = ic * ic*ic;
		if (c > a)
			im = ic;
		else
			in = ic;
	}
	dn[10] = im * im*im;
	for (ic = 9; ic > -1; --ic)
	{
		c = in + dn[ic];
		dn[ic] = c * c*c;
		if (dn[ic] <= a)
		{
			if (dn[ic + 1] - a < a - dn[ic])
				++ic;
			break;
		}
	}
	if (ic == 10)
		cout << im << ".0" << endl;
	else
		cout << in << '.' << ic << endl;
	return 0;
}