class Solution
{
private:
	bool hash_table[200001];

public:
	void quick_sort(vector<int>& nums, vector<int>::iterator const& i, vector<int>::iterator const& j)
	{
		if (j - i <= 1)
			return;
		vector<int>::iterator p = i;
		int t;
		for (vector<int>::iterator s = i + 1; s != j; ++s)
			if (*s < *i)
			{
				++p;
				t = *s;
				*s = *p;
				*p = t;
			}
		t = *i;
		*i = *p;
		*p = t;
		quick_sort(nums, i, p);
		quick_sort(nums, p + 1, j);
	}

	vector<vector<int>> threeSum(vector<int>& nums)
	{
		if (nums.size() < 3)
			return vector<vector<int>>();
		quick_sort(nums, nums.begin(), nums.end());
		int i, fi = -1000000, fj;
		for (i = 0; i < 200001; ++i)
			hash_table[i] = false;
		vector<vector<int>> a;
		vector<int>b(3);
		vector<int>::iterator pi, pj, pb;
		vector<int>::iterator const ci = nums.end() - 2, cj = nums.end() - 1;
		for (pi = nums.begin(); pi != nums.end(); ++pi)
			hash_table[*pi + 100000] = true;
		for (pi = nums.begin(); pi != ci; ++pi)
		{
			if (*pi == fi)
				continue;
			fi = *pi;
			fj = -1000000;
			for (pj = pi + 1; pj != cj; ++pj)
			{
				if (*pj == fj)
					continue;
				fj = *pj;
				if (*pi + *pj * 2 < 0)
				{
					i = 100000 - *pi - *pj;
					if (i > 200000 || i < 0)
						continue;
					if (hash_table[i])
					{
						pb = b.begin();
						*pb = *pi;
						*(++pb) = *pj;
						*(++pb) = i - 100000;
						a.push_back(b);
					}
				}
				else if (*pi + *pj * 2 == 0 && *(pj + 1) == *pj)
				{
					pb = b.begin();
					*pb = *pi;
					*(++pb) = *pj;
					*(++pb) = *pj;
					a.push_back(b);
				}
			}
		}
		return a;
	}
};