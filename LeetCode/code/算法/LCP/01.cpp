class Solution
{
public:
	int game(vector<int>& guess, vector<int>& answer)
	{
		int c = 0;
		auto p1 = guess.begin();
		auto p2 = answer.begin();
		while (p1 != guess.end())
		{
			if (*p1 == *p2)
				++c;
			++p1;
			++p2;
		}
		return c;
	}
};