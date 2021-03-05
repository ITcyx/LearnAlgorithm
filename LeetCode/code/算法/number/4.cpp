class Solution
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int n = nums1.size() + nums2.size();
		auto p1 = nums1.begin();
		auto p2 = nums2.begin();
		int i = 0;
		if (n % 2)
		{
			n >>= 1;
			while (p1 != nums1.end() && p2 != nums2.end())
			{
				++i;
				if (i > n)
					return  *p1 < *p2 ? *p1 : *p2;
				if (*p1 < *p2)
					++p1;
				else
					++p2;
			}
			if (p1 != nums1.end())
				return *(p1 + (n - i));
			else
				return *(p2 + (n - i));
		}
		n >>= 1;
		int j;
		while (p1 != nums1.end() && p2 != nums2.end())
		{
			++i;
			if (i == n)
				j = *p1 < *p2 ? *p1 : *p2;
			else if (i > n)
				return *p1 < *p2 ? (*p1 + j) / 2.0 : (*p2 + j) / 2.0;
			if (*p1 < *p2)
				++p1;
			else
				++p2;
		}
		if (p1 != nums1.end())
		{
			if (i == n)
				return (*p1 + j) / 2.0;
			else
				return (*(p1 + (n - i - 1)) + *(p1 + (n - i))) / 2.0;
		}
		else
		{
			if (i == n)
				return (*p2 + j) / 2.0;
			else
				return (*(p2 + (n - i - 1)) + *(p2 + (n - i))) / 2.0;
		}
	}
};