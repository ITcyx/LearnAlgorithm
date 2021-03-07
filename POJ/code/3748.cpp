#include <iostream>

using namespace std;

int main()
{
	unsigned int r, x, y;
	char p;
	cin >> hex >> r >> p >> dec >> x >> p >> y;
	cout << hex << (r&~(1 << x)&~(2 << (y - 3)) | (12 << (y - 3))) << endl;
	return 0;
}