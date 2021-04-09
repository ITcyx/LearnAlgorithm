class Solution
{
public:
	vector<int> missingTwo(vector<int>& nums)
	{
		vector<int> a(2);
		long long s = 0, p = 0, pc = 0;
		size_t i = 1;
		for (auto pn = nums.begin(); pn != nums.end(); ++pn)
		{
			s += *pn;
			p += *pn**pn;
			pc += i * i;
			++i;
		}
		pc += i * i;
		++i;
		pc += i * i;
		s = (nums.size() + 3)*(nums.size() + 2) / 2 - s;
		p = pc - p;
		long long b4ac = 2 * p - s * s, qi = 1, qj = b4ac, qm = (qi + qj) / 2;
		while (qm*qm != b4ac)
		{
			if (qm*qm > b4ac)
				qj = qm - 1;
			else
				qi = qm + 1;
			qm = (qi + qj) / 2;
		}
		a[0] = (s + qm) / 2;
		a[1] = (s - qm) / 2;
		return move(a);
	}
};