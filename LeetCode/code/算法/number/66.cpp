class Solution
{
public:
	vector<int> plusOne(vector<int>& digits)
	{
		vector<int>::reverse_iterator p = digits.rbegin();
		int c = 1, t;
		for (; p != digits.rend(); ++p)
		{
			t = *p + c;
			*p = t % 10;
			c = t / 10;
			if (c == 0)
				break;
		}
		if (c == 1)
			digits.insert(digits.begin(), 1);
		return move(digits);
	}
};