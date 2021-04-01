class Solution
{
public:
	void rotate(vector<vector<int>>& matrix)
	{
		int t, i, j;
		int const size = matrix.size(), mid = matrix.size() / 2;
		for (i = 0; i < mid; ++i)
			for (j = i; j < size - 1 - i; ++j)
			{
				t = matrix[i][j];
				matrix[i][j] = matrix[size - 1 - j][i];
				matrix[size - 1 - j][i] = matrix[size - 1 - i][size - 1 - j];
				matrix[size - 1 - i][size - 1 - j] = matrix[j][size - 1 - i];
				matrix[j][size - 1 - i] = t;
			}
	}
};