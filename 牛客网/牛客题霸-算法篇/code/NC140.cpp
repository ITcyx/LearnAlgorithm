class Solution
{
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 * 将给定数组排序
	 * @param arr int整型vector 待排序的数组
	 * @return int整型vector
	 */
	void qs(vector<int>& arr, vector<int>::iterator const& i, vector<int>::iterator const& j)
	{
		if (j - i <= 1)
			return;
		vector<int>::iterator p = i;
		int t;
		for (vector<int>::iterator s = i + 1; s != j; ++s)
			if (*s < *i)
			{
				++p;
				t = *p;
				*p = *s;
				*s = t;
			}
		t = *p;
		*p = *i;
		*i = t;
		qs(arr, i, p);
		qs(arr, p + 1, j);
	}

	vector<int> MySort(vector<int>& arr)
	{
		qs(arr, arr.begin(), arr.end());
		return move(arr);
	}
};