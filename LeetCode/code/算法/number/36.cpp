class Solution
{
public:
	bool isValidSudoku(vector<vector<char>>const& board)
	{
		unsigned short a;
		unsigned short const c = 1;
		unsigned char b[9][9], i, j, t, p, q;
		vector<vector<char>>::const_iterator p1;
		vector<char>::const_iterator p2;
		for (p1 = board.begin(); p1 != board.end(); ++p1)
			for (p2 = p1->begin(); p2 != p1->end(); ++p2)
				if (*p2 == '.')
					b[p1 - board.begin()][p2 - p1->begin()] = 0;
				else
					b[p1 - board.begin()][p2 - p1->begin()] = *p2 - '0';
		for (i = 0; i < 9; ++i)
		{
			a = 0;
			for (j = 0; j < 9; ++j)
			{
				t = b[i][j];
				if (t != 0)
				{
					if ((a >> t)&c)
						return false;
					a |= c << t;
				}
			}
		}
		for (j = 0; j < 9; ++j)
		{
			a = 0;
			for (i = 0; i < 9; ++i)
			{
				t = b[i][j];
				if (t != 0)
				{
					if ((a >> t)&c)
						return false;
					a |= c << t;
				}
			}
		}
		for (i = 0; i < 9; i += 3)
			for (j = 0; j < 9; j += 3)
			{
				a = 0;
				for (p = 0; p < 3; ++p)
					for (q = 0; q < 3; ++q)
					{
						t = b[i + p][j + q];
						if (t != 0)
						{
							if ((a >> t)&c)
								return false;
							a |= c << t;
						}
					}
			}
		return true;
	}
};