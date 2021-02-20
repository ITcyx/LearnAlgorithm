#include <iostream>

using namespace std;

int main()
{
	int n, i = 0, j = 0;
	double c = 0;
	while (cin >> n)
	{
		if (n < 0)
			++i;
		else
		{
			++j;
			c += n;
		}
	}
	printf("%d\n", i);
	if (j > 0)
		printf("%.1f", c / j);
	else
		printf("0.0");
	return 0;
}