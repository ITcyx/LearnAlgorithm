class Solution
{
public:
	void setZeroes(vector<vector<int>>& matrix)
	{
		if (matrix.size() == 0)
			return;
		size_t i, j;
		vector<size_t> buffer;
		size_t const row = matrix.size(), col = matrix[0].size();
		for (i = 0; i < row; ++i)
			for (j = 0; j < col; ++j)
				if (matrix[i][j] == 0)
				{
					buffer.push_back(i);
					buffer.push_back(j);
				}
		for (auto p = buffer.begin(); p != buffer.end(); ++p)
		{
			for (j = 0; j < col; ++j)
				matrix[*p][j] = 0;
			++p;
			for (i = 0; i < row; ++i)
				matrix[i][*p] = 0;
		}
	}
};