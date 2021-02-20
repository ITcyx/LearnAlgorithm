#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string a;
	vector<string> b;
	while (cin >> a)
		b.push_back(a);
	for (vector<string>::reverse_iterator i = b.rbegin(); i != b.rend(); ++i)
		cout << *i << " ";
	return 0;
}