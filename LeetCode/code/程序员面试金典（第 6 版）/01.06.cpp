class Solution
{
private:
	char char_string[500000];

public:
	string compressString(string& S)
	{
		if (S.length() == 0)
			return "";
		string::const_iterator p = S.begin();
		char num_stack[20], c_S = *p;
		char *char_string_p = char_string, *num_stack_p;
		int count = 1;
		for (++p; p != S.end(); ++p)
		{
			if (*p != c_S)
			{
				*char_string_p = c_S;
				for (num_stack_p = num_stack; count; ++num_stack_p)
				{
					*num_stack_p = count % 10 + '0';
					count /= 10;
				}
				for (--num_stack_p; num_stack_p != num_stack; --num_stack_p)
					*(++char_string_p) = *num_stack_p;
				*(++char_string_p) = *num_stack_p;
				++char_string_p;
				c_S = *p;
				count = 1;
			}
			else
				++count;
		}
		*char_string_p = c_S;
		for (num_stack_p = num_stack; count; ++num_stack_p)
		{
			*num_stack_p = count % 10 + '0';
			count /= 10;
		}
		for (--num_stack_p; num_stack_p != num_stack; --num_stack_p)
			*(++char_string_p) = *num_stack_p;
		*(++char_string_p) = *num_stack_p;
		*(++char_string_p) = '\0';
		return char_string_p - char_string < S.length() ? char_string : move(S);
	}
};