class Solution
{
private:
	char roman[100];

public:
	string intToRoman(int& num)
	{
		char* p = roman;
		while (num >= 1000)
		{
			*p = 'M';
			++p;
			num -= 1000;
		}
		if (num >= 900)
		{
			*p = 'C';
			*(++p) = 'M';
			++p;
			num -= 900;
		}
		if (num >= 500)
		{
			*p = 'D';
			++p;
			num -= 500;
		}
		if (num >= 400)
		{
			*p = 'C';
			*(++p) = 'D';
			++p;
			num -= 400;
		}
		while (num >= 100)
		{
			*p = 'C';
			++p;
			num -= 100;
		}
		if (num >= 90)
		{
			*p = 'X';
			*(++p) = 'C';
			++p;
			num -= 90;
		}
		if (num >= 50)
		{
			*p = 'L';
			++p;
			num -= 50;
		}
		if (num >= 40)
		{
			*p = 'X';
			*(++p) = 'L';
			++p;
			num -= 40;
		}
		while (num >= 10)
		{
			*p = 'X';
			++p;
			num -= 10;
		}
		if (num == 9)
		{
			*p = 'I';
			*(++p) = 'X';
			++p;
			num -= 9;
		}
		if (num >= 5)
		{
			*p = 'V';
			++p;
			num -= 5;
		}
		if (num == 4)
		{
			*p = 'I';
			*(++p) = 'V';
			++p;
			num -= 4;
		}
		while (num)
		{
			*p = 'I';
			++p;
			num -= 1;
		}
		*p = '\0';
		return roman;
	}
};