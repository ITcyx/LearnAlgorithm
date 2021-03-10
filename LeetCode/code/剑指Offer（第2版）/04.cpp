class Solution
{
public:
	bool findNumberIn2DArray(vector<vector<int>> const& matrix, int const& target)
	{
		if (matrix.size() == 0)
			return false;
		int i = 0;
		int j = matrix[0].size() - 1;
		int t;
		while (i<matrix.size() && j>-1)
		{
			t = matrix[i][j];
			if (target == t)
				return true;
			else if (target < t)
				--j;
			else
				++i;
		}
		return false;
	}
};