class Solution
{
private:
	char string_char[1500000];

public:
	string replaceSpaces(string const& S, int const& length)
	{
		char* string_char_p = string_char;
		string::const_iterator S_p, S_q = S.begin() + length;
		for (S_p = S.begin(); S_p != S_q; ++S_p)
		{
			if (*S_p == ' ')
			{
				*string_char_p = '%';
				*(++string_char_p) = '2';
				*(++string_char_p) = '0';
				++string_char_p;
				continue;
			}
			*string_char_p = *S_p;
			++string_char_p;
		}
		*string_char_p = '\0';
		return string_char;
	}
};