/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
	int guessNumber(int& n)
	{
		unsigned int i = 1, j = n, m;
		while (j > i)
		{
			m = (i + j) / 2;
			if (guess(m) == 1)
				i = m + 1;
			else
				j = m;
		}
		return j;
	}
};