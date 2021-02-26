#include <iostream>

using namespace std;

int main()
{
	int x;
	cin >> x;
	for (x = 0; x <= 12; x += 4)
		cout << x << " " << 25 - 7 * x / 4 << " " << 75 + 3 * x / 4 << endl;
	return 0;
}